#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long sol(int n, int k){
    if (n==1){
        return k;
    }
    long line = powl(k-1, n) + powl(-1, n) * (k-1);
    if (!line){
        return -1;
    }
    else{
        return line;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    cout << sol(n, k);
}
