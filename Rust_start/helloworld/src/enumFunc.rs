#[derive(Debug)]
enum Book2 {
    Papery { index: i32 },
    Elec { url: String },
}
//Rust 不支持switch分支，改用match语法
fn get_book() {
    let book = Book2::Papery { index: 2222 };
    match book {
        Book2::Papery { index } => {
            println!("papery {}", index);
        }
        Book2::Elec { url } => {
            println!("elec {}", url);
        }
    }
    let i = 0;
    if let 0 = i {
        println!("equal");
    }
    match i {
        0 => println!("zero"),
        _ => {}
    }
}
