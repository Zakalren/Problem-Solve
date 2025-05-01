#include <bits/stdc++.h>

using namespace std;

pair<int, int> points[10000];

double solve(double x1, double x2, double x3, double y1, double y2, double y3) {
    double ans = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
    return ans / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double ans = 0;
    for (int i = 1; i < N; i++) {
        ans += solve(points[0].first, points[i - 1].first, points[i].first,
                     points[0].second, points[i - 1].second, points[i].second);
    }

    printf("%.1f", abs(ans));

    return 0;
}