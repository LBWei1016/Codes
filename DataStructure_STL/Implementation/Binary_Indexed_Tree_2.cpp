/*
    Binary-Indexed-Tree(BTS)--�S�پ𪬼Ʋ� (�Ѧ�BIT_1)

    �Q�Ψ��� BIT �ӹF��H O(log n) �������׭ק�϶���
*/
#include <iostream>

using namespace std;

int arr[101];
int bit0[101]; //�쥻��BIT
int bit1[101]; //�u�O���ק�Ȫ�BIT
int n;

void add(int *bit, int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int sum (int *bit, int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void modify(int L, int R, int x)
{
    add(bit0, L, -x*(L-1));
    add(bit1, L, x);
    add(bit0, R+1, x*R);
    add(bit1, R+1, -x);
}
void query(int L, int R)
{
    int res = 0;
    res += sum(bit0, R) + sum(bit1, R) * R;
    res -= sum(bit0, L-1) + sum(bit1, L-1) * (L-1);
    
    cout << "Sum is: " << res << '\n';
}

int main()
{
    cout << "Input size of array: \n";
    cin >> n;
    cout << "Input value of array: \n";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=n; i++)
        add(bit0, i, arr[i-1]);

    cout << "Input the block to be modified: \n";

    int l, r, x;
    cin >> l >> r >> x;

    modify(l, r, x);

    cout << "Input the block to query: (L, R, x)\n";
    cin >> l >> r;
    query(l, r);
    return 0;
}