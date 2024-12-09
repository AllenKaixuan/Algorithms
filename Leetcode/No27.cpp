#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int find_idx = 0;
       int result_idx = 0;
       
       for(; find_idx < nums.size(); find_idx++)
       {
            if(val != nums[find_idx])
            {
                nums[result_idx++] = nums[find_idx];
                printf("result_idx: %d\n", result_idx);
            }
               
                
            
       } 
       return result_idx;
    
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 5;
    int result = s.removeElement(nums, target);
    
    cout << result << endl;
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}