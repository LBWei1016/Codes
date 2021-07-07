/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e5;
int N, L;
ll p[MAX_N];
//�H�����I�s���i�滼�j (�]���O�H�����I�M�w���j�O�_����)
ll cut(int l, int r) {
    if(r-1 <= l) return 0; //�S�������I�F
    ll mid = (p[l] + p[r]) / 2; //�䤤�I
    int m = lower_bound(p+l, p+r, mid) - p;
    //��Z�����I��B�s���p��
    if(p[m-1] - p[l] >= p[r] - p[m]) m--;
    return p[r] - p[l] + cut(l, m) + cut(m, r);
}

int main() {
    scanf("%d%d", &N, &L);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &p[i]);
    }
    p[0] = 0, p[N+1] = L;
    printf("%lld\n", cut(0, N+1));
    return 0;
}