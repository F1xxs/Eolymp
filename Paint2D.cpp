#include <iostream>
#include <cmath>
#include <algorithm>

#define N 1001
#define MAX 255
using namespace std;

unsigned char dim_list[N][N];

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            dim_list[i][j] = MAX;
        }
    }
    dim_list[1][1] = 4;
    dim_list[1][2] = 6;
    dim_list[1][3] = 8;
    dim_list[2][1] = 6;
    dim_list[3][1] = 8;
    for (int i = 1; i < (a + 1); ++i){
        for (int j = 1; j < (b+1); ++j){
            if (dim_list[i][j] != MAX){
                continue;
            }
            dim_list[i][j] = min({dim_list[(int)ceil(i / 2.0)][j] + 4, dim_list[(int)ceil(i / 3.0)][j] + 6,
                                 dim_list[(int)ceil(i / 2.0) + 1][j] + 4,
                                 dim_list[(int)ceil(i / 3.0) + 1][j] + 6, dim_list[i][(int)ceil(j / 2.0)] + 4,
                                 dim_list[i][(int)ceil(j / 2.0) + 1] + 4, dim_list[i][(int)ceil(j / 3.0)] + 6,
                                 dim_list[i][(int)ceil(j / 3.0) + 1] + 6});


        }
    }
    cout << (int)dim_list[a][b];
    return 0;
}
