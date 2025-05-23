#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left = -1;
    int right;
    int result;
};

int counts[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

Node available[51];

bool is_one_digit(int num) { return num >= 0 && num < 10; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            int total = a + b;
            int count = 4;

            if (total >= 100) continue;

            if (is_one_digit(a)) {
                count += counts[a];
                count += counts[0];
            } else {
                count += counts[a % 10];
                count += counts[a / 10];
            }

            if (is_one_digit(b)) {
                count += counts[b];
                count += counts[0];
            } else {
                count += counts[b % 10];
                count += counts[b / 10];
            }

            if (is_one_digit(total)) {
                count += counts[total];
                count += counts[0];
            } else {
                count += counts[total % 10];
                count += counts[total / 10];
            }

            if (available[count].left == -1) available[count] = {a, b, total};
        }
    }

    int N;
    cin >> N;

    if (available[N].left == -1)
        cout << "impossible";
    else {
        auto& [left, right, result] = available[N];
        string left_string = to_string(left);
        string right_string = to_string(right);
        string result_string = to_string(result);

        if (is_one_digit(left)) {
            left_string = '0' + left_string;
        }
        if (is_one_digit(right)) {
            right_string = '0' + right_string;
        }
        if (is_one_digit(result)) {
            result_string = '0' + result_string;
        }

        cout << left_string << "+" << right_string << "=" << result_string;
    }

    return 0;
}