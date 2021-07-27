/*
***Graph*** -- diameter, radius, center of tree
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct E { int to, w; };
int n, m, l, D;
bitset<N> vis;
vector<E> ds(N), G[N];

int dfs(int v, int p) {
    vis[v] = 1;

    int id = 0, d = 0;
    for(auto e : G[v]) {
        int u = e.to, w = e.w;
        if(u == p) continue;
        d = w + dfs(u, v);
        // record the highest child
        if(d > id) {
            id = d; 
            ds[v].to = u; ds[v].w = w;
        }
    }
    return id;
}
int main() {
    while(scanf("%d%d%d", &n, &m, &l) != EOF) {
        // init!!!
        for(int i=0; i<n; ++i) {
            ds[i].to = -1; ds[i].w = 1e9;
            G[i].clear();
        }
        vis.reset();

        for(int i=0; i<m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int res = 0; 
        int mx[5] = {0}; // ���ݤ��P�ʾ𪺫e�T�j�b�| (�h���t�Ŷ��Ӧs�D�e�T�j��)
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                dfs(i, n);
                int v, sum = 0, dx, st = 3;
                // go to the deepest leaf -- an end point of diameter
                for(v=i; ds[v].to>0; v=ds[v].to); 
                D = dfs(v, n);

                res = max(res, D); // self
                while(sum+ds[v].w <= D/2) {
                    sum += ds[v].w;
                    v = ds[v].to;
                }
                dx = min(sum+ds[v].w, D-sum);
                // record the 1-st, 2-nd, and 3-rd great value, consecutively
                // point!!!
                while(st && dx > mx[st-1]) {
                    mx[st] = mx[st-1];
                    st--;
                }
                mx[st] = dx;
            }
        }
        // ���T���H�W���� / �u����ʾ�
        if(n-m > 2) res = max(res, max(mx[0]+mx[1]+l, mx[1]+mx[2]+2*l));
        else if(n-m > 1) res = max(res, mx[0]+mx[1]+l); 
        printf("%d\n", res);
    }
    return 0;
}