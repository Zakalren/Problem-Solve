#include <bits/stdc++.h>

using namespace std;

typedef struct Time {
    int hour, minute, second;
} Time;

bool compare(Time t, Time t2) {
    if (t.hour == t2.hour) {
        if (t.minute == t2.minute) {
            return t.second < t2.second;
        }

        return t.minute < t2.minute;
    }

    return t.hour < t2.hour;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Time times[5000];
    for (int i = 0; i < N; i++) {
        cin >> times[i].hour >> times[i].minute >> times[i].second;
    }

    sort(times, times + N, compare);

    for (int i = 0; i < N; i++) {
        Time time = times[i];
        cout << time.hour << ' ' << time.minute << ' ' << time.second << '\n';
    }

    return 0;
}