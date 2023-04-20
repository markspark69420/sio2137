#include<bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000;

bool land[1000][1000];
int n;
int mem[1000][1000];

int walk(int x, int y){
    if(mem[x][y] != -1)
        return mem[x][y];

    if(x >= n || y >= n || land[x][y]){
        mem[x][y] = 0;
        return 0;
    }
    if(x == n-1 && y == n-1){
        mem[x][y] = 1;
        return 1;
    }
    mem[x][y] = (walk(x, y+1) + walk(x+1, y))%MOD;
    return mem[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mem[i][j] = -1;
            cin >> land[i][j];
        }
    }
    cout << walk(0,0);
}