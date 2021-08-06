/*
***Graph*** -- Shortest path
���z:
    Floyd-Warshall �ܦn�g�A���O�ݰ_�Ӧb�}���ϤW�A�] V �� Dijkstra �� O(V E log V ) �|
��n�@�I�A�M�� Dijkstra �u��Φb�D�t�v�ϤW�C��O�A�o�Ӻt��k���ت��N�O��a�t�v��
���ܦ����v�ϡC
�@�@�ҨϥΪ���k�A�O���C�@���I�[�W�@���I�v H(i)�A�åB�O�Ҧ��䪺�s�v���A������v���[�W�_�I
���I�v�B����I���I�v�C�����ҩ��o�ӽվ����v���@�k����өʽ�G
1. �P�@�I�� (S, T) ���̵u���| P(A, B) �ä��|���ܡA���v���|�[�W H(S) ? H(T)�C
2. ���������v���������ܡC
�@�@�]���o�O�@�Ө}�n���վ����v�@�k�C���n�p�����C�����v���ܬ��D�t�O�H�ڭ̥��C�X���l�G
        w(i, j) + H(i) ? H(j) ? 0, ?(i, j) ? E
�@�@�M�Ჾ�Ӷ��G
        H(i) + w(i, j) ? H(j)
�@�@���S���������ѡH�ٰO�o�ڭ̤��e���P��������O d(i) + w(i, j) < d(j)�A�Y�O
H(i) = d(i)�A�W���N���O�u����A�i���P���v�A�]�N�O�����@�ճ��I���̵u���|���ѳ�
�O�ŦX�����I�v�C�ܦ��o�Ӻt��k�j�P���ΡG����@�I�� Bellman-Ford�]���K�P�_���S
���t���^�A�o���I�v����A�νվ㧹�����v�� V �� Dijkstra�A�ɶ������� O(V E log V )�A�b���}��
���ϤW��{�|�� Floyd-Warshall �n�C
�@�@�M���٦��@�Ӥp���D�C�e�������L�A��Ϭ����V�Ϫ��ɭԡA�@���M�����i��L�k�M
�������ϡA�]�N�O���i��|�o�ͦ��I�S���I�v�����p�]�]���䤣��̵u���^�C�o�Ӱ��D��
�n�ѨM�G�s�W�@���I�A�����s��Ҧ��I�A�åB���v���O 0�A�A��o���I�� Bellman-Ford �Y
�i�C

�p��:
    ���I��̵u���|�A����@���淽�̵u���| (Bellman-Ford)�A�ñN�q�_�I����N�I���̵u�Z���@���U�۪�
    �I�v�A�ӭק�쥻�����v�A�h������t�v��N >= 0�C�]�� dijkatra �N�i�H�ΤF !!!
    O(V*E*log V)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    return 0;
}