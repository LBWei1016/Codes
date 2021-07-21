//next_permutation: �̦r�嶶�� (�p��j)�C�|�Ҧ����A(�@n!�Ӫ��A)
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
    // to ensure full permutation, sort first
    sort(v.begin(), v.end());
    int cnt = 0;
    s = clock();
    do
    {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
        cnt++;
    } while(next_permutation(v.begin(), v.end())); // increase lexicographically
    e = clock();
    cout << "n! = " << cnt << '\n';
    cout << "Time spent: " << e-s << " ms\n";

    reverse(v.begin(), v.end());
    do {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
    } while(prev_permutation(v.begin(), v.end())); // decrease lexicographically
    
    return 0;
}