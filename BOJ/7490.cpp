#include <bits/stdc++.h>

using namespace std;

int N;

void solve(int depth, string expression) {
    if (depth == N) {
        vector<int> nums;
        vector<char> operators;

        string number = "";

        for (const char& ch : expression) {
            if (ch == ' ') continue;

            if (ch == '+' || ch == '-') {
                nums.push_back(stoi(number));
                operators.push_back(ch);
                number = "";
            } else {
                number += ch;
            }
        }
        nums.push_back(stoi(number));

        int total = nums[0];
        for (int i = 0; i < operators.size(); i++) {
            if (operators[i] == '+')
                total += nums[i + 1];
            else
                total -= nums[i + 1];
        }

        if (total == 0) {
            cout << expression << "\n";
        }

        return;
    }

    depth++;

    solve(depth, expression + " " + to_string(depth));
    solve(depth, expression + "+" + to_string(depth));
    solve(depth, expression + "-" + to_string(depth));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        solve(1, "1");
        cout << "\n";
    }

    return 0;
}