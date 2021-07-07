/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct S { ll h, pos; }; //height, pos
vector<S> B; //�תO�������X
ll ans[100005]; //�̲פ��q

bool comp(const S &s1, const S &s2) {
    return s1.h < s2.h;
}
/*
    �b�϶� [left, right) �H���Ҭ��Ť��ѡA�H�~���w�g��L�εL�k�񪺤���
*/
void rec(int left, int right, ll w, int in) {
    //�ȳѤ@���ѡA�����񺡡A����
    if(left+1 == right) {
        ans[left] = w;
        return;
    }
    //��X�̰����O�l
    while(true) {
        S b = B.back();
        /*
            �Y�ӪO�l���b�϶����A�N�������A�]���϶��O�v���Y�p�A
            �ҥH�b�϶��~������(�O�l)�w�g���|�A�Q�Q�ΡC
        */
        if(b.pos >= right || b.pos <= left) {
            B.pop_back();
        } else break;
    }
    S highest = B.back();
    ll H = highest.h, P = highest.pos;
    //�Y��e�����q���H�񺡩Ҧ��϶��������ѡA�N���������t
    if(w >= (right-left)*H) {
        ll avg = w / (right-left);
        for(int i=left; i<right; i++) {
            ans[i] = avg;
        }
        return;
    }
    //��`�J�I�b�ثe�̰����O�l������
    if(P > in) {
        //���X
        if(w > (P-left)*H) {
            for(int i=left; i<P; i++) {
                ans[i] = H;
            }
            //�Y�p�϶��A��h���q
            rec(P, right, w-(P-left)*H, in);
            return;
        } else {
            //�����X�A�Y�p�϶��A���q����
            rec(left, P, w, in);
            return;
        }
    } else {
        //��`�J�I�b�ثe�̰����O�l������
        //���X
        if(w > (right-P)*H) {
            for(int i=P; i<right; i++) {
                ans[i] = H;
            }
            rec(left, P, w-(right-P)*H, in);
            return;
        } else {
            rec(P, right, w, in);
            return;
        }
    }
    return;
}

int main() {
    int N, I;
    ll W;
    scanf("%d%d%lld", &N, &I, &W);
    for(int i=0; i<N; i++) {
        ll h;
        scanf("%lld", &h);
        B.push_back((S){h, i});
    }
    //�̰��ץѤp��j�Ƨ�
    sort(B.begin(), B.end(), comp);
    rec(0, N-1, W, I);
    for(int i=0; i<N-1; i++) {
        printf("%lld%c", ans[i], i==N-1 ? '\n' : ' ');
    }
    return 0;
}