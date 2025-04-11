#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned int answer = 0;
    int cables[10001];
    int K, N, maxLength;
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        cin >> cables[i];
        maxLength = max(maxLength, cables[i]);
    }

    // 1~INT_MAX
    unsigned int start = 1, mid, end = maxLength;
    while (start <= end) {
        mid = ((start + end) / 2);

        int counts = 0;
        for (int i = 0; i < K; i++) {
            counts += (cables[i] / mid);
        }

        if (counts >= N) {
            answer = max(answer, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}