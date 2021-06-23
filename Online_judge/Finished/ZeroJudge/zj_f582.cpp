/*
***DP*** 
    Reference: https://yuihuang.com/zj-f582/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int n, m, root;
int dp[1005][85][5]; //dp[n][m][sym]: �� n �ӧǦC�B�� m �Ӧr���Ÿ��O sym 
int ans, inf = 1e9;
string s[1005]; //s[i]: i �ǦC
vector <int> v[1005]; //v[i]: i ���l�`�I
map <char, int> mp = {{'@', 0}, {'A', 1}, {'U', 2}, {'C', 3}, {'G', 4}};
 
void f(int now, int pos){
    //��S���l�`�I��
    if (v[now].empty()){
        //�Y���U�Φr���A�����Ҽ{�A�]���L���i�H�̷ӳ̨α��ζi��վ�
        if (s[now][pos] == '@') return;

        for (int i = 0; i <= 4; i++){
            //�H�N i ���j�Ȫ�l�ơA�N���O i �Ÿ�
            dp[now][pos][i] = inf;
        }
        //�]���S���l�`�I�A�ҥH�Z�����s   
        dp[now][pos][0] = dp[now][pos][mp[s[now][pos]]] = 0;
        return;
    }
    //���l�`�I�ɡA�v�@�l�`�I���j (���O�P�@��m���r��)
    for (auto i:v[now]){
        f(i, pos);
    }
    int c = mp[s[now][pos]];
    //�� s[now][pos] ���O�U�Φr�� '@'
    if (c != 0){
        for (int i = 0; i <= 4; i++){
            //�H�N i ���j�Ȫ�l�ơA�N���O i �Ÿ�
            dp[now][pos][i] = inf;
        }
        dp[now][pos][c] = 0;
        for (auto i:v[now]){
            //�V�l�`�I�M��
            //min(dp[i][pos][0]+1... : ��Ӥl�`�I�� '@' �B�]��Ÿ����P�P��e
            dp[now][pos][c] += min(dp[i][pos][0]+1, dp[i][pos][c]);
        }
        //����K�p��A�N���]�� s[now][pos] �� '@' �ɪ��ȳ]���Ӧb�r���ɪ��̤p��
        dp[now][pos][0] = dp[now][pos][c];
        return;
    }
    for (c = 1; c <= 4; c++){
        for (auto i:v[now]){
            dp[now][pos][c] += min(dp[i][pos][0]+1, dp[i][pos][c]);
        }
    }
    //�N�U�Φr����w���@�㦳�̤p�Ȫ��r��
    dp[now][pos][0] = min(min(dp[now][pos][1], dp[now][pos][2]), min(dp[now][pos][3], dp[now][pos][4]));
}
 
int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        cin >> s[a];
        if (a == b) root = a;
        else v[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        //�@���u���j�@�Ӧr��
        f(root, i);
        ans += dp[root][i][0];
    }
    cout << ans << "\n";
}
/* 
    �̪�ڦۤv���Q�k�A���Ҽ{�S�̸`�I���v�T�F20��
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000+5;
const int MAX_M = 80+3;

int N, M, root;
struct node { int from, now; string s; vector<int> chl; };
struct F { int cnt[4] = {0}; };
node G[MAX_N];
char table[4] = {'A', 'U', 'C', 'G'};

void bfs() {
    int res = 0;
    queue<node> que;
    que.push(G[root]);
    while(!que.empty()) {
        node cur = que.front(); que.pop();
        if(cur.chl.empty()) continue;

        vector<int> chl = cur.chl;
        vector<F> freq(M);
        for(int i=0; i<chl.size(); i++) {
            for(int j=0; j<M; j++) {
                if(cur.s[j] == '@') {
                    if(G[chl[i]].s[j] == 'A') freq[j].cnt[0]++;
                    else if(G[chl[i]].s[j] == 'U') freq[j].cnt[1]++;
                    else if(G[chl[i]].s[j] == 'C') freq[j].cnt[2]++;
                    else if(G[chl[i]].s[j] == 'G') freq[j].cnt[3]++;
                }
                else if(cur.s[j] != G[chl[i]].s[j] && G[chl[i]].s[j] != '@')
                    res++;
            }
            que.push(G[chl[i]]);
        }

        for(int i=0; i<M; i++) {
            int MX = 0;
            int mx = 0;
            for(int j=0; j<4; j++) {
                res += freq[i].cnt[j];
                if(freq[i].cnt[j] > MX) {
                    MX = freq[i].cnt[j];
                    mx = j;
                }
            } 

            if(MX == 0) continue;

            res -= MX;
            G[cur.now].s[i] = table[mx];
            if(table[mx] != G[cur.from].s[i] && G[cur.from].s[i] != '@')
                res++;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int p, q;
        string s;
        cin >> p >> q >> s;
        if(p == q) root = p;
        else G[q].chl.push_back(p);
        G[p].s = s;
        G[p].from = q;
        G[p].now = p;
    }
    bfs();
    return 0;
}
*/