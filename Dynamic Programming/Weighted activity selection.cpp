/*
带权重的区间调度问题就不能简单的用贪心算法解决，无法得到
最优解，需要用动态规划构建解的最优解结构，递归算法容易产生
冗余重复运算，容易达到指数级别，因此采取保存中间结果的来减
少，用时直接查找；
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
    int start, finish, weight;
};
bool compare(Job s1, Job s2)
{
    return s1.finish < s2.finish;
}

int latestNonConflict(Job *arr, int i) // 找到无冲突的最大编号作为上一个最优值
{

    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i - 1].start)
            return j;
    }
    return -1;
}
int findMaxWeightRec(Job *arr, int n) // 给了n个任务
{
    if (n == 1)
        return arr[n - 1].weight;
    int inclWeight = arr[n - 1].weight;       // 当前任务的权重
    int previous = latestNonConflict(arr, n); // 上一个不与当前任务冲突的任务
    if (previous != -1)
        inclWeight += findMaxWeightRec(arr, previous + 1); // 本任务+上一个最佳序列
    int exclWeight = findMaxWeightRec(arr, n - 1);
    return max(inclWeight, exclWeight);
}

int findMaxWeight(Job *arr, int n)
{
    sort(arr, arr + n, compare);
    return findMaxWeightRec(arr, n);
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxWeight(arr, n);
}