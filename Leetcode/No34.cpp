#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int RightBorder = -2;
    int LeftBorder = -2;
    vector<int> searchRange(vector<int> &nums, int target)
    {
        RightBorder = searchRightBorder(nums, target);
        LeftBorder = searchLeftBorder(nums, target);

        if (LeftBorder == -2 || RightBorder == -2)
            return {-1, -1};

        if (RightBorder - LeftBorder >= 0)
            return {LeftBorder, RightBorder};

        return {-1, -1};
    }

private:
    int searchRightBorder(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (target < nums[middle])
                right = middle - 1;
            else if (target >= nums[middle])
            {
                left = middle + 1;
                RightBorder = middle;
            }
        }
        return RightBorder;
    }

    int searchLeftBorder(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (target <= nums[middle])
            {
                right = middle - 1;
                LeftBorder = middle;
            }

            else if (target > nums[middle])
            {
                left = middle + 1;
            }
        }
        return LeftBorder;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    vector<int> result = s.searchRange(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}