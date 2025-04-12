#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int last_in = 1;
    int N, n;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;

        while (!s.empty()) {
            int n = s.top();

            if (n == last_in) {
                s.pop();
                last_in++;
            } else {
                break;
            }
        }

        if (n == last_in) {
            last_in++;
        } else {
            s.push(n);
        }
    }

    while (!s.empty()) {
        int n = s.top();
        s.pop();

        if (n != last_in) {
            cout << "Sad";
            return 0;
        } else {
            last_in++;
        }
    }

    cout << "Nice";

    return 0;
}