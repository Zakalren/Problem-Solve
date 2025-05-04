#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int a, b, ans = 1;
        cin >> a >> b;

        for (int i = 0; i < b; i++) {
            ans = (ans * (a % 10)) % 10;
        }

        if (ans == 0) ans = 10;

        cout << ans << "\n";
    }

    return 0;
}