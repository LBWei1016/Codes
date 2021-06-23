/*
    ����n�ѥk�����M��?�p�U:
        �]����: -1-9
        �Y�ѥ����k�M���A�L�{: 
            1. 0 - right
            2. 1 - 9 = -8 = right
            3. 0 - (-8) = 8 #
        �����׬O����!!!(�]���t�������D)�F
        �Y�ѥk�����A�L�{:
            1. left - 9
            2. 0 - 1 = -1 = left
            3. -1 - 9 = -10 #
        ���T!!!�קK�F�t�����D

    ����: �ѡu�k�v���u���v�A�~���T!!!
*/
#include <iostream>
#include <cctype>

using namespace std;

int DFS(int, int); // left, right
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(getline(cin, s))
    {
        int ans = DFS(0, s.size()-1);
        cout << ans << '\n';
    } 
    return 0;
}
int DFS(int left, int right) //�ѥk�������j!!!!!���n!!!!!!
{
    int par = 0; //�N��O�_�b�A����(0�N���b)
    //���j�����I�s�[��A�A�I�s�����A�]�������|�u���Q����(Stack: FILO)
    for(int i=right; i>=left; i--)
    {
        if(s[i] == ')') par++; //�]���ѥk�������j�A�ҥH���J��k�A���Fpar++�N���b�A����
        if(s[i] == '(') par--; // par--��par=0�A�N��A����������
        if(s[i] == '+' && par == 0)
            return DFS(left, i-1) + DFS(i+1, right); 
        if(s[i] == '-' && par == 0)
            return DFS(left, i-1) - DFS(i+1, right);
    }
    for(int i=right; i>=left; i--)
    {
        if(s[i] == ')') par++; //�]���ѥk�������j�A�ҥH���J��k�A���Fpar++�N���b�A����
        if(s[i] == '(') par--; // par--��par=0�A�N��A����������
        if(s[i] == '*' && par == 0)
            return DFS(left, i-1) * DFS(i+1, right);
        if(s[i] == '/' && par == 0)
            return DFS(left, i-1) / DFS(i+1, right);
        if(s[i] == '%' && par == 0)
            return DFS(left, i-1) % DFS(i+1, right);
    }

    if(s[left] == '(' && s[right] == ')') return DFS(left+1, right-1); //�h���A��
    if(s[left] == ' ' && s[right] == ' ') return DFS(left+1, right); //�h�����k�Ů�
    if(s[left] == ' ') return DFS(left+1, right); //�h�����Ů�
    if(s[right] == ' ') return DFS(left, right-1); //�h���k�Ů�

    int num = 0;
    if(isdigit(s[left]) && isdigit(s[right])) //�r����Ʀr
    {
        for(int i=left; i<=right; i++)
            num  = num*10 + s[i]-'0';
        return num;
    }
}
