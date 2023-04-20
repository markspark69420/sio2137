#include<iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long max_res = -999999999;
    long long min = 0;
    long long curr = 0;
    long long input;
    for(int i=0; i<n; i++){
        cin >> input;
        curr += input;
        if(curr - min > max_res){
            max_res = curr - min;
        }
        if(curr < min){
            min = curr;
        }
    }
    cout << max_res;

}