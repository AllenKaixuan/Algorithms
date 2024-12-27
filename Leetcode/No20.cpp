#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return 0;
                else
                {
                    if(s[i] == ')' && st.top() == '(')
                        st.pop();
                    
                    else if(s[i] == ']' && st.top() == '[')
                        st.pop();
                   
                    else if(s[i] == '}' && st.top() == '{')
                        st.pop();
                   
                    else
                        return 0;
                    
                }
            }

        }
        return st.empty();
    }
};

int main()
{
    string s;
    cin >> s;
    Solution S;
    cout << S.isValid(s);
    return 0;
}