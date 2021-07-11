/*
***Sweep Line***
    Solution:
        �ۥk�ӥ��A�]�q�k��ӡA�ҥH x �y�Фw������A�A�ӴN�u�ݭn�ˬd
        y �y�ЬO�_�j��ثe�̤j��(���Q����)

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P {int x, y; } ;
bool cmp(P &p1, P &p2) {
    return p1.x > p2.x;
}
int main() {
    int n;
    scanf("%d" ,&n);
    vector<P> p(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i].x);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i].y);
    }
    //x ����
    sort(p.begin(), p.end(), cmp);
    int res = 0, max_y = -1;
    for(auto i : p) {
        int y = i.y;
        if(y > max_y) {
            res++;
            max_y = y;
        }
    }
    printf("%d\n", res);
    return 0;
}