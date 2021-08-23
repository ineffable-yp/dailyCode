use std::sync::mpsc;
use std::sync::Arc;
use std::sync::Mutex;

pub struct ThreadPool{
    workers:Vec<Worker>,//线程组
    sender:mpsc::Sender<Message>//多生产单消费消息模型  
}
//工作线程
struct Worker{
    id:usize,
    //强制检测空值
    thread:Option<thread::JoinHandle<()>>,
}

type Job = Box<dyn FnOnce() + Send + 'static>;

enum Message {
    NewJob(Job),
    Terminate,
}
//工作线程的new方法实现
impl Worker {
    fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Message>>>) ->
        Worker {
        let thread = thread::spawn(move ||{
            loop {
                //unwrap忽略错误处理 有值返回 无值直接panic
                let message = receiver.lock().unwrap().recv().unwrap();
                match message {
                    Message::NewJob(job) => {
                        println!("Worker {} got a job; executing.", id);
                        job();
                    },
                    Message::Terminate => {
                        println!("Worker {} was told to terminate.", id);
                        break;
                    },
                }
            }
        });
        //返回worker结构体
        Worker {
            id,
            thread: Some(thread),//有值 rust空异常编译器确定
        }
    }
}
//线程池创建 工作线程的初始化
impl ThreadPool{
    pub fn new (size:usize)->ThreadPool{
        assert!(size>0);
        let (sender,receiver) = mpsc::channel();
        let receiver = Arc::new(Mutex::new(receiver));//类似于智能指针 引用计数
        let mut workers = Vec::with_capacity(size);//预分配vector大小

        for id in 0..size{
            workers.push(Worker::new(id, Arc::clone(&receiver)));
        }
        //返回
        ThreadPool{
            workers,
            sender,
        }
    }
    pub fn execute<F>(&self,f:F)
        where 
            F:FnOnce()+Send+'static 
            {
                let job = Box::new(f);
                self.sender.send(Message::NewJob(job)).unwrap();
            }
}

impl Drop for ThreadPool {
    fn drop(&mut self) {
        println!("Sending terminate message to all workers.");

        for _ in &mut self.workers {
            self.sender.send(Message::Terminate).unwrap();
        }

        println!("Shutting down all workers.");

        for worker in &mut self.workers {
            println!("Shutting down worker {}", worker.id);

            if let Some(thread) = worker.thread.take() {
                thread.join().unwrap();
            }
        }
    }
}

