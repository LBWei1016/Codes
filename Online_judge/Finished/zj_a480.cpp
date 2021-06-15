/*
***�a�|(method of exhaustion)***
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6+5;

//��Ĥ@�B�ĤG�t�Ϊ��Z��(����)
struct point {
    int d1, d2;
}ps[MAX_N];

int x1, x2, y1, y2, n;
//�H��Ĥ@�t�Ϊ��Z�����D�A�v�B�X�j�a�|�A�]���N��� d1 �i��ɾ��ƦC
bool comp(const point &p1, const point &p2) {
    return p1.d1 < p2.d1;
}

int main() {
    
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i].d1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
        ps[i].d2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
    }
    
    sort(ps, ps+n, comp);

    //��X�䥦������ĤG�Өt�Ϊ��̻��Z��
    for(int j=n-2; j>=0; j--) 
        ps[j].d2 = max(ps[j].d2, ps[j+1].d2);

    ps[n].d2 = 0;
    int ans = 0x7fffffff;
    for(int i=0; i<n; i++) {
        //�`��q��O: �Ĥ@�Өt�β[�\���d�� + (�Ĥ@�t�ΨS���[�\��)�䥦������ĤG�Өt�Ϊ��̻��Z��
        //i �N��� i ���I
        ans = min(ans, ps[i].d1+ps[i+1].d2);
    }
    //ps[0].d2: ��(x2, y2)�[�\�Ҧ��I�Fps[n-1].d1: ��(x1, y1)�[�\�Ҧ��I
    printf("%d\n", min(ans, ps[0].d2));

    return 0;
}