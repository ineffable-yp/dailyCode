#include <iostream>
#include <iterator>

// normal
template <class T>
void testDemo(T t1, T t2)
{
}
// specical
template <>
void testDemo<int>(int t1, int t2)
{
}

template <typename IterT, typename DistD>
void advance(IterT &iter, DistD &d);

template <typename IterT>
struct iterator_traits
{
    typedef typename IterT::iterator_category iterator_category
};

template <typename IterT> // partial template specialization
struct iterator_traits<IterT *>
{
    typedef random_access_iterator_tag iterator_category;
};
