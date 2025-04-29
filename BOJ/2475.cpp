#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 0;
    int a;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        a = ((a % 10) * (a % 10)) % 10;
        res = ((a % 10) + (res % 10)) % 10;
    }

    cout << res;

    return 0;
}