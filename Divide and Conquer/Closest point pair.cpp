/*
最邻近点对
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <climits>
#include<iomanip>
using namespace std;
struct coor
{
	float x;
	float y;
	coor() {};
	coor(float a, float b) {
		x = a;
		y = b;
	}
	
};

bool comp_x(coor a, coor b) {  //大的在前面,根据x来排序
	return a.x > b.x;
}
bool comp_y(coor a, coor b) {  //小的在前面，根据y来排序
	return a.y < b.y;
}
float dist(coor a, coor b) { 
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
float min(float x, float y)
{
	return (x < y) ? x : y;
}
//找到条带内最近的距离，若小于则更新
float stripCloset(vector<coor> strip, float d) {
	float min = d;
	sort(strip.begin(), strip.end(), comp_y);
	for (int i = 0; i < strip.size(); ++i)
		for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j)  //最多执行6次
				//(strip[j].y - strip[i].y) < min，不满足此条件时则退出循环，说明没有
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}
float closestUtil(vector<coor>P) {
	if (P.size()<2)
	{
		return INT_MAX;   //注意要设置递归t
	}
	
	int mid = P.size() / 2;
	coor midCoor = P[mid];
	
	vector<coor>::iterator second = P.begin()+mid;  
	
	
	vector<coor>Pl, Pr;
	Pl.assign( P.begin(), second);  //注意assign内部的迭代器应该为同一类型的，const_iterator与iterator是不同类型的
	Pr.assign(second, P.end());
	float PL = closestUtil(Pl);
	float PR = closestUtil(Pr);  //&P[mid]与P + mid，表示相同的意思
	
	float disL = min(PL,PR);
	vector<coor> strip;
	
	for (int  i = 0; i < P.size(); i++)
	{
		if (abs(P[i].x-midCoor.x)<disL)
		{
			strip.push_back( P[i]);
			
		}
	}
	return min(disL, stripCloset(strip,  disL));
}
float closest(vector<coor> P) {
	sort(P.begin(), P.end(), comp_x);  //首先根据x排序
	return closestUtil(P);
}
int main() {
	int n;
	cin >> n;
	vector<coor> P;
	coor temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.x >> temp.y;
		P.push_back(temp);
	}
	cout.setf(ios::fixed);
	cout << setprecision(2);
	cout << closest(P);
	
	return 0;
	

}