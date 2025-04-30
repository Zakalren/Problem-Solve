#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;

    int N;
    cin >> N;

    for (int i = 1; i < N + 1; i++) {
        dq.push_back(i);
    }

    while (dq.size() > 1) {
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();

        dq.push_back(front);
    }

    cout << dq[0];

    return 0;
}