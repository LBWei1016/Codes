/*
***Topology***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> G[n]; //adjacent list
    int indegree[n] = {0}; //�J�����
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        indegree[v]++;
    }
    int topo[N], head = 0, tail = 0; //queue
    for(int i=0; i<n; i++) {
        //�S���H�b�ۤv�e���F
        if(indegree[i] == 0) {
            topo[tail++] = i; //push
        }
    }
    //���H�� indegree �O 0 
    while(head < tail) {
        int u = topo[head++]; //pop
        for(int v : G[u]) {
            if(--indegree[v] == 0) {
                topo[tail++] = v;
            }
        }
    }

    //�����A�ҥH�õL�k�������I�ҹF�� indgree = 0
    if(tail < n) 
        printf("Not a DAG"); 
    else {
        for(int i=0; i<n; i++) {
            printf("%d%c", topo[i], i==n-1 ? '\n' : ' ');
        }
    }   
    return 0;
}