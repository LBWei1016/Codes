/*
***Binary-Search***

    O(N)
*/
#include <cstdio>
#include <algorithm>

#define MAX_N 100000
#define INF 1e9

using namespace std;

int N, C;
int x[MAX_N+5];

bool Con(int d)
{
    int prev = 0;
    for(int i=1; i<C; i++) //put every cow into a proper stall
    {
        int curr = prev + 1;
        while(curr < N && x[curr] - x[prev] < d)
            curr++;
        if(curr == N) //curr should be in [0, N)
            return false;
        prev = curr;
    }
    return true;
}
int main()
{
    scanf("%d%d", &N, &C);
    for(int i=0; i<N; i++)
        scanf("%d", &x[i]);
    sort(x, x+N);

    int lb = 0, ub = 1e9+5;

    //binary search
    while(ub - lb > 1)
    {
        int mid = (ub + lb) / 2;
        if(Con(mid))
            lb = mid;
        else    
            ub = mid;
    }
    
    /*
        �Q���ѤU�̫�T�ӼƦr: 3, 4, 5�Flb = 3, ub = 5, mid = 4
        1. ���ɭY solve(mid) = true�A�h lb = 4, ub = 5�A�Y�N��
           4 �� true�A�]�����קY�� lb = 4�C
           ���]���ר� ub�A�p�G�u���O ub�A����b lb = 4, ub = 6�ɡA
           �N���Ө� lb = 5 �����פF�A�ҥH�� ub �����פ��X
        2. ���ɭY solve(mid) = false�A�h lb = 3, ub = 4�C
           �P�W�z�P�z

        �]�����ר� lb
    */
    printf("%d\n", lb);
    return 0;
}