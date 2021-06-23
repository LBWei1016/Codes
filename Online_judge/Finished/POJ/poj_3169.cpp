/*
***Bellman-Ford***
(���o���Τ��廡��)
    �D��:
        �� N �Y���A�̧ǽs���� 1~N�A���������w�P�Q�������Y: �Y A ���w B�A�h d[A] - d[B] <= D�F
        �Y B �Q�� C�A�h d[B] - d[C] >= D'�C�D 1 �����P N �����������̤j�Z��(d[N] - d[1] = ?)
    ���: (�Ѧҹ�: ���Z���D��Ƭ��̵u���|���D)
        # �w���D�u�̤j�v���Z�A�ҥH:
        �@�B ���w���ɶq�Ի�
        �G�B �Q�����ɶq�a��!! ������??
            => ���]�Q�������ۻ����C�]���i�D�X�̤j���Z���ǦC�����A�u���۰Q���v���w�Q�u���۳��w�v
            �ҥ]��(�_�h�����N�i�H�L������)�A�]���Y�ϰ��]���ߡA�u���۰Q���v�������N���N�O��u����
            ���w�v���Ԫ�A��Y�N�� N �������e���ʡA(�]���� N �������w�Q�Y�����w�A�_�h���Z�N�L���j)
            �Ӵ�p�̤j���Z�C(�����I�i�ѦҹϨ÷Q���u��ӥd�g�v)
        �T�B �ѫe�z���I�H���D�ؤ������i���A�u���۳��w�v���Z���N�O D�F�u���۰Q���v���Z���N�O -D'�C
             �̦��i�N���D��Ƭ��u�Ϫ��̵u���|���D�v(�䪺�v���Τ�V�Ѧҹ�)
             (�Y��������O�i��F���A�h�]�v����0�A�åѫ���V�e)
        �|�B �]���i�঳�t���v���A�ҥH�ϥ� Bellman-Ford �ӫD Dijkstra
    ����: (������)
        4 2 1
        1 3 10
        2 4 20
        2 3 3
    O(N * (N + ML + MD))
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_ML 10001
#define MAX_N 1001
#define INF 1e9
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_ML], BD[MAX_ML], DD[MAX_ML];

int d[MAX_N]; //shortest path

void bellman_ford()
{
    fill(d, d + N, INF);
    d[0] = 0; //start from 0 to N-1

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i + 1 < N; i++) //set weight 0
        {
            if (d[i + 1] < INF)
                d[i] = min(d[i], d[i + 1]);
        }
        for (int i = 0; i < ML; i++) //like
        {
            if (d[AL[i] - 1] < INF)
                d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
        }
        for (int i = 0; i < MD; i++) //dislike
        {
            if (d[BD[i] - 1] < INF)
                d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
        }
    }
    int res = d[N - 1];
    if (d[0] < 0) //negative cyclic paths exist
        res = -1;
    else if (res == INF) //infinite distance
        res = -2;

    printf("%d\n", res);
}
int main()
{
    scanf("%d%d%d", &N, &ML, &MD);
    for (int i = 0; i < ML; i++)
        scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
    for (int i = 0; i < MD; i++)
        scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);

    bellman_ford();

    return 0;
}