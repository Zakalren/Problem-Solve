#include <bits/stdc++.h>

using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;

    return n * factorial(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    cout << factorial(N);

    return 0;
}