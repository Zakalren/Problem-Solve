#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq(N);

    for (int i = 0; i < N; i++) {
        cin >> dq[i];
    }
    sort(dq.begin(), dq.end());

    int exclude_count = round(N * 0.15L);
    for (int i = 0; i < exclude_count; i++) {
        dq.pop_back();
        dq.pop_front();
    }

    if (dq.empty())
        cout << 0;
    else
        cout << round((float)accumulate(dq.begin(), dq.end(), 0) / dq.size());

    return 0;
}