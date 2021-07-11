/*
***Greedy***
    Solution:
        �ۦ��u�̤j���@�~�}�l�v�@�ˬd�A�ҩ��G
            �O d1 > d2�A�Y���� 1 �A�� 2�A�h 2 ���쪺�ɶ����O��j�A�i��L�k�����A
            �Ϥ��A1 �Y�ϸ��߰����I���p
    
    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

struct Task { int t, d; };
int T, n, t_sum;
vector<Task> v;

bool cmp(Task t1, Task t2) {
    return t1.d > t2.d;
}
bool finish() {
    for(int i=0; i<n; i++) {
        if(v[i].d < t_sum) {
            return false;
        }
        t_sum -= v[i].t;
    }
    return true;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        t_sum = 0;
        v.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i].t);
            t_sum += v[i].t;
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i].d);
        }
        sort(v.begin(), v.end(), cmp);
        if(finish()) puts("yes");
        else puts("no");
    }
    return 0;
}