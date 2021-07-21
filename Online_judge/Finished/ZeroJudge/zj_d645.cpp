/*
***DP*** -- Bounded knapsack
    O(N * W * T)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, W;
int v[N], w[N], t[N], dp[N]; // value, weight, number of items
int main() {
    scanf("%d%d", &n, &W);
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d", &v[i], &w[i], &t[i]);
        if(t[i] == -1) t[i] = W / w[i] + 1; // infinite items
    }
    // 0/1 knapsack
    for(int i=1; i<=n; i++) {
        // multiple items
        for(int k=1; k<=t[i]; k++) {
            for(int j=W; j>=w[i]; j--)
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}
/* �u�ơG�N���~�ƶq > 1 �������H 2 �������ƭӤl���~ (1, 2, 4, 8....)�A
        �ӳo�Ǥl���~��i�H�զX�����N�p�󵥩��ƶq�������覡�A�A�H 0/1 �I�]
        �D�ѡC���~�����W�h�� N * log T�C
    O(N * log T * W)
#include <iostream>
using namespace std;

const int MAX_W = 1005;
const int N = 8000;
int n, W;
int v[N], w[N], dp[MAX_W]; // value, weight, number of items
int main() {
    scanf("%d%d", &n, &W);
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a, b, t, j;
        scanf("%d%d%d", &a, &b, &t);
        if(t < 0) t = W / b;
        for(j=1; j<t; j<<=1) {
            v[cnt] = a * j;
            w[cnt++] = b * j;
        }
        if(t == j) {
            v[cnt] = a;
            w[cnt++] = b;
        }
    }
    // 0/1 knapsack
    for(int i=0; i<cnt; i++) {
        // multiple items
        for(int j=W; j>=w[i]; j--)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
    printf("%d\n", dp[W]);
    return 0;
}
*/