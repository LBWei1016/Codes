/*
***Graph*** -- diameter of tree -- farthest of farthest
    Solution:
        First, start from any given node, traverse to the deepest node, and 
        make that node a new root.
        Second, start from the new root to find out the deepest node from it,
        and the depth is exactly the farthest distance.
    Statement:
        For any node u in G, the farthest node of it is an end point of D(diameter)
    Proof:
        1.  Let u be one of the end popints of D�Fproved
        2.  Let u be on D but is not either end points.
                Suppose d1 + d2 = D and d1 > d2, and d3 > d1.
                If the end point of d3 isn't that of D's, then D can be 
                lengthened to "d3 + d2 > d1 + d2 = D"�Fproved
        3.  Let u be neither of the above situations.
                ��ө������Av ���M���V D ������I a, b �䤤�@��F�Y v ���V a�A
                �h dvb >= dva�C���]�@�I c�Advc > dvb�A�h dcvb = dvc + dvb > dvb + dva = D�A
                �]�� c �������|�����I���X�C
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, d[N];
vector<int> G[N];

int bfs(int r) {
    memset(d, -1, sizeof(d));
    int mx = 0, r2;
    queue<int> que;
    que.push(r); d[r] = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int u : G[v]) {
            if(d[u] >= 0) continue; //visited
            d[u] = d[v] + 1;
            if(d[u] > mx) {
                mx = d[u];
                r2 = u;
            }
            que.push(u);
        }
    }
    return r2;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    printf("%d\n", d[bfs(bfs(0))]);
    return 0;
}