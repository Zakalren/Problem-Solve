#include <bits/stdc++.h>

using namespace std;

int N;
int m = INT_MAX, M = 0;

int nums[100000][3];

int dp_m[2][3];
int dp_M[2][3];

int dx[3] = {0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp_m[1][i] = INT_MAX;
        dp_m[0][i] = dp_M[0][i] = nums[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int prev_selection = j + dx[k];
                if (prev_selection > 2 || prev_selection < 0) continue;

                dp_m[1][j] =
                    min(dp_m[1][j], dp_m[0][prev_selection] + nums[i][j]);
                dp_M[1][j] =
                    max(dp_M[1][j], dp_M[0][prev_selection] + nums[i][j]);
            }
        }

        for (int j = 0; j < 3; j++) {
            dp_m[0][j] = dp_m[1][j];
            dp_M[0][j] = dp_M[1][j];

            dp_m[1][j] = INT_MAX;
            dp_M[1][j] = nums[i][j];
        }
    }

    cout << *max_element(dp_M[0], dp_M[0] + 3) << " "
         << *min_element(dp_m[0], dp_m[0] + 3);

    return 0;
}