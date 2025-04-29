#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lines[3];
    for (int i = 0; i < 3; i++) {
        cin >> lines[i];

        if (lines[i] == "Fizz" || lines[i] == "Buzz" || lines[i] == "FizzBuzz")
            continue;

        int num = atoi(lines[i].c_str());
        num += 3 - i;

        if (num % 3 == 0) cout << "Fizz";
        if (num % 5 == 0) cout << "Buzz";

        if (num % 3 != 0 && num % 5 != 0) cout << num;

        return 0;
    }

    return 0;
}