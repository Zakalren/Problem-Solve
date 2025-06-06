#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> N_string(N);
    vector<string> M_string(M);

    for (int i = 0; i < N; i++) {
        cin >> N_string[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> M_string[i];
    }

    set<string> set_N_string(N_string.begin(), N_string.end());

    int ans = 0;
    for (const string& str : M_string) {
        if (set_N_string.find(str) != set_N_string.end()) ans++;
    }

    cout << ans;

    return 0;
}