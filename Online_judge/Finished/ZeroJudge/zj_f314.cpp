/*
***DP***
    Solution:
        �ϥΥt�~���}�C(�D dp[][])�ӰO���֥[���� -- �]���D�ح���u�ਫ�s�򪺮�l
    
    O(M * N)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_M = 50+5;
const int MAX_N = 10000+5;

int M, N;
ll a[MAX_N]; //������e���C
ll dp[MAX_M][MAX_N];
ll l[MAX_N], r[MAX_N]; //�����Y�C���q���αq�k�֥[

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            cin >> a[j]; 
            if(j == 1) l[j] = dp[i-1][j] + a[j]; //�q�e�@�檺�Ĥ@�C���U��
            else l[j] = max(dp[i-1][j], l[j-1]) + a[j]; //�q���ΤW
        }
        for(int j=N; j>=1; j--) {
            if(j == N) r[j] = dp[i-1][j] + a[j]; //�q�e�@�檺�̫�@�C���U��
            else r[j] = max(dp[i-1][j], r[j+1]) + a[j]; //�q�k�ΤW
            dp[i][j] = max(l[j], r[j]);
        }
    }
    ll ans = -1e9;
    for(int j=1; j<=N; j++) {
        ans = max(ans, dp[M][j]);
    }
    cout << ans << '\n';
    
    return 0;
}