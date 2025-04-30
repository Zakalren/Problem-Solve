#include <bits/stdc++.h>

using namespace std;

char get_opposite(char c) {
    switch (c) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
        default:
            return '_';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        stack<char> stk;
        string line;
        getline(cin, line);

        if (line == ".") break;

        int err = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == '[') {
                stk.push(line[i]);
            } else if (line[i] == ')' || line[i] == ']') {
                if (stk.empty() || stk.top() != get_opposite(line[i])) {
                    err = 1;
                    break;
                } else {
                    stk.pop();
                }
            }
        }

        if (err || !stk.empty())
            cout << "no\n";
        else
            cout << "yes\n";
    }

    return 0;
}