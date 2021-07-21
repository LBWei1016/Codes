/*
�q�`�Ө��A�p�G�n���p�`�ƪ��ܡA�۸��󪽱��ϥΰ}�C�A�Ŷ��O 1/8�Bcount ���O 1/6�B
�줸�B����O 1/30�C��M�o�ǳ����O���諸�C
*/
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    string s = "00011101010001";
    // construct a length-fixed bit array, initialized by string "s"
    bitset<20> bs(s); 
    bitset<20> bs2; //all "0" by default
    cout << bs << (bs2 = bs) << '\n';
    bs2 <<= 100;
    cout << bs2;

    string tos = bs.to_string(); // O(n)
    unsigned long ul = bs.to_ulong(); // O(n)
    bs.flip(); // flip 0 to 1 and 1 to 0, O(n)
    bs.set(); // all to 1, O(n)
    bs.reset(); // all to 0. O(n)
    return 0;
}