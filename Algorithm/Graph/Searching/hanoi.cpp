#include <cstdio>

using namespace std;

int cnt = 0;
void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("%d: Move from %c to %c\n", ++cnt, A, C);
    }
    else
    {
        hanoi(n-1, A, C, B); //�en-1�Ӹ��p���L�l
        hanoi(1, A, B, C); //��n�ӳ̤j���L�l
        hanoi(n-1, B, A, C); //�en-1�Ӹ��p���L�l
    }
    
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    printf("�п�J�L��: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}