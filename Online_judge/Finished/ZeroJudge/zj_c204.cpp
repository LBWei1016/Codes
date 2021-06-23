/*
***Prime*** --UVa13194
    Description:
        ��X�]�ƩM(���]�t�ۤv)����ۤv����(perfect)
    Solution:
        1. �ؽ�ƪ�
        2. sqrt(N) ��]�Ƥ���
        3. ����ż� (�קK owerflow)

    O(sqrt(N))
*/
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAX_N = 1e6+1;
struct factor { ll p, cnt; };

ll N;
bool is_prime[MAX_N];
vector<int> primes;
vector<factor> v; //N's factors except N itself

//sieve of Eratosthenes
void sieve() {
    for(int i=2; i<MAX_N; i++)
        is_prime[i] = true;

    int cnt = 0;
    for(int i=2; i<MAX_N; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=2*i; j<MAX_N; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    ll n = N;
    //�N N ��]�Ƥ��ѡA�u�ݨ� sqrt(N)
    for(int i=0; n>1 && primes[i]<sqrt(N); i++) {
        if(n % primes[i] == 0) {
            int cnt = 0;
            for(; n%primes[i] == 0; cnt++) 
                n /= (ll)primes[i];
            v.push_back((factor){primes[i], cnt});
        }
    }
    //�Y N �٨S�Q�������ѡA���ѤU���]�Ƥ@�w�O��ơA�åB�n�ư� N ����ƪ�����
    if(n != 1 && v.size() != 0)
        v.push_back((factor){n, 1});

    ll res = 1;
    for(int i=0; i<v.size(); i++) {
        if(v[i].cnt == 1) //�קK owerflow
            res *= (v[i].p + 1);
        else 
            res *= (pow(v[i].p, v[i].cnt+1) - 1) / (v[i].p - 1); //����ż�
    }
    res -= N;
    if(res == N) {
        printf("perfect\n");
    } 
    else if(res < N) {
        printf("deficient\n");
    }
    else {
        printf("abundant\n");
    }
}

int main() { 
    sieve();
    int t;
    scanf("%d", &t);
    while(t--) {
        v.clear();
        scanf("%lld", &N);
        solve();
    }
    
    return 0;
}