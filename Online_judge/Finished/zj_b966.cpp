/*
****Sort*** --acknowledgement: https://yuihuang.com/zj-b966/
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N, L, R;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        //��u�q���}�l���I�M�������I�����W�ߪ�evnet
        //�b�u�q���}�l���IL�B�Aevent +1
        v.push_back({L, 1});
        //�b�u�q���������IR�B�Aevent -1
        v.push_back({R, -1});
    }
    sort(v.begin(), v.end());

    //now���V�ثe�˵���event

    int now = 0, event = 0, ans = 0;
    for (int i = 0; i <= 1e7; i++) {
        while (now < (int)v.size() && v[now].first == i) {
            event += v[now].second;
            now++;
        }
        //���s���d�򥪺ݥX�{�Aevent++�F���Y�d�򪺥k�ݥX�{�A�N��ӽd�򵲧��Aevent--
        //�Y event > 0�A�N��ثe���b�Y�q�d�򤧤�(�٨S�IĲ��k�ݦӵ���)
        if (event > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}