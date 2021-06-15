/*
***DP-Subset***
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_P 20
#define MAX_N 1000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, p;
    cin >> t;
    while(t--)
    {
        int dp[MAX_N+1] = {}, 
            l[MAX_P+1] = {};
        cin >> n >> p;
        for(int i=0; i<p; i++)
            cin >> l[i];
        dp[0] = 1;
        for(int i=0; i<p; i++)
        {
            for(int j=n; j>=l[i]; j--)
            {
                if(dp[j-l[i]]) //��dp[j-l[i]] = 1�A�N�����j-l[i]�s�b�A�Sl[i]�]�s�b�A�]��j�s�b
                    dp[j] = 1;
            }
        }
        if(dp[n])
            cout << "YES\n";
        else 
            cout <<"NO\n";
    }
    return 0;
}