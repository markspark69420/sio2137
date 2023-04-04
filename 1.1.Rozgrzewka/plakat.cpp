#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n, res=0;
    cin >> n;
    int curr;
    stack<int> sztos;
    for(int i=0; i<n; i++){
        cin >> curr >> curr;
        if(sztos.empty()){
            res++;
            //cout << "\npushed e: " << curr;
            sztos.push(curr);
        }
        else if(sztos.top() > curr){
            while (sztos.top() > curr)
            {
                //cout << "\npopped: " << sztos.top();
                sztos.pop();
                if(sztos.empty()){
                    res++;
                 //   cout << "\npushed w: " << curr;
                    sztos.push(curr);
                    break;
                }
            }
            if(sztos.top() < curr){
                res++;
                //cout << "\npushed w: " << curr;
                sztos.push(curr);
            }
        }
        else if(sztos.top() < curr){
            res++;
            //cout << "\npushed <: " << curr;
            sztos.push(curr);
        }
    }
    cout << res;
}