#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int shirts[6];
    int T, P;
    int ans = 0;

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> shirts[i];
    }
    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        ans += ceil((double)shirts[i] / T);
    }

    cout << ans << "\n";
    cout << N / P << " " << N % P;

    return 0;
}