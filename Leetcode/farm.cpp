#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int m, n;
    
    cin >> n >> m;
    
    vector<int> sum_row(n, 0);       // 存储每一行的累加和
    vector<int> sum_column(m, 0);   // 存储每一列的累加和
    vector<vector<int>> block(n, vector<int>(m));  // 存储矩阵元素
    
    // 输入矩阵并计算每一行和每一列的累加和
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> block[i][j];
            sum_row[i] += block[i][j];
            sum_column[j] += block[i][j];
        }
    }
    
    // 总面积（所有元素和）
    int sum_total = 0;
    for (int i = 0; i < n; i++) {
        sum_total += sum_row[i];
    }
    
    // 计算行分割的最小差值
    int result = INT_MAX;
    int partial_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        partial_sum += sum_row[i];
        int difference = abs(sum_total - 2 * partial_sum);
        result = min(result, difference);
    }
    
    // 计算列分割的最小差值
    partial_sum = 0;
    for (int i = 0; i < m - 1; i++) {
        partial_sum += sum_column[i];
        int difference = abs(sum_total - 2 * partial_sum);
        result = min(result, difference);
    }
    
    cout << result;
    return 0;
}
