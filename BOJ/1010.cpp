#include <bits/stdc++.h>

using namespace std;

int dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 31; i++) {
        dp[1][i] = i;
        dp[i][i] = 1;
    }

    // 핵심 아이디어: N에서 M을 고르려 하지말고 M에서 N을 골라야함
    // M번째 사이트 선택 안함 + M번째 사이트 선택 함
    // M번째 선택 안하는 경우 = N가지고 M-1개 선택할 수 있는 경우
    // M번째 선택 하는 경우 = N-1가지고 M-1개 선택할 수 있는 경우 (1개는 무조건
    // M에 고정되기 때문)
    for (int i = 2; i < 31; i++) {
        for (int j = 2; j < 31; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[N][M] << "\n";
    }

    return 0;
}