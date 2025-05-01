#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main() {
    dp[1] = 1;
    dp[2] = 1;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 이전거에 0붙이던가, 2번째 이전거에 01 붙이던가
    // 1자리 이친수 = 1, 개수 1
    // 2자리 이친수 = 10, 개수 1
    // 3자리 이친수 = 100, 101, 개수 2
    // 4자리 이친수 = 1000, 1010, 1001, 개수 3
    // 5자리 이친수 = 10000, 10100, 10010, 10001, 10101 개수 5
    // 6자리 이친수 = 100000, 101000, 100100, 100010, 101010, 100001, 101001,
    // 100101 개수 8

    int N;
    cin >> N;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N];

    return 0;
}