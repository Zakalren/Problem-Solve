#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    while (T--) {
        int answer = 0;
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            answer += max(max(max(a, b), c), 0);
        }

        cout << answer << '\n';
    }

    return 0;
}