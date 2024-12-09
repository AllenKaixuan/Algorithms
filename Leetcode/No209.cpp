#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int slide_length = 0;
        int slide_start = 0;
        int result = INT32_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            while(sum >= target)
            {
                
                
                slide_length = i - slide_start + 1;
                result = result < slide_length ? result : slide_length;
                sum -= nums[slide_start++];
                
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{
    Solution s;
    vector<int> nums ={5,1,3,5,10,7,4,9,2,8};
    int target = 15;
    int  result = s.minSubArrayLen(target, nums);
    
   
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << " ";
    // }
    cout << result << endl;
    return 0;
}