/*
***Divide and Conquer***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//���v�A�C��������b���j�A�q�����V���k��s���A
ll area(ll h[], int s, int t) {
    if(s >= t) return 0;
    if(s+1 == t) return h[s];
    int m = (s+t) / 2;
    ll largest = max(area(h, s, m), area(h, m+1, t));
    ll i = m, j = m, cross = 0, height = h[m];
    //�����V���k��s���A (�u�ʮɶ�)
    while(i>=s || j<t) {
        if(i < s) height = h[j];
        else if(j >= t) height = h[i];
        else height = max(h[i], h[j]);
        while(i>=s && h[i] >= height) 
            i--;
        while(j<t && h[j] >= height)
            j++;
        cross = max(cross, height*(j-i-1));
    }
    return max(cross, largest);
} 
int main() {
    int n;
    ll h[100005];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &h[i]);
    }
    printf("%lld\n", area(h, 0, n));
    return 0;
}