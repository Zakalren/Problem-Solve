#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        stack<char> stk;

        string line;
        cin >> line;

        int err = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(') {
                stk.push(line[i]);
            }

            else if (line[i] == ')') {
                if (stk.empty() || stk.top() != '(') {
                    err = 1;
                    break;
                } else {
                    stk.pop();
                }
            }
        }

        if (err || !stk.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}