#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main(){
    int n, count;
    count = 0;
    cin >> n;
    int ma = 9;
    int first_digit, last_digit;
    while (n <= pow(10, ma)){
       ma--;
    }
    // cout << ma << endl;
    int loop_lenght = (ma + 2)/2;
    for (int i=0; i < loop_lenght; i++){
        first_digit = n / (int)pow(10, ma);
        last_digit = n % 10;
        if (first_digit == last_digit){
            count++;
        } 
        // cout << first_digit << " " << last_digit << endl;
        n -= first_digit * (int)pow(10, ma);
        n /= 10;
        ma -= 2;
    }
    cout << count << endl;
}
