/*
    XOR => a^b
    getBit => rightshift a by b bits and perform & with 1
    setBit => leftshift 1 by b bits and perform | with a
*/

#include<bits/stdc++.h>

using namespace std;

int getXOR(int a, int b) {
    return a^b;
}

int getBit(int a, int b) {
    a>>=b;
    return a & 1;
}

int setBit(int a, int b) {
    int temp = 1;
    temp<<=b;
    return a | temp;
}

int main() {
    int a = 20;
    int b = 10;

    cout<<getXOR(a, b)<<endl;
    cout<<getBit(a, b)<<endl;
    cout<<setBit(a, b)<<endl;
    return 0;
}
