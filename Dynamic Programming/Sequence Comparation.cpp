/*
序列比对问题，利用编辑距离作为罚分机制
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
static int k;

int dist(char a, char b) {		
		return abs(a - b);	
}
int solution(string p, string q) {

	int m = p.size();
	int n = q.size();
	int** a = new int* [m+1];
	for (int i = 0; i <= m; i++)
		a[i] = new int[n+1];
	
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
				a[i][j] = k * j;
			else if (j == 0)
				a[i][j] = k * i;
			
			else						
				a[i][j] = min(dist(p[i-1], q[j-1])+a[i-1][j-1], k+min(a[i - 1][j], a[i][j - 1]));         
            //注意此处string索引需要-1，因为第5个字符相等相当于stri[4]=strj[4]
		}
	}
	return int(a[m][n]);
}
int main() {
	string a, b;
	cin >> a >> b;
	cin >> k;
	cout << solution(a, b);
}