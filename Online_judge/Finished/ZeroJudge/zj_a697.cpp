/*
***DP*** 
    Description:
        �� m �Ӫ�� n �ت�A�� i �تᦳ��̤j�ƶq a[i]�A�D�@���u�B�N�P�ت��\��b�@�_����k��
    Solution:
        ���i��:
            dp[i][j] = dp[i-k][j-1] (for k from 0 to a[i]) => �[�J 0 ~ a[j] �ֲ� j �ت�

    O(m * n * a)

    P.S. �o�O�Ĥ@�ӧ����ۤv�Q�X�Ӫ� DP !!!
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100+5;
const int MOD = 1000007;
int n, m;
int a[MAX]; 
int dp[MAX][MAX]; //dp[i][j]: �� i �Ӫ�� j �ت�ɪ��\���k��

void solve() {
    for(int i=1; i<=a[1]; i++) dp[i][1] = 1; //�������\�Ĥ@�ت��
    for(int j=1; j<=n; j++) dp[0][j] = 1; //�������\�� j �ت��

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            //���X k �Ӧ�l������ i �ت��\��
            for(int k=0; i-k>=0 && k<=a[j]; k++) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % MOD;
            }
        }
    }
    cout << dp[m][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    solve();
    
    return 0;
}