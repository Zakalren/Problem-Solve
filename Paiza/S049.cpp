#include <bits/stdc++.h>

using namespace std;

struct Node {
    int depth, writableLines, leftLines;
};

queue<Node> q;

int N, X, F, S, ans = 2000000000;

// Sol 1)
// feedback : depth가 무한정 증가할 수 있다 => 타임오버
// 다른 방법 생각해보기.
/*
void solve(int depth, int writableLines, int leftLines) { 
    if (writableLines >= leftLines) { // 코드 작성이 끝났으면 답 갱신하기
        ans = min(depth, ans);
        return;
    }

    if (writableLines <= 0) { // 더이상 코드 작성이 불가하면 수면만 취하기
        solve(depth+3, writableLines + S, leftLines);
        return;
    }

    if (writableLines >= X) { // 수면 취할 필요 없으면 코드만 작성하기
        solve(depth+1, max(writableLines-F, 0), leftLines-writableLines);
        return;
    }

    // 수면, 개발 둘 다 가능하면 둘 다 해보기
    solve(depth+1, max(writableLines - F, 0), leftLines-writableLines); // 코드 작성
    solve(depth+3, min(writableLines + S, X), leftLines); // 수면 취하기
}
*/

// bfs? 
// Sol 1과 동일한 결과
/*
void solve() {
    while (!q.empty()) {
        Node node = q.front();
        int depth = node.depth;
        int writableLines = node.writableLines;
        int leftLines = node.leftLines;
        q.pop();

        if (writableLines >= leftLines) { // 코드 작성이 끝났으면 답 갱신하기
            ans = min(depth, ans);
            return;
        }

        if (writableLines <= 0) { // 더이상 코드 작성이 불가하면 수면만 취하기
            q.push({ depth+3, writableLines + S, leftLines });
            continue;
        }

        if (writableLines >= X) { // 수면 취할 필요 없으면 코드만 작성하기
            q.push({ depth+1, max(writableLines-F, 0), leftLines-writableLines });
            continue;
        }

        // 수면, 개발 둘 다 가능하면 둘 다 해보기
        q.push({ depth+1, max(writableLines - F, 0), leftLines-writableLines }); // 코드 작성
        q.push({ depth+3, min(writableLines + S, X), leftLines }); // 수면 취하기
    }
}
*/

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X >> F >> S;

    //solve(1, S, N);

    //q.push({ 1, S, N });
    //solve();


    cout << ans;

    return 0;
}