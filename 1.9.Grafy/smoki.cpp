#include<bits/stdc++.h>

using namespace std;

bool tab[1000][1000];
int t, row, col, counter;

struct entry{
    int x;
    int y;
    int t;
};

queue<entry> q;

void bfs(){
    entry c;
    while(!q.empty()){
        c = q.front();
        q.pop();
        //cout << "looking at:" << c.x << ", " << c.y << ", " << c.t << '\n';
        if(tab[c.x][c.y]==true || c.t > t || c.x < 0 || c.x >= row || c.y < 0 || c.y >= col){
            //cout << "ignored: " << c.x << ", " << c.y << ", " << c.t << '\n';
            continue;
        }
        tab[c.x][c.y] = true;
        //cout << "marked " << c.x << ", " << c.y << '\n'; 
        counter++;
        q.push({c.x-1, c.y, c.t+1});
        q.push({c.x+1, c.y, c.t+1});
        q.push({c.x, c.y-1, c.t+1});
        q.push({c.x, c.y+1, c.t+1});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> row >> col >> t;
    char curr;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> curr;
            if(curr == 'x'){
                //cout << "pushed: " <<  i << ", " << j << '\n';
                q.push({i, j, 0});
            }
        }
    }
    bfs();
    cout << counter << '\n';
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(tab[i][j]){
                cout << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
}