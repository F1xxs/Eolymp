#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, temp, sum;
    sum = 2; 
    cin >> n;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    for (int i = 3; i < n; i++){
        sum = numbers[i-2] + numbers[i-1];
        numbers.push_back(sum);
    }
    cout << numbers[n-1];
}
