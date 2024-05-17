# The First Day

## 1.title
In the first line ,use 

```c++
#include <bits/stdc++.h>
```
to include many head files. It includes 
```c++
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

```

## 2.memset()
The function can initialzie an array, like
```c++
char a[20];
memset(a, 'c', sizeof(a));
```
Then all elmements in a will be set as 'c'.

## 3.并查集
在计算机科学中，并查集是一种树型的数据结构，用于处理一些不交集（Disjoint Sets）的合并及查询问题。有一个联合-查找算法（union-find algorithm）定义了两个用于此数据结构的操作：

1. Find：确定元素属于哪一个子集。它可以被用来确定两个元素是否属于同一子集。
2. Union：将两个子集合并成同一个集合。

由于支持这两种操作，一个不相交集也常被称为联合-查找数据结构（union-find data structure）或合并-查找集合（merge-find set）。其他的重要方法，MakeSet，用于创建单元素集合。有了这些方法，许多经典的划分问题可以被解决。

```pascal
 function MakeSet(x)
     x.parent := x
     x.rank   := 0
 function Union(x, y)
     xRoot := Find(x)
     yRoot := Find(y)
     if xRoot == yRoot
         return

     // x和y不在同一个集合，合并它们。
     if xRoot.rank < yRoot.rank
         xRoot.parent := yRoot
     else if xRoot.rank > yRoot.rank
         yRoot.parent := xRoot
     else
         yRoot.parent := xRoot
         xRoot.rank := xRoot.rank + 1

 function Find(x)
     if x.parent != x
        x.parent := Find(x.parent)
     return x.parent
```

```c++
//Union， 未优化
void Union(int x,int y)
{
    fx = getfather(x);
    fy = getfather(y);
    if(fy!=fx)
       father[fx]=fy;
}

//判断连个节点是否为同一个根节点
bool same(int x,int y)
{
   return getfather(x)==getfather(y);
}

//优化后的查找根节点代码
int getfather(int v)
{
    if (father[v]==v)
      return v;
    else
    {
        father[v]=getfather(father[v]);//路径压缩
        return father[v];
     }
}

//初始化
memset(rank,0,sizeof(rank));
//rank是秩，规定一个节点为0,其余按judge计算

//Union的优化
void judge(int x ,int y)

{
     fx = getfather(x);
     fy = getfather(y);

     if (rank[fx]>rank[fy])
        father[fy] = fx;
     else
     {
        father[fx] = fy;
        if(rank[fx]==rank[fy])
           ++rank[fy]; //重要的是祖先的rank，所以只用修改祖先的rank就可以了，子节点的rank不用管
     }
}
```