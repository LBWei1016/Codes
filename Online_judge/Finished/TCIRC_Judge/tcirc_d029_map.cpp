/*
***Monotone Sequence*** -- Multimap
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 2e5+5;
int n;
int h[MAX_N], p[MAX_N];
multimap<int, int> M; //h+p, pos

int main() {
    scanf("%d", &n);
    h[0] = 1e9;
    for(int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    ll res = 0;
    //�q���ӡA�ݽ��٨S�J�찪�H
    for(int i=n; i>=0; i--) {
        auto it = M.begin();
        while(it!=M.end() && it->first<h[i]) {
            int dis = it->second - i - 1;
            res += dis;
            //�J��F
            it = M.erase(it);
        }
        M.insert({h[i]+p[i], i});
    }
    printf("%lld\n", res);
    return 0;
}