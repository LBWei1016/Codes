/*
***DP*** -- 01knapsack �ܧ� + �u�ʰ}�C
    Solution:
        �b�Ҧ��m���d����ܤ����A���̤j���u���h���i��v�A�A�H�Ҧ������۴�A
        �Y���D�حn�D���̤p�ȡC

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
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, s, w = 0;
int c[200005], dp[200005];
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for(int i=0; i<n; i++) {
        scanf("%d", &c[i]);
        w += c[i]; //sum of rent
    }
    for(int i=0; i<n; i++) {
        for(int j=m-s; j>=c[i]; j--) {
            dp[j] = max(dp[j], dp[j-c[i]]+c[i]);
        }
    }
    printf("%d\n", w-dp[m-s]);
    return 0;
}
*/