// 2的次幂表示
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T235
/*
问题描述
任何一个正整数都可以用2进制表示，例如：137的2进制表示为10001001。
将这种2进制表示写成2的次幂的和的形式，令次幂高的排在前面，可得到如下表达式：137=2^7+2^3+2^0
现在约定幂次用括号来表示，即a^b表示为a(b) 此时，137可表示为：2(7)+2(3)+2(0)
进一步：
7=2^2+2+2^0 (2^1 用 2 表示)
3=2+2^0
所以最后137可表示为：
2(2(2)+2+2(0))+
2(2+2(0))+
2(0) 

又如：1315=2^10+2^8+2^5+2+1
所以1315最后可表示为 ： 
2(2(2+2(0))+2)+
2(2(2+2(0)))+
2(2(2)+2(0))+
2+
2(0)

输入格式
正整数(1<=n<=20000)
输出格式
符合约定的n的0，2表示(在表示中不能有空格) ——也就是说只能出现 2的0次方 和 2的2次方

样例输入
137
样例输出
2(2(2)+2+2(0))+2(2+2(0))+2(0)

样例输入
1315
样例输出
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

提示
用递归实现会比较简单，可以一边递归一边输出
*/

#include <iostream>
#include <cmath>
using namespace std;

void fun(int x)
{
    int index = (int)(log(x) / log(2));
    int remainingPart = x - pow(2, index);
    if (index == 0) // 如果index==0，则说明x为1（输入为正整数，remainingPart是两个整数之差，所以x只可能是整数），进而remainingPart为0,也就是说不再有剩余的部分需要用2的次幂来表示，所以输出“2(0)”后就可以退出fun函数了
    {
        cout << "2(0)";
        return;
    }
    else if (index == 1)
    {
        cout << "2";
        // 注意：index==1时，不能像index==0时那样cout后return
        // 例如：当x等于3时，log(3)/log(2)==1.58496，index==1，remainingPart==1（而非0），所以cout后不能直接return
    }
    else
    {
        cout << "2(";
        fun(index); // ★
        cout << ")";
    }
    if (remainingPart) // ★
    {
        cout << "+";
        fun(remainingPart);
    }
}

int main()
{
    int n;
    cin >> n;
    fun(n);
    return 0;
}