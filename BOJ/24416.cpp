#include <bits/stdc++.h>

using namespace std;

int fibo_count = 0;
int fib_count = 0;
int dp[41];

void fibo(int n) {
    if (n == 1 || n == 2) {
        fibo_count++;
        return;
    }

    fibo(n - 1);
    fibo(n - 2);
}

void fib(int n) {
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    fibo(n);
    cout << fibo_count << " " << n - 2;

    return 0;
}