#include<bits/stdc++.h>

using namespace std;

int nwd(int x, int y){
    while(x!=0){
        swap(x, y);
        
        x%=y;
    }
    return max(x, y);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << nwd(a,b);
}