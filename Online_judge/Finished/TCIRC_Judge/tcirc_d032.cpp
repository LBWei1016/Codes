/*
***Deque***
*/
#include <bits/stdc++.h>
using namespace std;

int N, L;
int arr[200005];
deque<int> max_q, min_q; //index

void put_max(int i) {
    //�q��ݥ[�J�A�۷��϶��V�k��
    //�Y�b i ���e�A���p�� arr[i] ���ȡA����L�̦b arr[i] ���}���e���i��O
    //�̤j�ȡA�]�������˱�
    while(!max_q.empty() && arr[max_q.back()] <= arr[i])
        max_q.pop_back();
    max_q.push_back(i);
}
void put_min(int i) {
    while(!min_q.empty() && arr[min_q.back()] >= arr[i])
        min_q.pop_back();
    min_q.push_back(i);
}

int main() {
    scanf("%d%d", &N, &L);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    max_q.push_back(0);
    min_q.push_back(0);
    int res = 0;
    for(int i=1; i<N; i++) {
        if(max_q.front() <= i-L) //i-max_q.front()+1 > L => out of range
            max_q.pop_front();
        put_max(i);
        if(min_q.front() <= i-L)    
            min_q.pop_front();
        put_min(i);
        int diff = arr[max_q.front()] - arr[min_q.front()];
        res = max(res, diff);
    }
    printf("%d\n", res);
    return 0;
}