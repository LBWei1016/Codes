/*
***Josephus problem***

    Description:
        ����Ұ��D�����s�A�D�� K ��Q�������H���w�����U�@��A�Y�u���B���H�v
    
    Solution:�]0-indexed ����K�^
        �Y�ϥΦ�C�����A�����װ��]�{���X�b�U��^�C�t�@�Ѫk�p�U�G
            �� N �H�򦨤@��A�C M �H�@�ơA�C���Q�����H�s�����G(M-1) mod N�C
            ���]�̫�s���̪��s���� f(N)�C��s�� M-1 ���H�Q����A���Ѿl�� N-1 �H���s�s���p�U�G
                M -> 0
                M+1 -> 1
                ...
                0 -> N-M
                ...
                M-3 -> N-3
                M-2 -> N-2
            �h��� N-�����s���� f(N) = (f(N-1) + M) mod N�A�H�������A�� f(1) = 0�C
            �]�յ۵e�Ϭݬݡ^�]���j���ѤW�z�b�Y�k�詹����f�B��Y�i�o�X�^

            �ӡu�� K ��Q�����H�v�Y���GN-(K-1) �H�򦨤@��ɡA
            �Ĥ@��Q�����H�A��s���G(M-1) mod N-(K-1)�A�A�ѤW�z���ɤ����j���Y�i��X
            �� K ��Q�����H�b N �H�򦨤@��ɪ��s���C

            ���D�ҨD�����B�̡A���N�O����j�p���@N-(K-1) �H�ɡA�Ĥ@��Q�����H���U�@��A
            ���U�s���Y�� (M-1 + 1) mod N-(K-1) = M mod N-K+1�A�A�̤W�z��k�^���Y�i�D�ѡC
    
    O(K)
*/
#include <bits/stdc++.h>

using namespace std;

int N, M, K;

void josephus_k() {
    // int Nk = N - (K-1);
    // int luc = (M-1+1) % Nk;
    // for(int i=Nk+1; i<=N; i++) {
    //     luc = (luc + M) % i;
    // }
    int luc = 0;
    for(int i=N-K+1; i<=N; i++) {
        luc = (luc + M) % i;
    }
    cout << luc+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    josephus_k();
    
    return 0;
}
/*
void simulation() {
    queue<int> que;
    for(int i=1; i<=N; i++) {
        que.push(i);
    }

    int k = 0, m = 0;
    while(true) {
        for(int i=0; i<que.size(); i++) {
            int t = que.front(); que.pop();
            m++;
            if(m != M) que.push(t);
            else {
                k++;
                m = 0;
                if(k == K) {
                    cout << que.front() << '\n';
                    return;
                }
            }
        }
    }
}
*/