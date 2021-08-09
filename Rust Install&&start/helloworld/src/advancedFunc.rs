//所有权:rust在编译阶段更有效的分析内存资源的有用性及实现内存管理
//rust编译器自动添加释放资源的步骤
//rust变量 数据交互（move,clone）
//基础数据不需要存储到堆中:整型,布尔,浮点,字符类型,包含以上的元组
fn allrights() {
    let s1 = String::from("yinpan"); //堆中存储(rust默认长度较大的数据存放在堆中)
                                     //let s2 = s1; //移动 s1 失效
    let s2 = s1.clone();
    println!("s2: {},s1: {}", s2, s1);
    ownership(s1); //s1 被移动 失效
    let s3 = get_ownership();
    println!("{}", s3 + "uuu");

    //可变引用不允许多重引用
    let s4 = &s2; //等价于c++的引用,共享一块内存
    println!("长度:{}", get_length(s4));
    //let s5 = &s1; //s5 无法继续租借s1(被移动)
    //let mut s5 =String::from("")
    //let s6 = &mut s5; //可修改租借的值
    let x = 10;
    base_type(x);
} //释放x,s已移动不考虑
fn ownership(str: String) {
    println!("{}", str);
}
fn base_type(x: i32) {
    println!("{}", x);
}
fn get_ownership() -> String {
    let str = String::from("hello");
    return str;
} // some_string 被当作返回值移动出函数
fn get_length(s: &String) -> usize {
    return s.len();
}
//未声明生命周期--待深入理解rust生命周期
// fn dangle() -> &String {
//     let s = String::from("hello");
//     &s
// }
