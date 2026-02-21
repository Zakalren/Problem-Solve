#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, M;

ll temp_sum, ans;
ll remainders[1001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        temp_sum = (temp_sum + num) % M;
        remainders[temp_sum]++;
    }

    ans += remainders[0];
    for (int i = 0; i <= M; i++) {
        ans += remainders[i] * (remainders[i] - 1) / 2;
    }

    cout << ans << "\n";

    return 0;
}
