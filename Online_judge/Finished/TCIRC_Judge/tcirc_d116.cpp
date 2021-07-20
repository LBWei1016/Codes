/*
***Graph / DP***
    Solution:
        �N @ ���|�ر��p���j�F���`�I���M�w�n�~���j�A�������u�b�l�`�I
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
//cost[u][i]: �� u �� parent �O�� i �r����(0~3)�A�H u ���ڪ��l�𪺳̤p�t����
int n, m, root, cost[N][4]; 
vector<int> chl[N];
unordered_map<char, int> mp = {{'A', 0}, {'U', 1}, {'C', 2}, {'G', 3}};
char s[N][85];

int dfs(int k, int v) { 
    int sum = 0, p = mp[s[v][k]];
    for(int u : chl[v]) {
        //record
        if(cost[u][p] >= 0) {
            sum += cost[u][p];
            continue;
        }
        if(s[u][k] == '@') {
            int mn = 1e9;
            for(auto temp : mp) {
                int cnt = 0;
                s[u][k] = temp.first;
                if(s[u][k] != s[v][k]) cnt++;;
                cnt += dfs(k, u);
                mn = min(mn, cnt);
            }
            cost[u][p] = mn;
            s[u][k] = '@'; //�^�_�A�ѤU�����j
        } else {
            if(s[u][k] != s[v][k]) cost[u][p] = 1;
            else cost[u][p] = 0;
            cost[u][p] += dfs(k, u);
        }
        sum += cost[u][p]; //�֥[�l�`�I
    }
    return sum;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        int a, b;
        scanf("%d%d%s", &a, &b, s[i]);
        if(a == b) root = a;  
        else chl[b].push_back(a);
    }
 
    int res = 0;
    for(int k=0; k<m; k++) {
        memset(cost, -1, sizeof(cost)); //�O�o��l��
        if(s[root][k] == '@') {
            int mn = 1e9;
            for(auto temp : mp) {
                s[root][k] = temp.first;
                mn = min(mn, dfs(k, root));
            }
            res += mn;
        }
        else res += dfs(k, root);
    }
    printf("%d\n", res);
    return 0;
}