/*
冒泡排序是最简单的排序算法，通过交换相邻元素排序，但是不适用
于大型数据上，因为其最坏和平均时间复杂度都很高，为O(n^2),即
使数组已经是有序的，也会一直排序。因此可以当内循环没有交换时
停止程序。
交换次数最坏为n*(n-1)/2
*/
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++) // 外循环为选取bubble的次数，同时记录有几个已排好序
    {
        for (int j = n - 1; j > i; j--) // 内循环为bubble从后向前冒泡
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

void bubbleSortOptimized(int *arr, int n)
{
    bool swapped; // 判断是否交换
    for (int i = 0; i < n; i++)
    {
        swapped = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

// 递归版本,通过一次冒泡每次将最大的值放到最后，不断递归调用缩短排序范围
void bubbleSortRecursive(int *arr, int n)
{
    if (n == 1 || n == 0)
        return;
    else
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        bubbleSortRecursive(arr , n-1);
    }
}

int main()
{
    int a[5] = {3, 1, 2, 4, 6};
    // bubbleSort(a, 5);
    // bubbleSortOptimized(a, 5);
    bubbleSortRecursive(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}