#include <bits/stdc++.h>

using namespace std;

int nums[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];

        if (nums[i]) {
            s.push(nums[i]);
        } else {
            s.pop();
        }
    }

    int ans = 0;
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans;

    return 0;
}