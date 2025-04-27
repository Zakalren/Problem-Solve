#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C, ans = 1;
    cin >> A >> B >> C;

    while (B > 0) {
        if (B % 2 == 1) {
            ans = ((A % C) * (ans % C)) % C;
        }

        A = ((A % C) * (A % C)) % C;
        B /= 2;
    }

    cout << ans;

    return 0;
}