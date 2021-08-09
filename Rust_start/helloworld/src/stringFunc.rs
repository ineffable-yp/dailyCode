//x..y表示区间[x,y)
//rust中两种常见的字符串类型str和String
//前者便是字符串切片
struct Book {
    domain: String,
    name: String,
    age: i64,
}
fn slice(str: String) {
    //切片类型必须是引用类型，显示指定
    let s = &str[0..4];
    // .. 0-结束
    // ..y 0--y
    //切片引用的字符串禁止修改
    let s1 = "helloworld"; //s1的类型就是&str
    println!("一部分:{},{}", s, s1);

    let arr = [1, 3, 5, 7, 9];
    let arr_s = &arr[2..4];
    for i in arr_s.iter() {
        println!("{}", i);
    }
}
fn get_struct() {
    let book = Book {
        domain: String::from("xian"),
        name: String::from("hello"),
        age: 1980,
    };
    println!(
        "domain: {}\nname: {}\n age: {}",
        book.domain, book.name, book.age
    );
    struct Color(u8, u8, u8);
    let red = Color(255, 0, 0);
    println!("{},{},{}", red.0, red.1, red.2);
}
