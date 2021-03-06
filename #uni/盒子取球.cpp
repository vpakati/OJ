// 盒子取球
// 方法一
/*
今盒子里有n个小球，A、B 两人轮流从盒中取球，每个人都可以看到另一个人取了多少个，也可以看到盒中还剩下多少个，并且两人都很聪明，不会做出错误的判断。

我们约定：
每个人从盒子中取出的球的数目必须是：1，3，7或者8个。
轮到某一方取球时不能弃权！
A先取球，然后双方交替取球，直到取完。
被迫拿到最后一个球的一方为负方（输方）

请编程确定出在双方都不判断失误的情况下，对于特定的初始球数，A是否能赢？

程序运行时，从标准输入获得数据，其格式如下：
先是一个整数n(n<100)，表示接下来有n个整数。
然后是n个整数，每个占一行（整数<10000），表示初始球数。 

程序则输出n行，表示A的输赢情况（输为0，赢为 1）。

输入：
4 
1 2 10 8
输出：
0
1
1
1
*/
#include <stdio.h>
#include <string.h>
const int MAX_NUM_OF_BALL = 10000;
int main()
{
    int a[MAX_NUM_OF_BALL + 1];
    int operation[4] = {1, 3, 7, 8}; // 每个人从盒子中取出的球的数目必须是：1，3，7或者8个。
    memset(a, 0, sizeof(a));         // 初始化判定数组为0。memset函数在string.h头文件中
    a[0] = 1;                        // 如果盒子中球数为0，那么轮到A取球时，盒子中还剩0个球，即已经没球可供A取了，说明B取完了最后一堆球，所以A赢
    for (int i = 1; i <= MAX_NUM_OF_BALL; i++)
        for (int j = 0; j < 4; j++)
            if (i - operation[j] >= 0)
            {
                if (a[i - operation[j]] == 0) // 如果盒子中还剩i - operation[j]个球时A会输的话，那么盒子中的初始球数为i时A就会赢。因为盒子中的初始球数为i时，A可以取operate个，那么此时盒子中就剩下i - operation[j]个球，所以B输
                {
                    a[i] = 1; // 经验证，这是正确的写法
                    break;
                }
            }
    int numOfBall;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &numOfBall);
        printf("%d\n", a[numOfBall]); // 直接输出即可，不需要存储下来统一输出，PS:ACM里都是这样处理的。
    }
    return 0;
}

/*
分析：
当n==1的时候，A一定会输
当n==1+[1/3/7/8]的时候，A一定会赢，因为A可以取1/3/7/8个球，然后把最后那个球留给B
也就是说，如果当盒子中的球数为n时A必输，那么当盒子中的球数为n+[1/3/7/8]时，则A可以取[1/3/7/8]个球，迫使B输。
我们根据这条规律，把n的所有取值1-10000都标为 1（必胜）或 0（必输），然后输出对应的标记即可。
*/
// #include <stdio.h>
// #include <string.h>
// const int MAX_NUM_OF_BALL = 10000;
// void fun(int a[])
// {
//     int operation[4] = {1, 3, 7, 8};
//     for (int i = 1; i + 8 <= 10000; i++)
//     {
//         if (a[i] == 0) // 如果当盒子中的球数为i时A必输
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 a[i + operation[j]] = 1; // 那么当盒子中的球数为i + operation[j]时A必赢
//             }
//         }
//     }
// }
// int main()
// {
//     int a[MAX_NUM_OF_BALL + 1] = {0}; // 从下标为1的数组元素开始使用。a[1]==0，表明当盒子中的初始球数为1时A必输
//     fun(a);

//     int n, numOfBall;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &numOfBall);
//         printf("%d\n", a[numOfBall]);
//     }
//     return 0;
// }
