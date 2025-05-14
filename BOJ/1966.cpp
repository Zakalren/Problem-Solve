#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> q;

        int N, M;
        cin >> N >> M;

        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;

            q.push({temp, i});
        }

        int count = 0;
        while (!q.empty()) {
            int priority = q.front().first;
            int num = q.front().second;
            q.pop();

            bool exists = false;
            queue<pair<int, int>> temp = q;
            while (!temp.empty()) {
                if (temp.front().first > priority) {
                    exists = true;
                    break;
                }

                temp.pop();
            }

            if (exists) {
                q.push({priority, num});
            } else {
                count++;
                if (num == M) {
                    cout << count << "\n";
                }
            }
        }
    }

    return 0;
}