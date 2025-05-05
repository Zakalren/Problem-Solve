#include <bits/stdc++.h>

using namespace std;

vector<int> nums, nums2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    nums.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) pq.push(nums[i]);

    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;

    return 0;
}