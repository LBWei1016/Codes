#include <bits/stdc++.h>

using namespace std;

int arr[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, sum = 0;
        int max = -10000000; //�Nmax�H���p�ƪ�l��
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=0; i<n; i++)
        {
            if(sum < 0) //��e�����M<0�A�N�k�s�A�Y�q�ۤv�}�l��
                sum = 0;
            sum += arr[i];
            if(sum > max)
                max = sum;
        }
        cout << max << '\n';
    }
    return 0;
}