use std::fs::File;
enum Book2 {
    Papery { index: i32 },
    Elec { url: String },
}
//Rust 不支持switch分支，改用match语法
fn get_book() {
    let book = Book2::Papery { index: 2222 };
    let book2 = Book2::Elec {
        url: String::from("hello"),
    };
    match book {
        Book2::Papery { index } => {
            println!("papery {}", index);
        }
        Book2::Elec { url } => {
            println!("elec {}", url);
        }
    }
    match book2 {
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
    //抛出panic
    //panic!("error occured");
}
//错误处理难点
fn openfile(filename: String) {
    let f = File::open(filename);
    match f {
        Ok(_file) => {
            println!("File opened successfully.");
        }
        Err(_err) => {
            println!("Failed to open the file.");
        }
    }
}
