/*
***Josephus problem***

    Description:
        �D�̫᪺�s���̡C

        �i���G�D�� k ��Q�����H

    Solution: (0-indexed)
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

    �i���G
        �� N �H�򦨤@��A�C M �H�@�ơA�� k ��Q�����H�Y���GN-(k-1) �H�򦨤@��ɡA
        �Ĥ@��Q�����H�A��s���G(M-1) mod N-(k-1)�A�A�ѤW�z���ɤ����j���Y�i��X
        �� k ��Q�����H�b N �H�򦨤@��ɪ��s���C

    O(N) / O(K)
*/
#include <iostream>

using namespace std;

const int MAX_N = 100;

int N, M, K;
int dp[MAX_N];

//0-indexed
//O(N)
void josephus() {
    dp[0] = dp[1] = 0;
    for(int i=2; i<=N; i++) {
        dp[i] = (dp[i-1] + M) % i;
    }
    //1-indexed
    for(int i=1; i<=N; i++) {
        printf("Kill %d: %d\n", i-1, dp[i]+1);
    }
}
//O(K)
void josephus_k_th() {
    int Nk = N - (K-1);
    int k_th = (M-1) % Nk;
    for(int i=Nk+1; i<=N; i++) {
        k_th = (k_th + M) % i;
    }
    /* 
        For more concise:
            int k_th = -1;
            for(int i=N-K+1; i<=N; i++) {
                k_th = (k_th + M) % i;
            }
    */
    cout << k_th+1 << '\n';
}

int main() {
    cout << "Input how many people in a circle, and the count to kill:\n";
    cin >> N >> M;
    
    cout << "The survivors are:\n";
    josephus();

    cout << "Input the K-th person to die:\n";
    cin >> K;
    josephus_k_th();
    
    return 0;
}