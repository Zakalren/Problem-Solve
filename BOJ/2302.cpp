#include <bits/stdc++.h>

using namespace std;

int dp[40];
vector<int> f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    while (M--) {
        int tmp;
        cin >> tmp;
        f.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        if (i < 0 || i > N) continue;

        if (find(f.begin(), f.end(), i + 1) != f.end()) {
        } else {
            dp[i]++;
        }
    }

    return 0;
}