/*
***String***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 100000+5;
bool isCap[MAX_S];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s;
    cin >> k >> s; 

    for(int i=0; i<s.size(); i++) {
        isCap[i] = (s[i] < 'a');
    }

    int ans = 0, cnt = 0;
    int step = 1; //�����o�O�ĴX�ӳs��ۦP�j�p�g���r��
    for(int i=1; i<s.size(); i++) {
        if(step == k) {
            step = 0;
            cnt++;
            ans = max(ans, cnt);
        }

        if(isCap[i] != isCap[i-1]) {
            //�P�e�@�r�����P�A�S���O�s���`�� -> ���_
            if(step > 0) { 
                ans = max(ans, cnt);
                cnt = 0;
            }
            //�s���`��
            step = 1;
        }
        else {
            //�P�e�@�r���ۦP�A�o�ӬO�s���}�l -> ���_
            if(step == 0) {
                if(cnt > 1) {
                    ans = max(ans, cnt);
                    cnt = 0;
                    step = 1;
                }
                else continue; //�Y�b�����e�S����L�w�������`���Fe.g. 2 aaaaAA
            }
            //���i�@�r��
            step++;
        }
    }
    //��̫�@�Ӧr����n�O�`��������
    if(step == k) {
        cnt++;
        ans = max(ans, cnt);
    }
    cout << ans * k << '\n';
    return 0;
}