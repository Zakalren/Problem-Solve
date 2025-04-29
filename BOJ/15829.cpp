#include <bits/stdc++.h>

#define MOD 1234567891

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;

    string line;
    cin >> line;

    long long ans = 0;
    long long power = 1;

    for (int i = 0; i < L; i++) {
        int offset = line[i] - 'a' + 1;
        ans = (ans + offset * power) % MOD;
        power = (power * 31) % MOD;
    }

    cout << ans % MOD;

    return 0;
}