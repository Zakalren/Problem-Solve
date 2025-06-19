#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    while (cin >> N >> S) {
        cout << (S / (N + 1)) << "\n";
    }

    return 0;
}