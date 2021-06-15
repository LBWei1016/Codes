/*
    �Q��BIT�p��G�N�@�ƦC(1 ~ n)�HBubble Sort�ɾ��ƦC�ɩһݪ��洫����
    (�Y��¨ϥμ����h��O(n * n))

    O(n * log n)
*/
#include <iostream>

using namespace std;

int n, arr[101];
int bit[101];

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int sum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

void solve()
{
    int ans = 0;
    for (int j=0; j<n; j++)
    {
        /*
            �O�_�n�洫�ѫ᭱���Ʀr�M�w�F
            sum(arr[j])�N��barr[j]���e�w�g���h�֤�arr[j]�p���Ʀr�X�{�L�A
            �ӳo�ǬO���ݭn�洫���A�ҥHans += j - sum(arr[j])
        */
        ans += j - sum(arr[j]);

        //�N��arr[j]�o�ӼƦr�w�g�Q�ιL
        
        add(arr[j], 1);
    }
    cout << ans << '\n';
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
}