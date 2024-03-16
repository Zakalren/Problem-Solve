#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int N, islands[100001], sz[100001];

int find(int x) {
    if (x == islands[x])
        return x;
    
    return islands[x] = find(islands[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    islands[a] = b;
}

ll pairs_count(ll x) {
    return x * (x - 1) / 2;
}

ll bridges_count(ll x) {
    return ((x - 1) * x * (x + 1)) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        islands[i] = i;
        sz[i] = 1;
    }

    int tmp;
    ll pairs = 0, bridges = 0;
    for (int i = 0; i < N-1; i++) {
        cin >> tmp;
        
        int a = find(tmp);
        int b = find(tmp+1);
        merge(a, b);

        pairs -= pairs_count(sz[a]) + pairs_count(sz[b]);
        bridges -= bridges_count(sz[a]) + bridges_count(sz[b]);
        
        sz[b] += sz[a];

        pairs += pairs_count(sz[b]);
        bridges += bridges_count(sz[b]);

        cout << pairs << ' ' << bridges << '\n';
    }


    return 0;
}