#include <bits/stdc++.h>

using namespace std;

int m, n, t;
int col[1000], row[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--)
    {
        int sum = 0;
        cin >> m >> n;
        for(int i=0; i<m; i++)
            cin >> col[i];
        for(int i=0; i<n; i++)
            cin >> row[i];
        //�����ƦC�A���F�u�����O�w�h���h��P
        sort(col, col+m, greater<int>());
        sort(row, row+n, greater<int>());

        for(int i=0; i<n; i++) //�T�w--�C
        {
            for(int j=0; j<m && col[j] && row[i]; j++) //��B�C���۩��
            {
                col[j]--;
                row[i]--;
                sum++;
            }
            sum += row[i]; //�C--�S�Q��P��
            sort(col, col+m, greater<int>()); //�����ƦC�A���F�u�����O�w�h���h��P�A�_�h�N�|�S��P�Ӫ�������"sum += row[i]"�A�]�Ӱ�������
        }
        for(int i=0; i<m; i++)
        {
            sum += col[i]; //��--�S�Q��P��
        }
        cout << sum << '\n';
    }
    return 0;
}