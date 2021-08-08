//类似于lambda表达式
fn add(a: i32, b: i32) -> i32 {
    let y = {
        let x = 3;
        x + 1 //表达式的值代表整个代码块的结果，函数体表达式
    };
    println!("y的值:{0}", y);
    return a + b;
}

fn func_call(a: &str) {
    println!("{0}", a);
}
