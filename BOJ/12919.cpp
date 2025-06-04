#include <bits/stdc++.h>

using namespace std;

string S, T;
bool ans = false;

bool solve(string str) {
    if (str == S) return true;

    if (S.size() >= str.size()) return false;

    bool res1 = false;
    bool res2 = false;

    if (str.back() == 'A') {
        string a = str;
        a.pop_back();
        res1 = solve(a);
    }

    if (str.front() == 'B') {
        string b = str.substr(1, str.size() - 1);  // pop_front
        reverse(b.begin(), b.end());
        res2 = solve(b);
    }

    return res1 || res2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> T;

    ans = solve(T);

    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}