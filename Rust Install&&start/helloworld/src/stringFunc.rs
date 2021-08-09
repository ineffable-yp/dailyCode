//x..y表示区间[x,y)
//rust中两种常见的字符串类型str和String
//前者便是字符串切片
fn slice(str: String) {
    //切片类型必须是引用类型，显示指定
    let s = &str[0..4];
    // .. 0-结束
    // ..y 0--y
    //切片引用的字符串禁止修改
    let s1 = "helloworld"; //s1的类型就是&str
    println!("一部分:{},{}", s, s1);
}
