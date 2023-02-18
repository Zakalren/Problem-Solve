#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
stack<int> s;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> str;

        if (str == "push") {
            int temp;
            cin >> temp;
            s.push(temp);
        }

        else if (str == "pop") {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "size") {
            cout << s.size() << '\n';
        }

        else if (str == "empty") {
            cout << s.empty() << '\n';
        }

        else if (str == "top") {
            if (s.empty()) {
                cout << "-1\n";
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}