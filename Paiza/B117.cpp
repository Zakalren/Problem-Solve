#include <iostream>
#include <queue>

using namespace std;

queue<int> A;
int N, last, temp, result = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push(temp);
    }

    while (!A.empty()) {
        int size = A.size();
        for (int i = 0; i < size; i++) {
            int cur = A.front();
            A.pop();

            if (cur == last + 1) {
                last = cur;
            } else {
                A.push(cur);
            }
        }
        result++;
    }

    cout << result;

    return 0;
}