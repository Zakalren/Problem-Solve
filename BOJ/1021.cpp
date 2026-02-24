#include <bits/stdc++.h>

using namespace std;

int N, M, ans;

deque<int> dq;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int idx = 0;
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == num) {
                idx = i;

                if (idx <= dq.size() / 2) {
                    while (dq.front() != num) {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        ans++;
                    }
                }
                else {
                    while (dq.front() != num) {
                        dq.push_front(dq.back());
                        dq.pop_back();
                        ans++;
                    }
                }

                dq.pop_front();
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
