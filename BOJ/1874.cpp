#include <bits/stdc++.h>

using namespace std;

int nums[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    string str = "";

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int cur = 1;
    bool failed = false;

    for (int i = 0; i < N; i++) {
        int target = nums[i];

        while (cur <= target) {
            s.push(cur);
            cur++;
            str += "+\n";
        }

        if (!s.empty() && s.top() == target) {
            s.pop();
            str += "-\n";
        } else {
            failed = true;
            break;
        }
    }

    if (failed)
        cout << "NO\n";
    else
        cout << str;

    return 0;
}