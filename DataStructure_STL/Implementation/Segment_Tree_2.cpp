/*
    �u�q��G�]�Ѧ� Segment_Tree_1�^(0-indexed)
        �o�̪��u�Ʀb��i�H�b O(log n) ���ɶ��קﵹ�w�϶����ȡ]�쥻�O O(n)�^
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 500000;

int N, Q;
int arr[MAX_N+1]; //�x�s��ƾ�

struct Node
{
    ll add = 0; //�Ӹ`�I���϶����Ҧ������ҥ[�W����
    ll sum = 0; //�Ӹ`�I���϶��M�A�h���W�z"add"����
}node[(1 << 20)+1];

//�@���קﵹ�w�϶�����
void add(int x, int y, int k, int v, int L, int R) //O(log n)
{
    if (x <= L && R <= y)
        node[v].add += k;
    else if (L < y && x < R) //���涰
    {
        node[v].sum += (min(y, R) - max(x, L)) * k; //�u���涰�������϶��~�[�W�nadd����

        int M = (L+R) / 2;
        add(x, y, k, 2*v+1, L, M);
        add(x, y, k, 2*v+2, M, R);
    }
}
//�D�϶��M
ll sum(int x, int y, int v, int L, int R)
{
    if (y <= L || R <= x)
        return 0;
    else if (x <= L && R <= y)
        return node[v].add*(R-L) + node[v].sum; //��X
    else 
    {
        ll res = (min(y, R)-max(x, L)) * node[v].add; //���l�`�I�]�[�Wadd����(�u�[�涰���϶�)

        int M = (L+R) / 2;
        res += sum(x, y, 2*v+1, L, M);
        res += sum(x, y, 2*v+2, M, R);
        return res;
    }
}
int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    int Q;
    scanf("%d", &Q);

    //�𪺫غc�]�i�H�� add()
    for (int i=0; i<N; i++)
        add(i, i+1, arr[i], 0, 0, N);

    while (Q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1) //[x, y]�Ҧ��ȬҼW�[k
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            add(x-1, y, k, 0, 0, N);
        }
        else //query
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ll res = sum(x-1, y, 0, 0, N);
            printf("%lld\n", res);
        }
    }
    return 0;
}