#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        for(; i + k - 1 < s.size(); i= i + 2 * k)
        {
            int start = i;
            int end = i + k - 1;
            while(start < end)
            {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
        }
        int index = s.size() - 2 * k - 1;
        //if(i > s.size() - 2 * k - 1)   // size返回的类型为size_t可能会出错，返回 18446744073709551615 （64 位下的无符号最大值），下溢出
        if(i > index)
        {
            int start = i;
            int end = s.size() - 1;
            while(start < end)
            {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "abcdefg";
    int k = 8;
    string result = solution.reverseStr(s, k);
    cout << "Reversed string: " << result << endl;
    return 0;
}