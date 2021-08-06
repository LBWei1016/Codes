/*
    線段樹：（參考 Segment_Tree_1）(0-indexed)
        這裡的優化在於可以在 O(log n) 的時間修改給定區間的值（原本是 O(n)）
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 50;

int N, Q;
int arr[MAX_N+1]; //儲存原數據

//[0, N)
struct Node
{
    ll add = 0; //該節點的區間的所有元素皆加上的值 (算在自己頭上的；已經給父，小孩在查詢時才給)
    ll sum = 0; //該節點的區間和，去除上述"add"的值 (子節點所累加的；小孩給的)
}node[1 << 6];

//一次修改給定區間的值
void add(int x, int y, int k, int v, int L, int R) //O(log n)
{
    if (x <= L && R <= y)
        node[v].add += k;
    else if (L < y && x < R) //有交集
    {
        node[v].sum += (min(y, R) - max(x, L)) * k; //只有交集之內的區間才加上要add的值

        int M = (L+R) / 2;
        add(x, y, k, 2*v+1, L, M);
        add(x, y, k, 2*v+2, M, R);
    }
}
//求區間和
ll sum(int x, int y, int v, int L, int R)
{
    if (y <= L || R <= x)
        return 0;
    else if (x <= L && R <= y)
        return node[v].add*(R-L) + node[v].sum; //整合
    else 
    {
        ll res = (min(y, R)-max(x, L)) * node[v].add; //讓子節點也加上add的值(只加交集的區間)

        int M = (L+R) / 2;
        res += sum(x, y, 2*v+1, L, M);
        res += sum(x, y, 2*v+2, M, R);
        return res;
    }
}
int main()
{
    printf("Input the size of arr:\n");
    scanf("%d", &N);
    printf("Input the values of arr:\n");
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    //樹的建構也可以用 add()
    for (int i=0; i<N; i++)
        add(i, i+1, arr[i], 0, 0, N);

    printf("Add value k between x and y:\n");
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    add(x-1, y, k, 0, 0, N);


    printf("Query the sum between x and y:\n");
    scanf("%d%d", &x, &y);
    ll res = sum(x-1, y, 0, 0, N);
    printf("%lld\n", res);

    return 0;
}