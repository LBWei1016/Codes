/*
***Convex Hull*** 

    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_M = 5e4+5;
struct L { ll a, b; };
int n, m;
ll c[MAX_M];
vector<L> line;
vector<L> dq; //�s��i�Ϊ����u (�Y�])

bool comp(L &l1, L &l2) {
    return (l1.a == l2.a ? l1.b > l2.b : l1.a < l2.a);
}
inline ll f(L l, ll x) {
    return l.a * x + l.b;
}

int main() {
    scanf("%d%d", &n, &m);
    line.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld", &line[i].a, &line[i].b);
    }
    for(int i=0; i<m; i++) {
        scanf("%lld", &c[i]);
    }
    sort(line.begin(), line.end(), comp);
    sort(c, c+m);

    dq.push_back(line[0]);
    for(int i=1; i<n; i++) {
        L l = line[i];
        //���_�V�e�ˬd�A�O�_�i�H��s���u
        while(dq.size() > 1) {
            ll a1 = dq[dq.size()-2].a, b1 = dq[dq.size()-2].b;
            ll a2 = dq[dq.size()-1].a, b2 = dq[dq.size()-1].b;
            /*
                �P�_ l1, l �H�� l2, l �����I x �y�� (�e�Ϭݬ�)
                �p�ޥ�:
                    �N�쥻��̪� x �ȥ�e�ۭ��A�H�קK�B�I�ơF
                    �]���ײv a ���W�A�]���������A����������
            */
            if((b1 - l.b) * (l.a - a2) >= (b2 - l.b) * (l.a - a1)) {
                dq.pop_back(); //��� l2
            } else break;
        }
        dq.push_back(l);
    }
    ll res = 0;
    int p = 0, len = dq.size();
    for(int i=0; i<m; i++) {
        //��ն���
        while(p < len-1 && f(dq[p], c[i]) <= f(dq[p+1], c[i])) {
            p++;
        }
        res += f(dq[p], c[i]);
    }
    printf("%lld\n", res);
    return 0;
}