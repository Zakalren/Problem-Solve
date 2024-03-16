#include <bits/stdc++.h>

using namespace std;

int N, M, tree[100001 * 4], arr[100001];

int init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid+1, end, node * 2 + 1));
}

int findMin(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 1000000001;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M; 

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init(0, N-1, 1);

    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << findMin(0, N-1, 1, a-1, b-1) << '\n';
    }

    return 0;
}