#include <bits/stdc++.h>

using namespace std;

int W, H;
int height[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    cin >> H >> W;

    for (int i = 0; i < W; i++) {
        cin >> height[i];
    }

    for (int i = 1; i < W - 1; i++) {
        int left_top = 0, right_top = 0;

        for (int j = 0; j < i; j++) {
            left_top = max(left_top, height[j]);
        }

        for (int j = i + 1; j < W; j++) {
            right_top = max(right_top, height[j]);
        }

        int score = min(left_top, right_top) - height[i];
        if (score > 0) ans += score;
    }

    cout << ans;

    return 0;
}