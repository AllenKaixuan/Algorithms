#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1)
            return {{1}};
        int i = 0;
        int layer = 0;
        
        
        vector<vector<int>> result(n, vector<int>(n));
        while(i < n * n)
        {
            if(i == n * n - 1)
            {
                result[layer][layer] = i + 1;
                break;
            }
            int lenth =  n - 1 - layer;
            for(int j = layer; j < lenth; j++, i++)
                result[layer][j] = i + 1;
            for(int j = layer; j < lenth; j++, i++)    
                result[j][n - layer - 1] = i + 1;
            for(int j = layer; j < lenth; j++, i++)
                result[n - layer - 1][ n - j - 1] = i + 1;
            for(int j = layer; j < lenth; j++, i++)
                result[n - j - 1][layer] = i + 1;
               
            layer ++;
            
        }

        return result;
        
    }
};

int main()
{
    Solution s;
    int nums = 3;
    vector<vector<int>> result = s.generateMatrix(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << "";
            
        }
        cout << endl;
    }
    
    return 0;
}