/*
选择序列中最小的放在前面（最大的放在后面），维护两个子数组
1.已经排好序的
2.未排序的
时间复杂度为O(n^2),交换次数不会超过O(n),相较于bubblsort内
存写入操作减少；
一般的选择排序不是稳定排序，优化后可以（改为插入而非交换），
但是插入操作对于数组效率很低
*/
#include <iostream>
using namespace std;

int max(int *arr, int n)
{
    int maxElement = arr[0]; // 如果不需要记录最大值可与只用index
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
            index = i;
        }
    }
    return index;
}

void searchSort(int *arr, int n)
{
    for (int i = n - 1; i > 0; i--) // 记录已经排好序的序列
    {
        int maxIndex = max(arr, i + 1);
        if (i != maxIndex)  // 避免无意义的交换
            swap(arr[i], arr[maxIndex]); // 将待排序序列最大值与最后位置交换，注意索引
    }
}

void searchSortOptimized(int *arr, int n)
{
    bool sorted = false;
    for(int i = n;(i>1)&&!sorted;i--)
    {
        int pose = 0;
        sorted = true;
        for (int j = 0; j <i; j++)
        {
            if(arr[pose]<arr[j])  // 在寻找最大值时判断数组是否为顺序
                pose = j;
            else
            {
                sorted = false; //当数组为顺序时，该语句一次都不运行
                swap(arr[pose],arr[i-1]);
            }
        }
        
    }

}

int main()
{
    int a[5] = {3, 1, 2, 4, 6};
    //searchSort(a, 5);
    searchSortOptimized(a,5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}