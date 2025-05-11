#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, W, S;
    cin >> X >> Y >> W >> S;

    // 결국 W 두번 움직이는것보다 S가 더 크거나 같으면 S 써가면서까지 대각선으로
    // 움직일 이유 X, 만약 W 두번 움직이는것보다 S가 더 작으면 S로 움직일수 있는
    // 상황이면 S로 가면 됨.

    // 대각선 지그재그로 하면 2번 이동했을 때 상하 좌우로 2칸 간거랑 똑같을수도
    // 있음. (짝수번 이동은 대각선만 써도 상하좌우로 이동 가능)

    // 대각선으로는 X, Y 중에 더 작은 쪽 만큼은 갈수있음.

    int m = min(X, Y);
    int M = max(X, Y);
    int diff = M - m;

    if (W + W <= S) {
        cout << (long long)W * (X + Y);
    }

    else if (W <= S) {
        cout << ((long long)m * S) + ((long long)diff * W);
    }

    else {
        if (diff % 2 == 0)
            cout << ((long long)m * S) + ((long long)diff * S);
        else
            cout << ((long long)m * S) + ((long long)(diff - 1) * S) + W;
    }

    return 0;
}