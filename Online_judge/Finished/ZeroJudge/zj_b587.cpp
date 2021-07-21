/*
***DP***
    Solution:
        n = 2�A�� 3 �رƪk�Fn > 2�A�u���W�U��٨�� (�Ѥ�����m��������F��L�k���ά���p�x�Ϊ��ت�)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[31];
int main() {
    dp[0] = 1, dp[2] = 3;
    for(int i=4; i<=30; i+=2) {
        dp[i] = 4*dp[i-2] - dp[i-4];
    }
    int n;
    while(scanf("%d", &n)) {
        if(n == -1) break;
        printf("%d\n", dp[n]);
    }    
    return 0;
}