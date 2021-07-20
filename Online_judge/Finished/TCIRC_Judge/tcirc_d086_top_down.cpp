/*
***DP*** -- top-down
    Solution:
        �H�x�}���D��C
        �b�d�� [i, j] ���A��� for all k such that i<=k<j�A�� k �Y�O�N��̫�
        �@�����k�o�ͪ���m�A�N���k����b�A�]�N�O���A�o�ӻ��j���O�˵۰����G
        ���_���筼�k�媺�i��̫�@�����k���G�A�A���̤p�ȡC

    O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int p[205];
int dp[205][205];
int f(int i, int j) {
    if(dp[i][j] >= 0) return dp[i][j];
    int mn = 1e9;
    for(int k=i; k<j; k++) {
        //point!!!
        //p[i]*p[k+1]*p[j+1]: row(i) * col(k) * col(j)
        mn = min(mn, f(i, k)+f(k+1, j)+p[i]*p[k+1]*p[j+1]);
    }
    return dp[i][j] = mn;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n+1; i++) {
        scanf("%d", &p[i]);
    }
    memset(dp,-1, sizeof(dp));
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;
    }
    printf("%d\n", f(0, n-1));
    return 0;
}