#include <iostream>
#include <stack>
#include <string>
using namespace std;


string removeDuplicates(string s) {
    if (s.empty()) return "";
    stack<char> st;
   
    for(int i = 0; i < s.size(); i++)
    {
        
        if(!st.empty() && s[i] == st.top())     // 必须先判断栈是否为空
            st.pop();
        else
            st.push(s[i]);
    }

    string result = "";
    while(!st.empty())
    {
        result.insert(0, 1, st.top());
        st.pop();
    }
    return result;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;  // 输出: "ca"
    return 0;
}