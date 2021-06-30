/*
    �u�q��G (1-indexed)
        �ӥѸԨ��t��k���O�]http://web.ntnu.edu.tw/~algo/Sequence2.html#3�^

        �@���G���𵲺c�A�u�q�𪺨C�@�`�I�x�s���_�Q�G�����϶��G
        �ڵ��I�]�t��Ӱ϶��A�Ӹ��`�I�h�ȥ]�t�@�ӼƭȡF����H 
        O(log n) �������׬d��: �]���G��l�Ƭ� O(n)�^
            1. ���N���w�϶����̤j�]�p�^�ȡA�Y RMQ(Range Minimum Query) ����
            2. ���N���w�϶����M
            3. �ק���N�϶����̤j�]�p�^�ȡB�M�]���I��s�^
            �]�h�I��s�Ԩ� Segment_Tree_2�^
        �b��@�W�A�Y�N�u�q��ظm�������G����A����ާ@�N����K�F�x�s�覡�i�H��
        �¨ϥΰ}�C�ηf�t���гs���C
*/
#include <iostream>

using namespace std;

const int MAX_N = 1 << 17;
const int INF = 1e9;
int N, n; //n = 2^k >= N
int dat[MAX_N]; //�@�Ӱ϶�
int node[2*MAX_N+1]; //dat �϶����u�q��

//��K���Τl�`�I
int LC(int v) {return 2 * v;}
int RC(int v) {return 2 * v + 1;}

void init() //O(n)
{
    n = 1; //n = 2^k >= N
    while (n < N)
        n *= 2;
    for (int i=1; i<=2*n-1; i++)
        node[i] = INF; //�D�̤p�ȮɡA��l�Ƭ�INF�F�Y�D�̤j�ȫh�O(-INF)
}
void build(int v, int L, int R) //�غc�u�q�� O(n)
{
    if (L == R) //[L, R]
    {
        node[v] = dat[L];
        return;
    }

    int M = (L+R) / 2;
    build(LC(v), L, M);
    build(RC(v), M+1, R);

    node[v] = min(node[LC(v)], node[RC(v)]);
}
void update(int v, int val) //��s dat[v] ���Ȭ� val (���I��s) O(log n)
{
    v += n - 1; //�q���}�l��s
    dat[v] = val;

    while (v > 0)
    {
        v /= 2; //���^���`�I
        dat[v] = min(dat[LC(v)], dat[RC(v)]);
    }
}
int query(int l, int r, int v, int L, int R) //�d��[l, r]���̤p�� O(log n)
{
    if (l > R || r < L) return INF;
    if (L <= l && r <= R) return dat[v];
    else 
    {
        int M = (L+R) / 2;
        if (r < L)
            return query(l, r, LC(v), L, M);
        else if (l > M)
            return query(l, r, RC(v), M+1, R);
        else
        {
            int s1 = query(l, r, LC(v), L, M);
            int s2 = query(l, r, RC(v), M+1, R);

            return min(s1, s2);
        }
    }
}
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> dat[i];
    init();
    build(1, 1, N);
    update(3, 23);

    int l, r;
    cin >> l >> r;
    query(l, r, 1, 1, N);
    return 0;
}