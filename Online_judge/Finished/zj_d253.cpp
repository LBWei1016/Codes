/*
***DP-Coin Change
*/
#include <bits/stdc++.h>

using namespace std;

const int coin[] = {1, 5, 10, 25, 50};
int dp[7490]; //dp[j]: �b���B��j�ɡA�Ҿ֦����զX��
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<5; i++)
        {
            for(int j=coin[i]; j<=n; j++)
            {
                //�p�G�u���B j ��h�ϥάY�صw�� v�v��i�H�Q�զX�X�� �A�h�Ӫ��B�@�w�i�H�Q�զX�X�ӡC
                dp[j] += dp[j-coin[i]]; 
                //e.g. dp[20] <- dp[20-5] = dp[15]: 15�h�[�@��5�Y�O20
            }
        }
        cout << dp[n] << '\n';
    }
    
    return 0;
}