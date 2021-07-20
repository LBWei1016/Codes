/*
***DP*** -- weighted LIS
    Solution:
        ���̷� c �Ѥj��p�Ƨ� (m �]�i�H)�A�M��̷Ӧ����Ǧb�ʺA����Ƶ��c����
        ��e m �b���p����e�� m �����p�U (�]�� c �w�g����e���@�����p)�A�W�[�v���C
        ���p m �j���v���p�A�o�i��O�p�A�n�N�䲾���A�]���ӰʺA����Ƶ��c�㦳��թ�
        (m �V�j P �V�j)
    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct Mem { int p, c, m; } seq[N];
int n;

bool cmp(Mem m1, Mem m2) {
    return (m1.c == m2.c ? m1.m < m2.m : m1.c > m2.c);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].p);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].c);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].m);
    }
    sort(seq, seq+n, cmp);

    map<int, int> M; //(m, P), increasing 
    M.insert({-1, 0}); //boundary
    //�q��� c ���A�� m �b���H�ϭ�����p�U�̤j���v��
    for(int i=0; i<n; i++) {
        auto it = M.upper_bound(seq[i].m);
        it--; //seq[i] �i�H���W���a�� (it->first < seq[i].m)
        int w = it->second + seq[i].p;
        it = M.insert(it, {seq[i].m, w}); //���J���ѦӥB��e�v������
        if(it->second < w) {
            it->second = w;
        }
        it++;
        //�������W����թ�
        while(it!=M.end() && it->second<=w) {
            it = M.erase(it);
        }
    }
    auto it = M.end(); it--;
    printf("%d\n", it->second);
    return 0;
}