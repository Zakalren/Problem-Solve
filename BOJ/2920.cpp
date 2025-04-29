#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    bool ascending = true, descending = true;

    int index = 0;
    while (index < 8) {
        if (arr[index] != index + 1) {
            ascending = false;
        }

        if (arr[index] != 8 - index) {
            descending = false;
        }

        ++index;
    }

    if (!ascending && descending) {
        cout << "descending";
    }

    else if (ascending && !descending) {
        cout << "ascending";
    }

    else {
        cout << "mixed";
    }

    return 0;
}