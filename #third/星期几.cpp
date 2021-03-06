// 星期几
/*
1949年的国庆节（10月1日）是星期六。今年（2012）的国庆节是星期一。
那么，从建国到现在，有几次国庆节正好是星期日呢？只要答案，不限手段！
可以用windows日历，windows计算器，Excel公式，。。。。。当然，也可以编程！
不要求写出具体是哪些年，只要一个数目！

输出：9
*/
#include <stdio.h>

int days(int year) // 这个函数用来计算指定年份的天数
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("r %d %d\n", year, 366);
        return 366; // 闰年有366天
    }
    else
    {
        printf("p %d %d\n", year, 365);
        return 365;
    }
}

int main()
{
    int cnt = 0; // 用来存储答案，从建国到现在，有cnt次国庆节正好是星期日
    int w = 6;   // 用来存储某一年的国庆节是星期几。1949年的国庆节（10 月 1 日）是星期六，所以初始化为6
    for (int year = 1950; year <= 2012; year++)
    {
        w = (days(year) % 7 + w) % 7;
        if (w == 0)
        {
            cnt++;
        }
    }

    printf("%d", cnt);
}

// ​公历中的年分为​闰年和平年
// 平年 365天 二月份为28天
// 闰年 366天 二月份为29天

// 闰年分为 普通闰年 和 世纪闰年
// 普通闰年 年份值能被4整除但不能被100整除
// 世纪闰年 年份值能被400整除
// 用代码表示就是：(n%4==0 && n%100!=0) || n%400==0
// 置闰法则：四年一闰 百年不闰；四百年再闰