/*
***BIT*** 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 100000+5;
int bit[2 * MAX_N]; //bit[i]: �Y�� 1�A�N��X�{�L�F�Ϥ��h�D
int L[MAX_N], R[MAX_N]; //L[i], R[i]: �Ʀr i �Ĥ@���M�ĤG���X�{����m
int n;
//1-indexed
void bit_add(int i, int x) {
    while(i <= 2*n) {
        bit[i] += x;
        i += i & -i;
    }
}
ll bit_sum(int i) {
    ll res = 0;
    while(i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=2*n; i++) {
        int t;
        cin >> t;
        if(L[t] == 0) L[t] = i;
        else R[t] = i;
    }

    ll res = 0;
    //�Ѥp��j
    for(int i=1; i<=n; i++) {
        //�e��M�A1 �N��X�{�L
        res += bit_sum(R[i]) - bit_sum(L[i]);
        //�N��Ʀr i �w�X�{�L
        bit_add(L[i], 1);
        bit_add(R[i], 1);
    }
    cout << res << '\n';
    
    return 0;
}