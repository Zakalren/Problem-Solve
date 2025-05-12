#include <bits/stdc++.h>

using namespace std;

int broken[10];

bool isValid(int num) {
    if (!num) return !broken[num];

    while (num) {
        if (broken[num % 10]) return false;

        num /= 10;
    }

    return true;
}

int getLength(int num) {
    if (!num) return 1;
    return log10(num) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int button;
    for (int i = 0; i < M; i++) {
        cin >> button;
        broken[button] = 1;
    }

    int digit = getLength(N);
    int ans = abs(N - 100);
    for (int i = 0; i <= 1000000; i++) {
        if (isValid(i)) {
            int count = abs(N - i) + getLength(i);
            ans = min(ans, count);
        }
    }

    cout << ans;

    return 0;
}