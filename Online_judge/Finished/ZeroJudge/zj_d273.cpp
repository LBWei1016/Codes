/*
***DP*** -- UVa11584
    Description:
        �̪��j��l�r��

    O(size(str) ^ 2)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000+5;
int dp[MAX_N]; //str[1] ~ str[i] ���̤p���j��l�r��ƶq
char str[MAX_N];
int n;
//�ˬd�O�_�j��
bool pal(int L, int R) {
    while(L < R) {
        if(str[L++] != str[R--]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        int i;
        fill(dp, dp+MAX_N, 0x7fffffff);
        dp[0] = 0;
        scanf("%s", str+1); //�q�@�}�l
        //�q����k
        for(i=1; str[i]; i++) { 
            for(int j=1; j<=i; j++) {
                //�ˬd str[j] ~ str[i] �O�_�j��
                if(pal(j, i)) {
                    /*
                        dp[j-1] + 1: 
                            �w�� str[i] ~ str[j] ���j��A�h�����N��į� str[i] ~ str[j] 
                            �o�q�@���j��l�r��
                    */
                    dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        printf("%d\n", dp[i-1]);
    }
    
    return 0;
}