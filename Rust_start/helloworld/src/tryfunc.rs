use std::fs::File;
use std::io;
use std::io::Read;

//错误传递学习资料
//https://mogeko.me/2019/044/
pub fn read_text_from_file(path: &str) -> Result<String, io::Error> {
    //? 只能用于返回Result的函数
    let file = File::open(path);
    let mut f = match file {
        Ok(s) => s,
        Err(e) => return Err(e), //直接返回
    };
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

pub fn test_read() {
    let str_file = read_text_from_file("D:\\dailyCode\\c++11_ini2t.cpp");
    match str_file {
        Ok(s) => println!("{}", s),
        Err(e) => match e.kind() {
            //异常分类,获取Err类型
            io::ErrorKind::NotFound => {
                println!("No such file");
            }
            _ => {
                println!("Cannot read the file");
            }
        },
    }
}
