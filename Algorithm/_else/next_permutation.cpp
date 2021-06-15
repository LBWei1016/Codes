//next_permutation: �̦r�嶶�ǦC�|�Ҧ����A(�@n!�Ӫ��A)
//�Q�έ�}�C�i��ާ@
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    clock_t s, e;
    vector<int> v = {0, 2, 1, 3, 4, 5};
    sort(v.begin(), v.end()); //before calling next_permutation, vector should be sorted!!
    int cnt = 0;
    s = clock();
    do
    {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
        cnt++;
    }while(next_permutation(v.begin(), v.end()));
    e = clock();
    cout << "n! = " << cnt << '\n';
    cout << "Time spent: " << e-s << " ms\n";
    
    return 0;
}