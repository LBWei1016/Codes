/*
***priority queue***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n, m;
    priority_queue<ll> coun; //�d�x
    queue<ll> wait; //���ӥ��A�ȡA���ԦC
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        wait.push(-t); //�Ѥp��j
    }
    for(int i=0; i<m; i++) {
        ll t = wait.front(); wait.pop();
        coun.push(t);
    }
    while(!wait.empty()) {
        ll w = wait.front(); wait.pop();
        ll fin = coun.top(); coun.pop();
        coun.push(fin+w);
    }
    for(int i=coun.size(); i>1; i--) {
        coun.pop();
    }
    //��̤j�ɶ�
    printf("%lld\n", -coun.top());
    return 0;
}