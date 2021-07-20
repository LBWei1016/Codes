/*
***Graph*** -- Maximum Independent Set
    Solution:
        �Y T �O�ڭ̭n�B�z����A��@�w�����A���] v �O�@�Ӹ��C�ڭ̫ź١G�@�w���@�ӳ̤j�W
        �߶��D��F v �ӨS���D�� parent(v)�C�ҩ��G���]�Y�̤j�W�߶� S �S���D�� v�A����
        �@�w���D parent(v)�A�_�h�i�H�N v �[�J S ���ܦ���j���W�߶��C�ڭ̥i�H�� v �I��
        �N S ���� parent(v)�o��t�~�@�ӿW�߶� S���A�N�O�ڭ̫ź٥]�t v ���̤j�W�߶��C
        �o�˪��������i��y�����X�k���ѡA�]�� v �I�O���l�Aparent(v)�O���ߤ@���F�~�C
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
int p[N], deg[N], mark[N];

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d", &p[i]);
        deg[p[i]]++;
    }

    queue<int> que;
    for(int i=1; i<n; i++) {
        if(deg[i] == 0) 
            que.push(i);
    }
    int res = 0; p[0] = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(!mark[v]) {
            mark[p[v]] = 1; 
            res++;
        }
        if(--deg[p[v]] == 0) {
            que.push(p[v]);
        }
    }
    printf("%d\n", res);
    return 0;
}