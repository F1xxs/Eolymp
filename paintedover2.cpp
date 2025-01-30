#include <iostream>
#include <cmath>


using namespace std;


int main(){
    double m, r, y;
    cin >> m >> r;
    r /= m;
    int N = ceil(r);
    int squares = N + N - 1;
    int perfect = 0;
    for (int x = ceil(r * (sqrt(2)/2)); x < N; x++) {
        y = sqrt(r * r - x * x);
        if  (ceil(y) == y) {
            ++perfect;
            ++perfect;
        }
    }
    cout << ((N + N - 1) - perfect) * 4;
}
