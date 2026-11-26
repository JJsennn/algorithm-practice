//括号匹配自然想到先入后出的栈
//这题输出完善好的匹配序列时需要保持原有顺序，故在原字符串s的基础上判断是否匹配然后完善输出
//下标有意义故不用for范围遍历

#include <bits/stdc++.h>
using namespace std;
bool isMatch(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> st;
    vector<bool> paired(n, false);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '[') {
            st.push_back(i);
            continue;
        }
        if (!st.empty() && isMatch(s[st.back()], s[i])) {
            int leftPosition = st.back();
            st.pop_back();
            paired[leftPosition] = true;
            paired[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            cout << '(';
            if (!paired[i]) {
                cout << ')';
            }
        } else if (s[i] == '[') {
            cout << '[';
            if (!paired[i]) {
                cout << ']';
            }
        } else if (s[i] == ')') {
            if (!paired[i]) {
                cout << '(';
            }
            cout << ')';
        } else {
            if (!paired[i]) {
                cout << '[';
            }
            cout << ']';
        }
    }

    cout << '\n';
    return 0;
}