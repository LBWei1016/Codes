/*
***DP***
    Description:
        �O p(i,j) = �b [1,j] �϶����������W�L i ���R�檺�̤j��Q�A�h
        p(i,j) = max{ c[j]-c[t]+p(i-1,t-1): for all t<j }
    Solution:
        �Q�k�@�G�C�|�Ҧ����ΡA��X�ϥ��N j �̤j�� t�AO(k*n^2)�A����C
        �Q�k�G�G�� j �P�ɧ�X�̤p�� c[t] �H�γ̤j�� p(i-1,t-1)�A���L�k�P�ɺ��@��̡C
        �Q�k�T�G
            ���s�˵����j��: c[j] + {p(i-1,t-1) - c[t]}�A��� t ���ɧY��h c[t]�C
        �]���A�u�ݭn���@�u�̤j�i�諸 p(i-1,t-1) - c[t]�v�Y�i�A�ӿ�ܷ|�] j ��
        �W�ӧ��ܡ]�i�H��ܧ��u�ժ��^�C
            �ϥ� deque ���x�s�up(i-1,t-1) - c[t] �����W�ǦC�v�A�z�ѡG�H�� j ���W�A
        �i��ܪ��e�m���A�W�[�A�]���A�Y�e�������A�����s�[�J�����A�t�A�O�i�H�˱󪺡F
        ���G�N�O�Adeque ���׬O val �٬O r �Ҭ����W���C
            �t�~�A�]���p��覡���N�R�榸�Ʋֿn�p�� (1~k)�Adp �}�C���ӬO�G���}�C�A
        ���ڭ̥u�ݭn�ϥΨ�e�@���R�� (�e�@�C) ����T�A�åB�e�@�C����T�w�g�̻��W������
        �s�� deque �����A�]���@���}�C�N���F�C
    
    O(k * n)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int val, r; };
int n, k;
vector<int> p; //price
deque<P> pre_mx; //increasing sequence of: dp[i-1][t-1] - p[t]
int dp[100005]; //int dp[105][100005]

void put_max(P p) {
    if(!pre_mx.empty() && pre_mx.back().val > p.val) {
        return;
    }
    pre_mx.push_back(p);
}
int main() {
    scanf("%d%d", &n, &k);
    p.resize(n+5);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
        put_max(P{-p[i], i});
    }
    for(int i=1; i<=k; i++) {
        P prev = pre_mx.front(); 
        pre_mx.pop_front();
        for(int j=1; j<=n; j++) {
            //if a better condition is available
            if(!pre_mx.empty() && j > pre_mx.front().r) {
                prev = pre_mx.front();
                pre_mx.pop_front();
            }
            dp[j] = max(dp[j-1], p[j]+prev.val);
        }
        pre_mx.clear();
        for(int j=1; j<=n; j++) {
            put_max(P{dp[j-1]-p[j], j});
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}