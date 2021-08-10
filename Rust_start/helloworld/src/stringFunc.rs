//x..y表示区间[x,y)
//rust中两种常见的字符串类型str和String
//前者便是字符串切片
//String是类似于长度不确定的数据，需要在堆中存储
#[derive(Debug)]
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
//rust 虽不面向对象，但结构体的方法首参数必须是self
impl Book {
    fn get_name(&self) {
        println!("impl:{}", self.name);
    }
    //多参数
    //fn shrink_size(&self, book: &Book) {}
    //结构体关联函数,不依赖具体结构体实例
    // fn writebook(name: String, age: i64, domain: String) -> Book {
    //     Book { domain, name, age }
    // }
}
fn get_struct() {
    let book = Book {
        domain: String::from("xian"),
        name: String::from("hello"),
        age: 1980,
    };
    //头部导入调试库 {:?}输出整个占位符
    //属性较多 #占位符
    println!("{:#?}", book);
    book.get_name();
    struct Color(u8, u8, u8);
    let red = Color(255, 0, 0);
    println!("{},{},{}", red.0, red.1, red.2);
}
