#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;

    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        if (n == 0) {
            if (pq.empty()) {
                cout << "0\n";
                continue;
            }

            int top = pq.top();
            pq.pop();

            cout << top << '\n';
        }

        else if (n > 0) {
            pq.push(n);
        }
    }

    return 0;
}