#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int mod = 1000000000;

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    if (dp[n]) return dp[n];

    return dp[n] = (fibo(n - 1) + fibo(n - 2)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
    } else if (n < 0) {    // 입력이 음수인 경우
        if (n % 2 == 0) {  // 절대값이 짝수 -> 마이너스
            cout << -1;
        } else {  // 절대값이 홀수 -> 플러스
            cout << 1;
        }
    } else {  // 입력이 양수 -> 플러스
        cout << 1;
    }

    int res = fibo(abs(n)) % mod;
    cout << '\n' << res;

    return 0;
}