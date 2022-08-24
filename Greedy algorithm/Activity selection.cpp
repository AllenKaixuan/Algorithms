/*
区间调度问题，给定n个活动及其开始结束时间，如何安排可以在
一段区间内完成最多的任务：
贪心算法优先——结束时间最早排序
1.当使用STL中sort排序时时间复杂度为O(n*Logn)
2.当使用优先队列储存时，为O(n)，省去了排序
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Activity
{
    int start, finish;
};

bool activityCompare(Activity s1, Activity s2)
{
    return s1.finish < s2.finish;
}
void printMaxActivities(Activity arr[], int n)
{
    sort(arr, arr + n, activityCompare); // 根据结束时间排序
    int temp = 0;
    cout << "(" << arr[temp].start << ", " << arr[temp].finish << "), ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > arr[temp].finish)
        {
            temp = i;
            cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
        }
    }
}



void SelectActivities(vector<int> s, vector<int> f)
{
   
    vector<pair<int, int>> ans;

   

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    for (int i = 0; i < s.size(); i++)
    {
        p.push(make_pair(f[i], s[i]));  // 按照键值f[i]排序
    }

    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start, end));

    while (!p.empty())
    {
        auto itr = p.top();
        p.pop();
        if (itr.second >= end)
        {
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start, end));
        }
    }
    cout << "Following Activities should be selected. " << endl
         << endl;

    for (auto itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << "Activity started at: " << (*itr).first << " and ends at " << (*itr).second << endl;
    }
}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);

    
    cout << endl
         << "优先队列实现：";
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    SelectActivities(s, f);
    return 0;
}