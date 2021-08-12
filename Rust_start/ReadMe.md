# Rust Install(windows)
国内镜像配置(windows)
====
>跳转至.Cargo目录创建config文件<br>
>       例如：C:\Users\yp\ .cargo\config <br>
>修改RustUP国内镜像<br>
>&emsp; 添加如下系统变量<br>
> &emsp;&emsp;CARGO_HOME C:\Users\yp\ .cargo<br>
> &emsp;&emsp; RUSTUP_HOME C:\Users\yp\ .rustup<br>
> &emsp;&emsp; RUSTUP_DIST_SERVER http://mirrors.ustc.edu.cn/rust-static<br>
> &emsp;&emsp;  RUSTUP_UPDATE_ROOT http://mirrors.ustc.edu.cn/rust-static/rustup<br>

> 系统变量PATH 中添加rust环境变量<br> 
> &emsp;&emsp; eg: C:\Users\yp\.cargo\bin<br>
> enumFunc : 枚举 match 及 异常错误处理<br>
> advanceFunc : 切片 管理权 生命周期<br>
> orgnizationFunc: 组织 包箱等<br>
> unittest : 简单的单元测试 框架模块等<br>
cargo
====
>rust包管理工具：创建，构建工程，运行等功能<br>
>!!!若编译报错，可删除./cargo/路径下config--或更新config写法<br>
>rustc 直接编译，可做部分算法测试 例:包外的并发所线程程序<br> 