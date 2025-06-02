#include <bits/stdc++.h>

using namespace std;

string S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> T;

    // 거꾸로 생각해서 T -> S가 가능한지 생각하면 될듯?

    while (T.size() > S.size()) {
        if (T.back() == 'A') {
            T.pop_back();
        }

        else if (T.back() == 'B') {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if (T == S)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}