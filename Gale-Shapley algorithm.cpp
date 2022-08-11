/*
以婚姻稳定匹配为载体，男女个数一致；
stable match表示连接中没有任何两方更希望放弃原有连接，达成新的
连接；
G-S算法总是可以找到稳定匹配；
输入一个(2*N)*N的矩阵，列为男人（女人）个数，0~N-1行为男人喜好
列表，N~2*N-1为女人喜好列表；
*/
#include <iostream>
#include <string.h>
using namespace std;
#define N 4                                                   // 设置人数
bool wprefermtom1(int w, int m, int m1, int prefer[2 * N][N]) // w比m更喜欢m1
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return false;
        if (prefer[w][i] == m)
            return true;
    }
}

void stableMatch(int prefer[2 * N][N])
{
    int womenPartner[N];
    bool freeman[N];
    int freeCount = N;
    memset(womenPartner, -1, sizeof(womenPartner));
    memset(freeman, false, sizeof(freeman)); // 有匹配对象才为true
    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (freeman[m] == false) // 随机抽取未配对一个男人，为m赋值
                break;

        for (int i = 0; i < N && freeman[m] == false; i++)
        {

            int w = prefer[m][i];

            if (womenPartner[w - N] == -1)  // 注意索引，w为prefer中索引需要减N
            {
                womenPartner[w - N] = m;
                freeman[m] = true;
                freeCount--;
            }
            else
            {
                int m1 = womenPartner[w - N];
                if (wprefermtom1(w, m, m1, prefer))
                {
                    womenPartner[w - N] = m;
                    freeman[m1] = false;
                    freeman[m] = true;
                }
            }
        }
    }
    // Print the solution
    cout << "Woman Man" << endl;
    for (int i = 0; i < N; i++)
        cout << " " << i + N << "\t" << womenPartner[i] << endl;
}
int main()
{
    int prefer[2 * N][N] = {
        {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMatch(prefer);

    return 0;
}
