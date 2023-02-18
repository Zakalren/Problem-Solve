#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
queue<int> q;
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
            q.push(temp);
        }

        else if (str == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "size") {
            cout << q.size() << '\n';
        }

        else if (str == "empty") {
            cout << q.empty() << '\n';
        }

        else if (str == "front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
            }
            else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}