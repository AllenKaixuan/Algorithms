#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int right = nums.size() - 1;
        int left = 0;
        int i = right;
        while(right >= left)
        {
            int pow_left = pow(nums[left], 2);
            int pow_right = pow(nums[right], 2);
            if(pow_left >= pow_right)
            {
                result[i--] = pow_left;
                left++;    
            }
            else
            {
                result[i--] = pow_right;
                right--;
            }
        }
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums ={-4,-1,0,3,10};
    
    vector<int>  result = s.sortedSquares(nums);
    
   
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}