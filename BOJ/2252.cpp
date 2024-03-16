#include <bits/stdc++.h>

using namespace std;

int N, M, cnt[32001], vst[32001];
vector<int> later[32001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int a, b;
    while (M--) {
        cin >> a >> b;
        cnt[b]++;
        later[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (vst[i])
            continue;

        if (cnt[i] == 0) {
            vst[i] = 1;
            cout << i << ' ';
            for (int j : later[i]) {
                cnt[j]--;
            }
            i = 0;
        }
    }

    return 0;
}