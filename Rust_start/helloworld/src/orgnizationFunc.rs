//Rust的路径分隔符::
//访问控制权限,默认是private
//pub 公开
mod nation {
    pub mod government {
        pub fn govern() {}
    }
    mod congress {
        pub fn legislate() {}
    }
    mod court {
        fn judicial() {
            super::congress::legislate();
        }
    }
}
//绝对路径crate 解决相对路径过长
use crate::nation::government::govern;
