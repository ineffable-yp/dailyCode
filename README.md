
# dailyCode
c++11的特性例子
====
>OMPtest: c++ for 循环并行计算<br>
>ReverseLink: 单链表的基础操作<br>
>CircleCentor/Alpha-shape: Alpha shape离散点边缘提取<br>
>BM: boyer Mooer字符串匹配算法<br>
>sunday: 改进的BM算法<br>
>Async/Async2: std::future异步结果使用（线程同步）<br>
>threadSync: 线程间同步的常用方式mutex, 条件变量,自旋锁<br>
>HashMap : 基于链表的开链法构建基础哈希表<br>
>std-move: 右值引用移动，减少无效拷贝<br>
>Tree    : 二叉树 结构<br>
>c++Contructor: 默认构造函数<br>
>container:   c++11部分容器特性<br>
>regex    :   std::regex使用<br>
>null     :   nullptr NULL的区分<br>
>atomic   :   基于原子操作的互斥锁（无锁）<br>
>alignMem :   内存对齐<br>
>noexcept :   异常处理<br>

>memory_order_relaxed	无fencing作用，cpu和编译器可以重排指令<br>
>memory_order_consume	后面依赖此原子变量的访存指令勿重排至此条指令之前<br>
>memory_order_acquire	后面访存指令勿重排至此条指令之前<br>
>memory_order_release	前面的访存指令勿排到此条指令之后。当此条指令的结果被同步到其他核的cache中时，保证前面的指令也已经被同步。<br>
>memory_order_acq_rel	acquare + release<br>
>memory_order_seq_cst	acq_rel + 所有使用seq_cst的指令有严格的全序关系<br>
>EularPath: 构造图迭代器,解耦图搜索，连通性--> 欧拉路径输出
>## memLeak  : Dr. memory代码性能分析（内存泄漏，悬挂指针等）