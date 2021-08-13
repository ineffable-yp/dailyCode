use std::error::Error;

// unsafe Rust不会进行安全检查
// 1.解引用原生指针
// 2.调用unsafe的函数或方法
// 3.访问或修改可变的静态变量
// 4.实现unsafe的trait
// 5.读写联合体中的字段

//自定义类型 Error,实现std::fmt::Debug的trait
#[derive(Debug)]
struct CustomError {
    err: ChildError,
}
//实现Display的trait，并实现fmt方法
impl std::fmt::Display for CustomError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "CustomError is here!")
    }
}
///实现Error的trait,因为有子Error:ChildError,需要覆盖source()方法,返回Some(err)
impl std::error::Error for CustomError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        Some(&self.err)
    }
}

///子类型 Error,实现std::fmt::Debug的trait
#[derive(Debug)]
struct ChildError;

///实现Display的trait，并实现fmt方法
impl std::fmt::Display for ChildError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "ChildError is here!")
    }
}

///实现Error的trait,因为没有子Error,不需要覆盖source()方法
impl std::error::Error for ChildError {}

///构建一个Result的结果，返回自定义的error:CustomError
fn get_super_error() -> Result<(), CustomError> {
    Err(CustomError { err: ChildError })
}

fn main() {
    match get_super_error() {
        Err(e) => {
            println!("Error: {}", e);
            println!("Caused by: {}", e.source().unwrap());
        }
        _ => println!("No error"),
    }
}