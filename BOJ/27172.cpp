#include <bits/stdc++.h>

using namespace std;

int nums[1000000];
int scores[1000001];
bool exists[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        exists[nums[i]] = true;
    }

    // 각각 num에서 1,000,000 까지의 num의 배수 인덱스의 스코어 조작하기?

    // cout << "최대값: " << *(s.rbegin()) << "\n";

    for (int n = 0; n < N; n++) {
        int num = nums[n];

        if (!exists[num]) continue;

        for (int i = num * 2; i <= 1000000; i += num) {
            if (exists[i]) {
                scores[i]--;
                scores[num]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << scores[nums[i]] << " ";
    }

    return 0;
}