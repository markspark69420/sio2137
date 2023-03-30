#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int il;
    cin >> il;
    unordered_map<long long, int> worek;
    long long curr;
    for(int i=0; i<il; i++){
        cin >> curr;
    }

    cin >> il;
    for(int i=0; i<il; i++){
        cin >> curr;
        cout<< worek[curr]<< '\n';
    }
}