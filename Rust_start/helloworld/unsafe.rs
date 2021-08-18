// unsafe Rust不会进行安全检查
// 1.解引用原生指针
// 2.调用unsafe的函数或方法
// 3.访问或修改可变的静态变量
// 4.实现unsafe的trait
// 5.读写联合体中的字段

union MyUnion {
    i: i32,
    f: f32,
}

fn main() {
    let my_union = MyUnion{i: 3};
    unsafe { 
        // 可能会访问到未定义的字段
        //unsafe代码块中的程序由开发者保证程序的安全性
        println!("{}", my_union.i);
    }
    let val:Option<u32> = Some(4);
    match val {
        Some(num) => println!("val is: {}", num),
        None => println!("val is None")
    }
}