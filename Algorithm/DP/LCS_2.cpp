/*
***LCS*** -- reduce momory
    Description:
        �Ѻ��i���i�H�ݥX�A�p��L�{���u�ݭn��e�C�H�ΤW�@�C����T�C
            "from": �N��e�@�C (�H�ΥN���Ʀ�)
            "to": �N���e�� i �C (�_�Ʀ�)
        ���ƧQ�ΰ}�C�A�C�⧹�@�C�A�洫 from �M to�C
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char s1[505], s2[505];
    scanf("%s%s", s1, s2);
    int m = strlen(s1), n = strlen(s2);
    int lcs[2][505] = {0};
    int from = 0, to = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            lcs[to][j] = s1[i-1] == s2[j-1] ? lcs[from][j-1]+1 : \
                            max(lcs[from][j], lcs[to][j-1]);
        }
        swap(from, to);
    }
    //since "from" and "to" swapped in the last step, so the result is "from"
    printf("%d\n", lcs[from][n]);
    return 0;
}