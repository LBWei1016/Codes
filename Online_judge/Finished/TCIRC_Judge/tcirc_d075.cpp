/*
***DP*** -- 01knapsack �ܧ� + �u�ʰ}�C
    Solution:
        �b�Ҧ��h������ܤ����A���̤j���u���h���i��v�A�A�H�Ҧ������۴�A
        �Y�i���D�حn�D���̤p�ȡC

    O(N * M)
*/
#include <bits/stdc++.h>
using namespace std;

int N, M, S;
int dp[2][200005];

int main() {
    scanf("%d%d%d", &N, &M, &S);
    int from = 0, to = 1;
    int sum = 0;
    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        for(int j=0; j<x; j++) {
            dp[to][j] = dp[from][j];
        }
        for(int j=x; j<=M-S; j++) {
            dp[to][j] = max(dp[from][j], dp[from][j-x] + x);
        }
        swap(from, to);
    }
    
    printf("%d\n", sum - dp[from][M-S]);
    return 0;
}