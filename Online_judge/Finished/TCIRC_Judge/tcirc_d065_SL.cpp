/*
***Sweep Line***
    Solution:
        �N�j�Ө̻��W���ש�m�� stack ���F�C��J���@�ɤ���|���C���A
        �Y�s����X�ϰ��|��_���W���ǡA�æb�o�L�{���p���ثe�����
        �ۤv�����j�өҳ�X�����n

    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n;
    ll h[100005];
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &h[i]);
    }
    //��ɳB�z
    h[0] = -1; 
    h[n+1] = 0;
    stack<int> inc; //increasing subsequence�Findex
    inc.push(0);
    ll res = 0;
    for(int i=1; i<=n+1; i++) {
        if(h[i] > h[inc.top()]) inc.push(i);
        if(h[i] >= h[inc.top()]) continue;
        while(h[inc.top()] >= h[i]) {
            ll height = h[inc.top()]; inc.pop();
            //�p�� (inc.top(), i) �����ϰ쪺���n
            res = max(res, (i-inc.top()-1)*height);
        }
        inc.push(i);
    }
    printf("%lld\n", res);
    return 0;
}