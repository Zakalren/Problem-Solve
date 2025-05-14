#include <bits/stdc++.h>

using namespace std;

int nums[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        nums[i] = i + 1;
    }

    do {
        for (int i = 0; i < N; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(nums, nums + N));

    return 0;
}