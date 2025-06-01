#include <bits/stdc++.h>

using namespace std;

using i128 = __int128_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 3;
    while (T--) {
        int N;
        cin >> N;
        i128 bigint = 0;

        long long input;
        for (int i = 0; i < N; i++) {
            cin >> input;
            bigint += input;
        }

        if (bigint > 0) {
            cout << "+\n";
        } else if (bigint == 0) {
            cout << "0\n";
        } else {
            cout << "-\n";
        }
    }

    return 0;
}