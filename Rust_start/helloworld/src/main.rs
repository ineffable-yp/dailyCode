include!("baseFunc.rs");
include!("advancedFunc.rs");
include!("stringFunc.rs");
include!("enumFunc.rs");
//include!("tryfunc.rs");
//模块方式的调用
mod tryfunc;
fn main() {
    //强类型转换 可变变量
    let mut a: u64 = 12;
    println!("Hello, world! {{}},{0}", add(3, 4));
    println!("test {0}", a);
    a = 456;
    println!("changed {0}", a);
    //重影就是指变量的名称可以被重新使用
    let x = 5;
    let x = x + 2;
    print!("x的值 {}\n", x);

    let s = "123";
    func_call(s);
    let s = s.len();
    println!("s的长度 {}", s);

    //元组
    let tup: (i32, f64, u8) = (500, 3.4, 1);
    let (x, y, z) = tup;
    println!("{0},{1},{2}", x, y, z);

    //数组
    let a0 = [1, 2, 3, 4];
    let c0: [i32; 5] = [2, 3, 4, 5, 6]; //长度为5的i32数组
    println!("a0[2]:{0}, c0[3]:{1}", a0[2], c0[3]);

    //rust条件分支
    if a0[3] < 5 {
        println!("a0[3]小于5");
    } else {
        //else分支不可少
        //不允许单独语句代替代码块
        println!("大于5");
    }
    let res = if a0[2] > 10 { 1 } else { -1 };
    println!("函数体表达式res: {0}", res);
    circle_call();
    allrights();

    let str = String::from("test slice");
    slice(str);

    get_struct();
    get_book();
    openfile(String::from("D:\\dailyCode\\c++11_init.cpp"));
    tryfunc::test_read();
    tryfunc::compare();
}
