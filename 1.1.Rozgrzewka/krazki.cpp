#include<bits/stdc++.h>

using namespace std;

int width[300000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> width[0];
    for(int i=1; i<n; i++){
        cin >> width[i];
        width[i] = min(width[i], width[i-1]);
    }
    int curr, indx=n;
    for(int i=0; i<m; i++){
        cin >> curr;
        indx--;
        while(indx>0 && curr>width[indx]){
            indx--;
        }
    }
    cout << max(0, indx+1);
}