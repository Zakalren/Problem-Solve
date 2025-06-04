#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    vector<int> durability(N * 2);
    vector<bool> has_robot(N * 2);

    for (int i = 0; i < N * 2; i++) {
        cin >> durability[i];
    }

    int ans = 0;
    while (1) {
        ans++;

        rotate(durability.rbegin(), durability.rbegin() + 1, durability.rend());
        rotate(has_robot.rbegin(), has_robot.rbegin() + 1, has_robot.rend());
        has_robot[N - 1] = false;

        for (int i = N - 2; i >= 0; i--) {
            if (has_robot[i] && !has_robot[i + 1] && durability[i + 1] > 0) {
                has_robot[i] = false;
                has_robot[i + 1] = true;
                durability[i + 1]--;
            }
        }
        has_robot[N - 1] = false;

        if (durability[0] > 0) {
            has_robot[0] = true;
            durability[0]--;
        }

        if (count(durability.begin(), durability.end(), 0) >= K) break;
    }

    cout << ans;

    return 0;
}