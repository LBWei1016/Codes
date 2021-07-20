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
int p[N], chosen[N];
vector<int> chl[N];

int dfs(int v) {
    int num = 0;
    for(int u : chl[v]) {
        num += dfs(u);
    }
    //�q���}�l�D��A�ñN�� parent �����D��
    if(chosen[v]) {
        num += 1;
        chosen[p[v]] = 0;
    }
    return num;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d", &p[i]);
        chl[p[i]].push_back(i);
        chosen[i] = 1; //�w�]�ҿ�
    }
    chosen[0] = 1; p[0] = n; //0 �� parent �]���@���i�ध��
    printf("%d\n", dfs(0));
    return 0;
}