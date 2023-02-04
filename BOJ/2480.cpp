#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + (1000 * a);
    }

    else if (a == b || b == c || a == c) {
        if (a == b || a == c)
            cout << 1000 + (100 * a);
        else 
            cout << 1000 + (100 * b);
    }

    else {
        cout << max(a, max(b, c)) * 100;
    }

    return 0;
}