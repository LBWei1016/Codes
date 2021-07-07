/*
***DP*** -- �G���̤j�l�x�}
    Solution:
        ���D�U�檺�e��M�A�A��C�i��C�| (�� i, j �h�����d��)

    O(n * m^2)
*/
#include <bits/stdc++.h>
using namespace std;

int m, n;
int dp[205][205]; //�� k ��� i �C��� j �C

int main() {
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &dp[i][j]);
            dp[i][j] += dp[i-1][j]; //prefix sum
        }
    }
    int mx = 0;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<=m; j++) {
            int sum = 0;
            for(int k=1; k<=n; k++) { 
                sum += dp[j][k] - dp[i][k];
                sum = max(0, sum);
                mx = max(mx, sum);
            }
        }
    }
    printf("%d\n", mx);
    return 0;
}