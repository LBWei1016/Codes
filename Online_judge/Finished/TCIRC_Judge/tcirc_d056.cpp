/*
***Sweep Line***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int n;
multimap<int, int> pre; //(y, x)�F���誺�I
vector<P> ps; //�I���X

bool cmp(P p1, P p2) {
    return p1.x < p2.x;
}
int main() {
    scanf("%d", &n);
    ps.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    sort(ps.begin(), ps.end(), cmp);
    int min_d = 1e9; 
    //�ѥ��ӥk���y
    for(int i=0; i<n; i++) {
        int x = ps[i].x, y = ps[i].y;
        //�̵u�Z�������̤p y �y��
        auto it = pre.lower_bound(y - min_d);
        //�̵u�Z�������̤j y �y�� (while �̦h���� 8 ��)
        while(it!=pre.end() && it->first <= y+min_d) {
            //x �y�жW�X�̤p�Z���A���|�A�Ψ�
            if(it->second < x - min_d) {
                it = pre.erase(it);
                continue;
            }
            min_d = min(min_d, abs(x-it->second) + abs(y-it->first));
            it++;
        }
        pre.insert({y, x});
    }
    printf("%d\n", min_d);
    return 0;
}