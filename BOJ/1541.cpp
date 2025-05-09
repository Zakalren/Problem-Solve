#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;

    int ans = 0;
    int operand = 0;
    int minus = 0;
    for (int i = 0; i <= line.size(); i++) {
        if (!isdigit(line[i]) || i == line.size()) {
            if (minus) {
                ans -= operand;
            }
            else {
                ans += operand;
            }

            if (line[i] == '-')
                minus = 1;

            operand = 0;
        }
        else {
            operand *= 10;
            operand += line[i] - '0';
        }
    }

    cout << ans;

    return 0;
}