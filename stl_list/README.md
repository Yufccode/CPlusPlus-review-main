# 遗留问题
适配std::的算法还没有成功

# const迭代器怎么弄？
难道要复制一份代码`__list_iterator`的代码吗？
如果要复制一份，写一个`__const__list_iterator``,
那这个`__list_iterator`和`__const__list_iterator`唯一的区别就是，`op->`和`op*`的返回值不一样，其他都是一样的

库里面不是这样做的，stl通过实例化来区分

```cpp
typedef __list_iterator<T, T&, T*> iterator;
typedef __list_iterator<T, const T&, const T*> const_iterator;
```

就是这样实现的！（重要）
非常的巧妙！
```cpp
typedef __list_iterator<T, T &, T *> iterator;                   // 定义迭代器！
typedef __list_iterator<T, const T &, const T *> const_iterator; // 定义const迭代器
iterator begin() { return iterator(__head->__next); }            // 用__head->__next构造__list_node就是迭代器的begin
iterator end() { return iterator(__head); }                      // end就是head自己
const_iterator begin() const { return const_iterator(__head->__next); }
const_iterator end() const { return const_iterator(__head); }
```