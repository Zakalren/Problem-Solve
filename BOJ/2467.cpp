#include <bits/stdc++.h>

using namespace std;

int N, m = INT_MAX;
int nums[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // sort(nums, nums + N);

    int m_left = INT_MAX / 2, m_right = INT_MAX / 2;
    for (int i = 0; i < N; i++) {
        int left = 0, right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (i == mid) {
                if (mid < N - 1)
                    left = mid + 1;
                else
                    right = mid - 1;
                continue;
            }

            if (abs(nums[i] + nums[mid]) == 0) {
                cout << nums[i] << " " << nums[mid];
                return 0;
            }

            if (abs(nums[i] + nums[mid]) < abs(m_left + m_right)) {
                m_left = nums[i];
                m_right = nums[mid];
            }

            if (nums[i] + nums[mid] < 0) {
                left = mid + 1;
            } else if (nums[i] + nums[mid] > 0) {
                right = mid - 1;
            }
        }
    }

    cout << m_left << " " << m_right;

    return 0;
}