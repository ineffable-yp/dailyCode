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
