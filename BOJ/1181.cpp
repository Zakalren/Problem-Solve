#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b)
{
    if (a.size() == b.size())
        return a < b;
    
    return a.size() < b.size();
}

main()
{
    int N, tmp;
    scanf("%d", &N);
    tmp = N;
    
    string ss[N], same;
    while (tmp--)
    {
        cin >> ss[tmp];
    }
    
    sort(ss, ss+N, cmp);
    
    for (int i = 0; i < N; i++)
    {
        if (ss[i] == same)
            continue;
        
        cout << ss[i] << "\n";
        same = ss[i];
    }
}