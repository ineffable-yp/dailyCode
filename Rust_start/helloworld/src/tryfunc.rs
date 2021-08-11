use std::fs::File;
use std::io;
use std::io::Read;
#[derive(Debug)]
//编译器通过derive为一些trait提供基础的实现
//trait理解为面向对象中的接口，但接口只能定义方法不能实现方法
//而trait可以 即存在默认实现
//特性对象（实现此特性的对象）也可作为参数传递
struct Point<T1, T2> {
    x: T1,
    y: T2,
}

trait Print {
    //默认实现
    // fn print(&self) -> String {
    //     String::from("12306")
    // }
    //只提供接口
    fn print(&self) -> String;
}
impl Print for Point<i32, f64> {
    fn print(&self) -> String {
        //控制输出格
        format!("testTrait:{},{}", self.x, self.y)
    }
}
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
    let p = Point { x: 2, y: 3.4 };
    println!("{}", p.print());
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
// &i64 :普通引用
// &'a i64: 含有生命周期注释的引用
// &'a mut i64: 可变型
//函数返回值的声明周期与两个参数绑定
fn longer<'a>(s1: &'a str, s2: &'a str) -> &'a str {
    if s2.len() > s1.len() {
        s2
    } else {
        s1
    }
}
pub fn compare() {
    let r;
    {
        let s1 = "rust";
        let s2 = "ecmascript";
        r = longer(s1, s2);
        println!("{} is longer", r);
    }
}
