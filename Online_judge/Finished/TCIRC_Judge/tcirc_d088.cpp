/*
***DP*** (*)
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
int n, res;
int h[N], v[N];
int dp0[N], dp1[N]; //�I�ܦۤv (�H�ۤv�����I) ������ֿn�ȡF�ۤv�[�W�e��ֿn��
int lh[N]; //�b�ۤv����A�̱���ۤv�B��ۤv�����I
stack<int> S; //decreasing height

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }

    S.push(0); 
    h[0] = 2e9;
    //����ۤv�����I
    for(int i=1; i<=n; i++) {
        while(h[S.top()] <= h[i]) 
            S.pop();
        lh[i] = S.top();
        S.push(i);
    }
    S = stack<int>(); S.push(0);
    for(int i=1; i<=n; i++) {
        dp1[i] = dp0[lh[i]] + v[i];
        dp0[i] = dp0[S.top()];
        while(h[S.top()] < h[i]) {
            //��s����ֿn��
            dp0[i] = max(dp0[i], dp1[S.top()]);
            S.pop();
        }
        if(h[S.top()] == h[i]) {
            dp0[i] = max(dp0[i], dp0[S.top()]);
            //�]���ثe�u��s����ֿn�ȡA���i�� dp1[S.top] > dp1[i]
            //�]���٤��� pop
            //S.pop();
        }
        S.push(i);
        res = max(res, dp1[i]);
    }
    printf("%d\n", res);
    return 0;
}