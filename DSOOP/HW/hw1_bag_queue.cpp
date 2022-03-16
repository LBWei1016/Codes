#include <iostream>
#include "hw1_bag_queue.h"
using namespace std;

int main() {
    int cap = 10;
    // Queue<int> que(cap);
    // for (int i=0; i<cap; ++i) {
    //     que.Push(i);
    //     // printf("\n size: %d\n", que.Size());
    // }
    // for (int i=0; i<cap/2; ++i) {
    //     cout << que.Element() << ' ';
    //     que.Pop();
    //     // printf("\n size: %d\n", que.Size());
    // }
    // printf("\noriginal size: %d\n", que.Size());
    // que.Push(100);
    // printf("now size: %d\n", que.Size());
    // while (!que.IsEmpty()) {
    //     printf("element: %d\n", que.Element());
    //     que.Pop();
    // }
    // printf("exceeded: %d\n", que.Element());

    Queue<double> que(0);
    for (int i=0; i<cap; ++i) {
        que.Push((double)i + 0.1);
    }
    for (int i=0; i<cap/2; ++i) {
        cout << que.Element() << ' ';
        que.Pop();
        // printf("\n size: %d\n", que.Size());
    }
    printf("\noriginal size: %d\n", que.Size());
    que.Push(100.0);
    printf("now size: %d\n", que.Size());
    while (!que.IsEmpty()) {
        printf("element: %lf\n", que.Element());
        que.Pop();
    }
    printf("exceeded: %lf\n", que.Element());
    return 0;
}