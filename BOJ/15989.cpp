#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    // 신박한 방법
    // 어차피 모든 정수는 1들의 합으로 표현 가능하니까 기본적으로 1로 다 초기화
    // 그 다음 2가 더해질수 있는 수에는 2를 더한 경우의 수 더하기
    // 3도 마찬가지로

    fill(dp, dp + 10001, 1);

    for (int i = 2; i <= 10000; i++) {
        dp[i] += dp[i - 2];
    }

    for (int i = 3; i <= 10000; i++) {
        dp[i] += dp[i - 3];
    }

    int num;
    for (int i = 0; i < T; i++) {
        cin >> num;
        cout << dp[num] << "\n";
    }

    return 0;
}