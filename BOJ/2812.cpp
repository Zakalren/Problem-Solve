#include <bits/stdc++.h>

using namespace std;

string num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int N, K;
    cin >> N >> K >> num;

    int count = K;
    for (int i = 0; i < N; i++) {
        while (!s.empty() && count > 0) {
            int top = s.top();
            if (top >= num[i]) break;

            s.pop();
            count--;
        }

        s.push(num[i]);
    }

    while (count) {
        s.pop();
        count--;
    }

    string ans;
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    // 그냥 앞자리부터 쭉 작은애들 제거하는거 K번 반복하면 안되나 ?

    return 0;
}