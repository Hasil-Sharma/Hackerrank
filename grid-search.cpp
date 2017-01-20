#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool check_flag;

void check(int start_r, int start_c, int r, int c, int R, int C, vector<string> &G, vector<string> &P ){
    int count = 0;
    bool break_flag = true;
    for(int g_i = start_r, p_i = 0; p_i < r && g_i < start_r + r && break_flag; p_i++, g_i++){
        for(int g_j = start_c, p_j = 0; p_j < c && g_j < start_c + c && break_flag ; p_j++, g_j++){
            break_flag = (G[g_i][g_j] == P[p_i][p_j]);
        }
    }
    
    check_flag = break_flag;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        check_flag = false;
        int i,j;
        for( i = 0; i < R  && !check_flag; i++)
            for( j = 0; j < C && !check_flag; j++){
              check(i, j, r, c, R, C, G, P);
        }
        //cout << i << " :" << j << endl;
        cout << (check_flag ? "YES" : "NO") << endl;
    }
    return 0;
}

