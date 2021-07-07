#include <iostream>
#include <algorithm>

using namespace std;

int arr[5] = {2, 5, 1, 9, 4}; //1, 2, 4, 5, 9
int n = 5;

void binary_search(int x)
{
    int lb = -1, ub = n; //(lb, ub] : �Y x �j��̤j�����A�h���׬� n�A�]���d��O�e�}�ᳬ

    //�b�ѵ��d��j�� 1 ���������а���
    while((ub-lb) > 1)
    {
        int mid = (ub+lb) / 2;

        //lower_bound
        //�Y�� "arr[k] > x" �h�� "upper_bound"(�]�����]�t�۵�)
        if(arr[mid] >= x)
            ub = mid;
        else 
            lb = mid;
    }
    //���� lb+1 = ub
    //�]���n�䪺�O arr[k] >= x�A�ҥH��ub
    cout << ub << '\n';
}

/* Sol II: jumping binary search */
int arr[100]; //sorted array

//search for "x"
int jump_search(int x) {
    //�] arr[0] �b���ᤣ�Q�ˬd�A�ҥH���ˬd
    if(arr[0] >= x) return 0;
    int p0 = 0;
    for(int jump=n/2; jump>0; jump/=2) {
        while(p0+jump<n && arr[p0+jump]<x) p0 += jump;
    }
    //arr[p0+1] >= x
    return p0+1;
}

int main()
{
    int x; //number to find
    cin >> x; 
    sort(arr, arr+5);
    binary_search(x);
    return 0;
}