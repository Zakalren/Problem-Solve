#include <bits/stdc++.h>

#define MAX (INT_MAX / 2)

using namespace std;

int dp[100001][5][5];

int needed_energy(int current, int target) {
    if (current == target) return 1;

    if (current == 0) return 2;

    if (abs(current - target) == 2) return 4;

    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;

    int n;
    while (cin >> n && n) {
        nums.push_back(n);
    }

    for (int i = 0; i <= nums.size(); i++) {
        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {
                dp[i][left][right] = MAX;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {
                if (dp[i][left][right] == MAX) continue;

                if (num != right) {
                    dp[i + 1][num][right] =
                        min(dp[i + 1][num][right],
                            dp[i][left][right] + needed_energy(left, num));
                }

                if (num != left) {
                    dp[i + 1][left][num] =
                        min(dp[i + 1][left][num],
                            dp[i][left][right] + needed_energy(right, num));
                }
            }
        }
    }

    int ans = MAX;
    for (int left = 0; left < 5; left++) {
        for (int right = 0; right < 5; right++) {
            ans = min(ans, dp[nums.size()][left][right]);
        }
    }

    cout << ans;

    return 0;
}