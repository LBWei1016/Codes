/*
***DP***
    Solution:
        �ѳ��ݳv���|�W��P�G�H���ݪ���P���W��ΫD���O���̾ڡA�A�P�_���p
    
    O(n ^ 2)
*/
#include <bits/stdc++.h>

using namespace std;

/*
    dp[i][j][k]:
        i: ��P�ƶq
        j: �T�O�w�����ƶq
        k: �̳��ݬO�_�W�� (lock: 1, unlock: 0)
*/
long long dp[67][67][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    for(int i=2; i<67; i++) {
        for(int j=0; j<=i; j++) {
            /*
                dp[i-1][j+1][1]:
                    ���ӳ��ݦw���A�A��W�@�ӥ��ꪺ��P�A���ܱo���w��
                dp[i-1][j][0]:
                    ���ӳ��ݴN���w���A�A��@���ꪺ��P���v�T
            */
            dp[i][j][0] += dp[i-1][j+1][1] + dp[i-1][j][0];
            if(j > 0) 
            /*
                dp[i-1][j-1][1]:
                    �b�w�������ݦA��@�W�ꪺ��P
                dp[i-1][j-1][0]:
                    �b���w�������ݩ�@�W�ꪺ��P
            */
                dp[i][j][1] += dp[i-1][j-1][1] + dp[i-1][j-1][0];
        }
    }

    int n, s;
    while(cin >> n >> s) {
        if(n < 0) break;
        long long res = dp[n][s][0] + dp[n][s][1];
        cout << res << '\n';
    }
    
    return 0;
}