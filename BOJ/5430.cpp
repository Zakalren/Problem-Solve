#include <bits/stdc++.h>

using namespace std;

int T, n;
bool err, rvs;
string p, tmp;
deque<string> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        err = false, rvs = false;
        dq.clear();
        cin >> p >> n >> tmp;
        for (auto a = tmp.begin(); a != tmp.end(); a++) {
            if (isdigit(*a)) {
                string num;
                while (isdigit(*a)) {
                    num += *(a++);
                }
                dq.push_back(num);
            }   
        }

        for (char &c : p) {
            if (c == 'R') {
                rvs = !rvs;
            }
            else if (c == 'D') {
                if (dq.empty()) {
                    err = true;
                    break;
                }

                else {
                    if (rvs) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (err) {
            cout << "error\n";
        }
        else {
            cout << '[';
            for (int i = 0; i < dq.size(); i++) {
                if (rvs) {
                    string str = dq[dq.size() - i - 1];
                    cout << str;
                    if (dq.size() - i - 1 != 0)
                        cout << ',';
                }
                else {
                    string str = dq[i];
                    cout << str;
                    if (i != dq.size()-1)
                        cout << ',';
                }
            }   
            cout << "]\n";
        }
    }

    return 0;
}

