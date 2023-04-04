#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int root(int x, int aprox){
    int res[2] ={aprox,(aprox+x/aprox)/2};
    bool a = 0;
    bool b = 1;
    int iter = 0;
    while(res[0]!=res[1] && iter < 2000){
        res[a] = (res[b]+x/res[b])/2;
        a = b;
        b = not b;
        iter++;
    }
    int c = min(res[0], res[1]);
    return (x==c*c)? c : c+1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    unsigned long long a;
    cin >> a;
    cout << root(a,1);

}