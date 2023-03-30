#include<iostream>
#include<string>
#include<chrono>

using namespace std;
void tre(int num){
    for(int i = 0; i <num; i++){
        cout <<string(num-i,' ')<<string(2*i+1,'*')<<'\n';
    }
    for(int i = 0; (i-1) <num; i++){
        cout <<string(num-i,' ')<<string(2*i+1,'*')<<'\n';
    }
    cout<<string(num,' ')<<"*\n"<<string(num,' ')<<"*\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numer;
    cin>>numer;
    auto start = chrono::steady_clock::now();
    
    for (int i = 0;i<numer;i++){
        cout<<i<<'\n';
        tre(i);
    }
    auto diff= chrono::steady_clock::now()-start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}