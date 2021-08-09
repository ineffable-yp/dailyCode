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

fn circle_call() {
    let mut i: i64 = 1;
    while i < 10 {
        println!("i的值: {}", i);
        i += 1;
    }
    println!("EXIT");
    let a = [10, 20, 30];
    //a.iter代表a数组的迭代器
    for i in a.iter() {
        println!("值为:{}", i);
    }
    for i in 0..3 {
        println!("a[{0}]={1}", i, a[i]);
    }
    //loop 类似于while(true) 原生的无限循环
    let location = loop {
        if i == 10 {
            break i;
        }
        i += 1;
    };
    println!("{} 等于 10", location);
}
