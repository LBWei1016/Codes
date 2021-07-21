/*
***DP*** -- top-down
    Solution:
        �H�x�}���D��C
        �b�d�� [i, j] ���A��� for all k such that i<=k<j�A�� k �Y�O�N��̫�
        �@�����k�o�ͪ���m�A�N���k����b�A�]�N�O���A�o�ӻ��j���O�˵۰����G
        ���_���筼�k�媺�i��̫�@�����k���G�A�A���̤p�ȡC
    O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int main() {
    int n;
    int p[N];
    int sum[N][N] = {0};
    scanf("%d", &n);
    for(int i=0; i<n+1; i++) {
        scanf("%d", &p[i]);
    }
    for(int len=1; len<n; len++) {
        //sum(i, i+len)
        for(int i=0; i+len<n; i++) {
            int j = i + len, mn = 1e9;
            for(int k=i; k<j; k++) {
                //p[i]*p[k+1]*p[j+1]: row(i) * col(k) * col(j)
                mn = min(mn, sum[i][k]+sum[k+1][j]+p[i]*p[k+1]*p[j+1]);
            }
            sum[i][j] = mn;
        }
    }
    printf("%d\n", sum[0][n-1]);
    return 0;
}
/* �t�@�ؼg�k (�e��������)
//�����I�v�������
for(int j=1; j<n; j++) {  
    //�}�l�I���e�� (�����ܪ�)
    for(int i=j-1; i>=0; i--) {
        int mn = 1e9;
        //�C�|�I�_�I
        for(int k=i; k<j; k++) {
            mn = min(mn, sum[i][k]+sum[k+1][j]+p[i]*p[k+1]*p[j+1]);
        }
        sum[i][j] = mn;
    }
}
*/