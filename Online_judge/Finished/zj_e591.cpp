/*
***Greedy***
*/
#include <bits/stdc++.h>

using namespace std;

int t, n;
int coin[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sum, cnt = 2; //���F�o��̤j�ȡA�̤j�M�̤p���w���@�w�|�Q�ϥ�
        for(int i=0; i<n; i++)
            cin >> coin[i];
        sum = coin[0];
        for(int i=1; i<n-1; i++) //���F�o��̤j�ȡA�̤j�M�̤p���w���@�w�|�Q�ϥ�
        {
            //��h:�v�@�˵��U���ȡA�Ѥp��j(�u�ݭ�n�֦��U���Ȫ����B�A�]���h�l�����O�L�N�q��)�A
            //���ۭY�ثe���B >= �U�@�ӹ��ȡA�h�����Q�N�����Ӹ��j���w��(����cnt������֡A�]����
            //���j�w���u���N��L�y�p�����ӵw���A�]��cnt����)
            if(sum + coin[i] < coin[i+1])
            {
                sum += coin[i];
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}