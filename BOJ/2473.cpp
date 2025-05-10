#include <bits/stdc++.h>

using namespace std;

long long nums[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -97 -6 -2 6 98

    // -24 -6 -3 -2 61 98 100

    // 양 끝단에 포인터 두 개 두고
    // 포인터 두 개 합이랑 가장 가까운 값 찾아가기?(이분탐색으로)
    // 그래서 포인터 두개 합이랑 가장 가까운 값이랑 합쳐서 0이 될때까지 찾아가서
    // 끝내면 제일 가까운 값 나오지 않을까?
    // X

    // 수 하나 정해놓고
    // 걔 뒤로 두개 포인터 정한다음에 세 값의 합이 0이랑 가까운거 찾아가기

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    long long ans = LLONG_MAX;
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            long long sum = nums[i] + nums[left] + nums[right];

            if (abs(sum) < abs(ans)) {
                ans = sum;
                a = i;
                b = left;
                c = right;
            }

            if (sum < 0)
                ++left;
            else
                --right;
        }
    }

    cout << nums[a] << " " << nums[b] << " " << nums[c];

    return 0;
}