#include <bits/stdc++.h>

using namespace std;

int nums[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cin >> S;

    for (int i = 0; i < N && S > 0; i++) {
        int max_index = i;

        for (int j = i + 1; j <= i + S && j < N; j++) {
            if (nums[j] > nums[max_index]) {
                max_index = j;
            }
        }

        for (int j = max_index; j > i; j--) {
            swap(nums[j], nums[j - 1]);
            S--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}