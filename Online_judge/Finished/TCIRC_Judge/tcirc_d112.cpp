/*
***Graph*** -- Minimal Dominating Set
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
//ch[]: �O�_���p�ĳQ��W (�Y���A�h�ۤv���Q��W�]�i�H)
bool visit[N], ch[N];
//vac[]: ��l�� = deg[]�F�N�������i��F���A�Ȥ��ߪ��p�ļƶq
int p[N], deg[N], vac[N];
vector<int> G[N];
//��Ƭ����ھ�
void dfs(int v) {
    visit[v] = true;
    for(int u : G[v]) {
        if(!visit[u]) {
            p[u] = v;
            deg[v]++; vac[v]++;
            dfs(u);
        }
    }
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //�H 1 ����
    dfs(1);
    queue<int> que;
    for(int i=2; i<=n; i++) {
        if(deg[i] == 0) 
            que.push(i);
    }
    int res = 0; p[1] = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        //�Y���p�Ĥ������i��F���A�Ȥ���
        if(vac[v]) {
            res++; //�ۤv�����A�Ȥ���
            vac[p[v]]--;
            ch[p[v]] = true;
        } else if(ch[v]) vac[p[v]]--; //�Y���p�ĬO�A�Ȥ���
        if(--deg[p[v]] == 0)
            que.push(p[v]);
    }
    if(!vac[1] && !ch[1]) res++;
    printf("%d\n", res);
    return 0;
}