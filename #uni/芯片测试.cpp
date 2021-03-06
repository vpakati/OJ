// 芯片测试
// AC
/*
问题描述
有n（2≤n≤20）块芯⽚，有好有坏，已知好芯⽚⽐坏芯⽚多。
每个芯⽚都能⽤来测试其他芯⽚。
⽤好芯⽚测试其他芯⽚时，能正确给出被测试芯⽚是好还是坏。
⽽⽤坏芯⽚测试其他芯⽚时，会随机给出好或是坏的测试结果（即此结果与被测试芯⽚实际的好坏⽆关）。
给出所有芯⽚的测试结果，问哪些芯⽚是好芯⽚。

输⼊格式
输⼊数据第⼀⾏为⼀个整数n，表示芯⽚个数。
第⼆⾏到第n+1⾏为n*n的⼀张表，每⾏n个数据。表中的每个数据为0或1，在这n⾏中的第i⾏第j列（1≤i, j≤n）的数据表示⽤第i块芯⽚测试第j块芯⽚时得到的测试结果，1表示好，0表示坏，i=j时⼀律为1（并不表示该芯⽚对本身的测试结果。芯⽚不能对本身进⾏测试）。

输出格式
按从⼩到⼤的顺序输出所有好芯⽚的编号

样例输⼊
3
1 0 1
0 1 0
1 0 1

样例输出
1 3
*/
/*
分析：
"好芯片比坏芯片多"意味着超过半数的芯⽚是好的，即:好芯片的数量>n/2
考虑到n为整型，n/2的值会向下取整（即：n==3时，n/2==1）
如果n为偶数，好芯片的数量大于n/2这句话当然是成立的（例如：n==4时，n/2==2，而此时好芯片的数量至少为3，故好芯片的数量大于n/2成立）
如果n为奇数，好芯片的数量大于n/2这句话当然也是成立的（例如：n==3时，n/2==1，而此时好芯片的数量至少为2，故有好芯片的数量大于n/2成立），但更加精准的说法是：好芯片的数量大于n*1.0/2

假设第i号芯⽚是好芯⽚，用其他芯片来测试第i号芯片，令cnt=测试结果为1（1表示被测试芯片是好芯片）的测试数，则cnt>=n/2（注意这里是大于等于号，因为如果用来测试的芯片是好芯片，测试结果为必定1，cnt就加一，但题目规定不能用芯片自身去测试自身，假设当测试芯片是坏芯片时，测试结果为0，那么最终求得的cnt==好芯片的数量-1，因此:好芯片的数量>n/2,cnt>=n/2）

那么这里的cnt如何求呢？只要对testResult矩阵的第i列求和（注意：求和时应当忽略对角线上的元素）即可，如果这个和（也就是cnt的值）>=n/2，则第i号芯⽚是好芯⽚。同理，如果第i号芯片是坏芯⽚，则cnt<n/2
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int testResult[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> testResult[i][j];
        }
    }
    for (int i = 0; i < n; i++) // 考察第i个芯片是好芯片还是坏芯片
    {
        int cnt = 0;
        for (int j = 0; j < n; j++) // 对testResult矩阵的第i列求和
        {
            if (j != i) // 由于不能用自身测试自身，所以应当忽略对角线上的元素
                cnt += testResult[j][i];
        }
        if (cnt >= n / 2)
        {
            cout << i + 1 << " ";
        }
    }
    return 0;
}