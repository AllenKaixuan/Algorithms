#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
private:
class MyQueue {
public:
    deque<int> que;
    void pop(int value) {
        if(!que.empty() && value == que.front())
            que.pop_front();

    }
    void push(int value) {
        
        while(!que.empty() && que.back() < value)   //注意不为空的判断，从后面开始删除
        {
            que.pop_back();
        }
        que.push_back(value);
    }
    int front() {
        return que.front();
    }
};  

public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> result;
    MyQueue myque;
    for(int i = 0; i < k; i++)
        myque.push(nums[i]);
    result.push_back(myque.front());
    for(int i = k; i < nums.size(); i++)
    {
        myque.pop(nums[i-k]);   //pop和push的顺序也很重要
        myque.push(nums[i]);
        
        result.push_back(myque.front());

    }
    return result;
}


    
};

    


int main()
{
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    Solution S;
    vector<int> result = S.maxSlidingWindow(nums, k);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}