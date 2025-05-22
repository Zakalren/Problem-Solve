#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // SK -> CY -> SK
    // 1 -> SK -> SK
    // 2 -> SK CY -> CY
    // 3 -> SK SK SK -> SK
    // 4 - > SK CY CY CY, SK SK SK CY -> CY
    // 5 -> SK CY CY CY SK, SK CY SK SK SK, SK SK SK CY CY -> SK
    // 6 -> SK CY SK CY SK CY, SK CY SK CY CY CY, SK CY SK SK SK CY, SK CY CY CY
    // SK CY, SK SK SK CY CY CY -> CY

    if (N % 2 == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}