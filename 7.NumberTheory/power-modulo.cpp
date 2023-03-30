#include<iostream>

using namespace std;

unsigned int modulo = 1000000007;

unsigned long long power(unsigned int x, unsigned int y){
    
    if(y==0) 
        return 1;

    if(y%2 == 0){
        unsigned long long a = power(x,y/2);
        return (a*a)%modulo;
    }
    else{
        unsigned long long a = power(x,y-1);
        return (a*x)%modulo;
    }
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int iter;
    cin >> iter;
    unsigned int a,b;
    for(int i=0;i<iter;i++){
        cin >> a >> b;
        cout<<power(a,b)<<'\n';
    }
}