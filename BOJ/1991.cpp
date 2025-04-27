#include <bits/stdc++.h>

using namespace std;

int btree[26][2];

int chartoint(char c) {
    if (c == '.') return -1;
    return c - 'A';
}

char inttochar(int i) {
    if (i == -1) return '.';
    return 'A' + i;
}

void preorder(int index) {
    if (index == -1) return;

    cout << inttochar(index);
    preorder(btree[index][0]);
    preorder(btree[index][1]);
}

void inorder(int index) {
    if (index == -1) return;

    inorder(btree[index][0]);
    cout << inttochar(index);
    inorder(btree[index][1]);
}

void postorder(int index) {
    if (index == -1) return;

    postorder(btree[index][0]);
    postorder(btree[index][1]);
    cout << inttochar(index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    char a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        int int_a = chartoint(a);
        int int_b = chartoint(b);
        int int_c = chartoint(c);

        btree[int_a][0] = int_b;
        btree[int_a][1] = int_c;
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}