#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int N;
    cin >> N;

    while (N--) {
        int a;
        cin >> a;
        if (a == 1) {
            cin >> a;
            s.push(a);
            continue;
        }

        if (a == 2) {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                int num = s.top();
                s.pop();
                cout << num << '\n';
            }
            continue;
        }

        if (a == 3) {
            cout << s.size() << '\n';
            continue;
        }

        if (a == 4) {
            if (s.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
            continue;
        }

        if (a == 5) {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
            }
            continue;
        }
    }

    return 0;
}