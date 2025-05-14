#include <bits/stdc++.h>

using namespace std;

int nums[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    if (prev_permutation(nums, nums + N)) {
        for (int i = 0; i < N; i++) {
            cout << nums[i] << " ";
        }
    } else {
        cout << "-1";
    }

    return 0;
}