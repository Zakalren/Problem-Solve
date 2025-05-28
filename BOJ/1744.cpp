#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1은 묶는 의미 없음, 근데 0은 음수가 하나일 때 묶어서 0으로 만들면 좋을듯?
    // 내림차순 정렬해서 스택에 담고 두 수 꺼내서 서로 곱하고 sum

    // 단 1이 나오면 그냥 더하고 스킵, 0 나오면 음수 개수가 홀수면 0이랑 제일
    // 큰 음수 곱하기. 음수 개수가 짝수면 걍 지들끼리 곱하기

    int N;
    cin >> N;

    deque<int> negatives, positives;

    int ans = 0;

    int num;
    bool contains_zero = false;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num < 0) {
            negatives.push_back(num);
        } else if (num > 0) {
            if (num == 1) {
                ans += num;
            } else {
                positives.push_back(num);
            }
        } else {
            contains_zero = true;
        }
    }

    sort(negatives.begin(), negatives.end());  // 오름차순 정렬
    sort(positives.begin(), positives.end());  // 오름차순 정렬

    if (negatives.size() % 2 == 1) {  // 음수 중 제일 큰 애는 0이 있다면 0으로
                                      // 만들고, 아니면 그냥 더하기
        if (!contains_zero) ans += negatives.back();
        negatives.pop_back();
    }

    if (positives.size() % 2 == 1) {  // 양수 중 제일 작은 애는 그냥 더하기
        ans += positives.front();
        positives.pop_front();
    }

    while (!negatives.empty()) {
        int a = negatives.back();
        negatives.pop_back();
        int b = negatives.back();
        negatives.pop_back();

        ans += (a * b);
    }

    while (!positives.empty()) {
        int a = positives.back();
        positives.pop_back();
        int b = positives.back();
        positives.pop_back();

        ans += (a * b);
    }

    cout << ans;

    return 0;
}