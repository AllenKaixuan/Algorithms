#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token : tokens) {
            if (is_operator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calculate(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }

private:
    bool is_operator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int calculate(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        throw invalid_argument("Invalid operator");
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution S;
    cout << S.evalRPN(tokens) << endl;  // Output: 9
    return 0;
}