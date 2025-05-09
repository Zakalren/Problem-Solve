#include <bits/stdc++.h>

using namespace std;

int nums[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums+N);

    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            nums[i] += nums[j];
        }
    }

    cout << accumulate(nums, nums+N, 0);

    return 0;
}