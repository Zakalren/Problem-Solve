#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
    return a.first < b.first;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N, a;
    string b;
    
    cin >> N;
    
    pair<int, string> pairs[N];
    
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }
    
    stable_sort(pairs, pairs+N, cmp);
    
    for (int i = 0; i < N; i++)
        cout << pairs[i].first << " " << pairs[i].second << '\n';
}