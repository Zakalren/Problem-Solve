#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numerator_a, numerator_b, denominator_a, denominator_b;
    int numerator, common_denominator;

    cin >> numerator_a >> denominator_a;
    cin >> numerator_b >> denominator_b;

    numerator_a *= denominator_b;
    numerator_b *= denominator_a;

    numerator = numerator_a + numerator_b;
    common_denominator = denominator_a * denominator_b;

    int gcd_count = 0;
    do {
        int temp_count = 0;
        for (int i = min(numerator, common_denominator); i >= 2; i--) {
            if (numerator % i == 0 && common_denominator % i == 0) {
                numerator /= i;
                common_denominator /= i;
                temp_count++;
                break;
            }
        }
        gcd_count = temp_count;
    } while (gcd_count >= 1);

    cout << numerator << ' ' << common_denominator;

    return 0;
}