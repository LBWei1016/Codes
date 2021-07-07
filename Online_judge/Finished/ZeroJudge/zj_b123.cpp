/*
***DP***
    Description:
        �D���ϧΤ��� 1 �c�����̤j�x�έ��n
    Solution:
        �ۥ��W���}�l�A�O���C��s�� 1 ���ƥ�(len[])�A�ä��_������s���[�����n(k = j-1, k--)

    O(M * N^2)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N_M = 200+5;

int M, N;
int G[MAX_N_M][MAX_N_M]; //0 or 1
int len[MAX_N_M]; //�O���ܸӦC����A�@���h�ֳs�� 1

void solve() {
    int res = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            len[j] = G[i][j] ? len[j]+1 : 0;
            int p = len[j]; //���n�� 1*len[j] (�����V���x��)
            res = max(res, p);
            for(int k=j-1; k>=0 && G[i][k]; k--) {
                p = min(p, len[k]); //�����p�Ȥ~�|�O���㪺�x��
                res = max(res, p * (j-k+1)); //(j-k+1) �O�x�Ϊ��e
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> M >> N) {
        memset(G, 0, sizeof(G));
        memset(len, 0, sizeof(len));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cin >> G[i][j];
            }
        }
        solve();
    }
    
    return 0;
}