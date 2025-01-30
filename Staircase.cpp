#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n, k, temp, max_;
    vector<int> steps;
    cin >> n;
    steps.push_back(0);
    for (int i = 0; i < n; i++){
        cin >> temp;
        steps.push_back(temp);
    }
    steps.push_back(0);
    cin >> k;
    for (int i = 2; i < n+2; i++){
        max_ = *max_element(steps.begin() + max(i-k, 0), steps.begin() + i);
        steps[i] += max_;
    }
    cout << steps[n+1];
    return 0;
}
