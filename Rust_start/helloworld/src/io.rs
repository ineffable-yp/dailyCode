use std::fs;
use std::fs::OpenOptions;
use std::io::prelude::*;
use std::io::stdin;
//一般用unwrap或expect处理可能的Result类型
//流方式读取
pub fn read_stream() -> std::io::Result<()> {
    let mut buffer = [0u8; 5];
    let mut file = fs::File::open("D:\\dailyCode\\BM.cpp").unwrap();
    file.read(&mut buffer).unwrap();
    println!("{:?}", buffer);
    file.read(&mut buffer).unwrap();
    //rust没有同其他语言的close 而是编译器在文件不使用时关闭
    println!("{:?}", buffer);
    //文件写入：流式写入 一次性写入
    let mut file = OpenOptions::new()
        .append(true)
        .open("D:\\dailyCode\\BM2.cpp")?;

    file.write(b" // APPEND WORD")?;
    Ok(())
}
//普通文件读取
pub fn showargs() {
    let s = String::from("tore中文");
    let a = s.chars().nth(2);
    println!("{:?}", a);
    let args = std::env::args();
    for arg in args {
        println!("{} ", arg);
    }
    let mut str1 = String::new(); //新建字符串
    stdin().read_line(&mut str1).expect("Failed to read a line");
    println!("input line:{}", str1);
    let text = fs::read_to_string("D:\\dailyCode\\BM.cpp").unwrap();
    // fs::read 读取二进制文件 缓冲区是一个u8类型数组
    println!("{}", text);
}
pub fn vec_process() {
    let mut vector = vec![1, 2, 3, 4]; //动态数组
    vector.push(5);
    println!("{}", vector.get(3).unwrap());
    for i in &vector {
        // 引用，否则租借会提前结束vector生命周期
        println!("{}", i);
    }
    println!(
        "{}",
        match vector.get(9) {
            //get 返回值 为Option<T>
            Some(v) => v.to_string(),
            None => "none".to_string(),
        }
    )
}
