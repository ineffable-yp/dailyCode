use std::net::{TcpListener, TcpStream};
use std::io::{Read, Write};
use std::{thread, time};

include!("threadpool.rs");

fn handle_client(mut stream: TcpStream) {
    let mut buffer = [0; 512];
    stream.read(&mut buffer).unwrap();
    let get = b"GET / HTTP/1.1\r\n";
    let sleep=b"GET /sleep HTTP/1.1\r\n";
    let (status_line, filename) = if buffer.starts_with(get) {
        ("HTTP/1.1 200 OK\r\n\r\n", "<html><body>test get</body></html>")
    }else if buffer.starts_with(sleep){
        ("HTTP/1.1 200 OK\r\n\r\n", "<html><body>test sleep</body></html>")
    } 
    else {
        ("HTTP/1.1 404 NOT FOUND\r\n\r\n", "wrong")
    };

    let contents = filename;//fs::read_to_string(filename).unwrap();
    let response = format!("{}{}", status_line, contents);

    stream.write(response.as_bytes()).unwrap();
    stream.flush().unwrap();
    
    let ten_millis = time::Duration::from_millis(10000); 
    thread::sleep(ten_millis);				//睡眠一段时间，模拟处理时间很长
}

fn main() {
    println!("服务监听8080");
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    let pool = ThreadPool::new(4);
    for stream in listener.incoming().take(3) {
        let stream = stream.unwrap();
        pool.execute(|| {
            handle_client(stream);
        });
    }
    println!("Shutting down.");
}