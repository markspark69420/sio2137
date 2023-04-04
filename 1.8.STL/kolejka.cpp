#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int a;
    cin>>a;
    queue<short> q;
    char funct;
    short b;
    for(int i=0;i<a;i++){
        cin>>funct;
        if(funct=='-'){
            cout<<q.front()<<'\n';
            q.pop();
        }
        else{
            cin>>b;
            q.push(b);
        }
    }
}