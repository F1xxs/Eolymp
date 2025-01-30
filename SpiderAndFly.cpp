#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int A, B, C;
    double dist;
    dist = 999999999.0;
    int x1, y1, x2, y2, z2;
    cin >> A >> B >> C;
    cin >> x1 >> y1 >> x2 >> y2 >> z2;
    if (z2 == 0){
        dist = min(dist, sqrt(pow((x1-x2), 2) + pow((y1-y2), 2)));
    }
    else{
        if (x2 == 0){
            dist = min(dist, sqrt(pow((x1-(x2-z2)), 2) + pow((y1-y2), 2)));
        }   
        if (x2 == B){
            dist = min(dist, sqrt(pow((x1-(x2+z2)), 2) + pow((y1-y2), 2)));
        }
        if (y2 == 0){
            dist = min(dist, sqrt(pow((x1-x2), 2) + pow((y1-(y2-z2)), 2)));
        }
        if (y2 == A){
            dist = min(dist, sqrt(pow((x1-x2), 2) + pow((y1-(y2+z2)), 2)));
        }


    }
    cout << fixed << showpoint;
    cout << setprecision(2) << dist;

}
