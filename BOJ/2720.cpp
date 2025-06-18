#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int amount;
        cin >> amount;

        int quarter = 0;
        int dime = 0;
        int nickel = 0;
        int penny = 0;

        while (amount) {
            if (amount >= 25) {
                amount -= 25;
                quarter++;
                continue;
            }

            if (amount >= 10) {
                amount -= 10;
                dime++;
                continue;
            }

            if (amount >= 5) {
                amount -= 5;
                nickel++;
                continue;
            }

            if (amount >= 1) {
                amount -= 1;
                penny++;
                continue;
            }
        }

        cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
    }

    return 0;
}