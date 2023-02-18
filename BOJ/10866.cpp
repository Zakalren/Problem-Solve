#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N, temp;
deque<int> dq;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> str;

        if (str == "push_front") {
            cin >> temp;
            dq.push_front(temp);
        }

        else if (str == "push_back") {
            cin >> temp;
            dq.push_back(temp);
        }

        else if (str == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "size") {
            cout << dq.size() << '\n';
        }

        else if (str == "empty") {
            cout << dq.empty() << '\n';
        }

        else if (str == "front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            }
            else {
                cout << "-1\n";
            }
        }

        else if (str == "back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            }
            else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}