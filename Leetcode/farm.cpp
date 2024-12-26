#include<iostream>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;


int main()
{
    int m, n;
    
    cin>>n>>m;
    vector<int> sum_row;
    vector<int> sum_column;
    
    vector<vector<int>> block;
    for(int i = 0; i < n; i++)
    {
        vector<int>row;
        int sum = 0;
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            row.push_back(temp);
            sum += temp;
            
        }
        block.push_back(row);
        sum_row.push_back(sum);
        
    }
    
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += block[j][i];
            
        }
        sum_column.push_back(sum);
        
    }
    
    int result = INT_MAX;
    for(int i = 0; i < n - 1; i++)
    {

        int difference = abs(sum_row[n-1] - sum_row[i]);
        if(result > difference)
            result = difference;
    }
    
    for(int i = 0; i < m - 1; i++)
    {
        int difference = abs(sum_column[m-1] - sum_column[i]);
        if(result > difference)
            result = difference;
    }
    
    cout<< result;
    
    
    
    
}