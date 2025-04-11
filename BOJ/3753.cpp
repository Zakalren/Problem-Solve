#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    while (true) {
        cin >> N >> C;
        if (cin.eof()) break;

        if (N == 0) {
            cout << "0\n";
            continue;
        }

        double T = (double)C / (N * 2);
        int T_ceil = ceil(T);
        int T_floor = floor(T);

        if (T_ceil * (C - T_ceil * N) > T_floor * (C - T_floor * N)) {
            cout << T_ceil << '\n';
        } else {
            cout << T_floor << '\n';
        }
    }

    return 0;
}