/*
***Graph***
    Solution I�BII:
        �⦸ DFS !!!
    O(V)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
// d[]: �`�סFds[]: �������|���s��
int n, d[N], ds[N]; 
// mid[]: �i�઺��߮y�� (�Y���|�����ƫh�����)�FD: ���|
int mid[2], D;
vector<int> G[N];
int dfs1(int, int);
int dfs2(int, int);

int main() {
    // ��k�@:
    d[0] = -1; // dummy
    scanf("%d", &n);
    for(int i=0; i<n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++u; ++v; // ����K�_���A�q 1 �}�l�s��
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root2 = dfs1(1, 0);
    dfs1(root2, 0);
    printf("---------------------\n");
    printf("D: %d\nmid0: %d\nmid1: %d\n", D, mid[0], mid[1]);
    printf("d[mid[0]]: %d\nd[mid[1]]: %d\n", d[mid[0]], d[mid[1]]);

    /*--------------------------�H�U����k�G-------------------------------------*/

    memset(ds, -1, sizeof(ds)); // -1 �N��
    dfs2(1, 0); // 1 �i�N�������N�_�l�I
    int v, rad = 0, mid;
    for(v=1; ds[v]>0; v=ds[v]); // v = �_�l�I�A�̲� v = ���|���I
    D = dfs2(v, 0);
    while(rad + 1 <= D/2) {
        rad++; v = ds[v];
    }
    mid = v; // ��ߧY���̫᪺ v
    printf("D: %d\nrad: %d\nmid: %d\n", D, rad, mid);
    return 0;
}

int dfs1(int v, int p) {
    d[v] = d[p] + 1;
    if(G[v].size()==1 && G[v][0]==p) return v; // leaf

    // id: �l�𤤲`�׳̲`�̡A�Y�کҨ�̻����`�I (���|���t�@���I)
    // ���j�̲ܳ`�B��Y�i�o�����|���A�A�^���w���� (���|���I)
    int id = 0, temp;
    for(auto u : G[v]) {
        if(u == p) continue;
        temp = dfs1(u, v);
        if(d[temp] > d[id]) id = temp;
    }
    // ��s���|�P���
    if(d[id] > D && d[v] == d[id]/2+1) {
        D = d[id];
        if(D & 1) {
            mid[0] = v;
            mid[1] = 0;
        }
        else {
            mid[0] = v;
            mid[1] = p;
        }
    }
    return id;
}
int dfs2(int v, int p) {
    int id = 0, d = 0;
    for(auto u : G[v]) {
        if(u == p) continue;
        d = 1 + dfs2(u, v); 
        // �����̲`���l��
        if(d > id) {
            id = d; 
            ds[v] = u;
        }
    }
    return id;
}
/* test cases:
8
0 1
0 2
0 3
7 0
1 4
1 5
3 6
*/