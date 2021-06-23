/*
***Greedy***
*/
#include <bits/stdc++.h>

using namespace std;

#define N 100001
typedef pair<int, int> pii;
int T, M;
vector<pii> coor, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while(T--)
    {
        coor.resize(N);
        ans.resize(N);
        cin >> M;
        int l, r;
        int num = 0; //number of coordinates
        for(int i=0; cin >> l >> r; i++)
        {
            if(l == 0 && r == 0)
                break;
            coor[i].first = l,
            coor[i].second = r;
            num++;
        }
        sort(coor.begin(), coor.begin()+num); //�Ѥp��j��(�H���Ȭ���)

        int left = 0, right = 0; //�ҭn�]�t�����B�k��
        int flag = -1; //�O�����e�@�I
        int cnt = 0; //�@�ݴX�I
        bool found = false; //�O�_����
        while(right < M) 
        {   
            int j;
            //�۳̥��}�l�A����j�����Ȥp(��)�󥪬ɡA�B���̤j�k�Ȫ��I
            for(j=flag+1, flag=-1; coor[j].first <= left && j<num; j++)
            {
                if(coor[j].second > right)
                {
                    flag = j;
                    right = coor[j].second;
                }   
            }
            left = right; //�쥻���k���ܦ��U�@�I������
            ans[cnt].first = coor[flag].first,
            ans[cnt].second = coor[flag].second;
            cnt++;

            if(flag == -1)
                break;
            if(right >= M)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            cout << cnt << "\n";
            for(int i=0; i<cnt; i++)
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            cout << '\n';
        }
        else
            cout << "0\n\n";
    }
    return 0;
}