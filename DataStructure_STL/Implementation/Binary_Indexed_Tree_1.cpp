/*
    Binary-Indexed-Tree(BTS)--�S�پ𪬼Ʋ�

    ��u�q�Ƨ�²�K���D���϶��M����Ƶ��c�]�ǥѫe��M�۴�^�F�ү�i�檺�ާ@�G
        1. �غc O(n logn) �� O(n)
        2. (���I)�W�[���ק�ƭ� O(log n) (�϶��ק﨣BIT_2)
        3. �p��e��M O(log n)
*/
#include <iostream>
#include <cstring>

using namespace std;

int bit[1000+1], n;
int arr[1000+1];

//(���I)�W�[���ק�ƭ�(O(log n))�A�P�ɥΨӫغc(O(n logn))BIT
void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
//�p��[1, i]���e��M(O(log n))
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
//�t�@�Ӹ��֪��غc��k(O(n))
void build()
{
    memcpy(bit+1, arr, n*sizeof(int));

    for(int i=1; i<=n; i++)
    {
        //j �O i(��i���`�I)���k�S�̸`�I
        int j = i + (i & -i); 
        bit[j] += bit[i];
    }
}

int main()
{
    n = 10;
    for(int i=0; i<n; i++)
        arr[i] = i+1;

    for (int i=1; i<=n; i++)
        add(i, arr[i-1]);
    //build();

    for(int i=1; i<=n; i++)
        cout << bit[i] << ' ';
    cout << '\n';
    for(int i=1; i<=n; i++)
        cout << sum(i) << ' ';
    return 0;
}