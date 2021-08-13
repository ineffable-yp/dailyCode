use std::thread;
use std::time::Duration;
use std::sync::mpsc;
//mpsc: 多生产者 单消费者 FIFO队列
//消息
fn message_pass(){
    let (tx,rx) = mpsc::channel();
    thread::spawn(move ||{
        let val = String::from("hi");
        //获取线程的发送者 tx 并发送数据
        tx.send(val).unwrap();
    });
    //unwrap 在确保程序不会异常或出错情况下，忽略-避免使用
    let receive = rx.recv().unwrap();
    println!("得到值:{}",receive);
}
fn main() {
    // 闭包 实现
    // |参数1, 参数2, ...| -> 返回值类型 {
    //     // 函数体
    // }
    let inc = |num:i32|->i32{
        num + 1
    };
    println!("闭包:{}",inc(5));
    let s = "测试闭包move 所有权";
    let handle = thread::spawn(move || {
        println!("{}",s);
        for i in 0..5 {
            println!("spawned thread print {}", i);
            thread::sleep(Duration::from_millis(1));
        }
    });
    //spawn 创建新进程
    //thread::spawn(spawn_function);
    for i in 0..3 {
        println!("main thread print {}", i);
        thread::sleep(Duration::from_millis(1));
    }
    //join等价于其他语言的线程资源交于主线程管理
    handle.join().unwrap();
    message_pass();
}
