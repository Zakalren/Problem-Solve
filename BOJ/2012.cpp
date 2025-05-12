#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long ans = 0;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        ans += abs(v[i] - (i + 1));
    }

    // 1 1 2 3 5

    cout << ans;

    return 0;
}