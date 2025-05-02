#include <bits/stdc++.h>

using namespace std;

// 18:24

int ans = INT_MAX;
long long nums[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        nums[i] = nums[i - 1] + a;
    }

    int left = 0, right = 0;
    while (right <= N) {
        if (nums[right] - nums[left] >= S) {
            ans = min(ans, right - left);
            ++left;
        } else {
            ++right;
        }
    }

    if (ans == INT_MAX) ans = 0;

    cout << ans;

    return 0;
}