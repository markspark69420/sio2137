#include<bits/stdc++.h>

using namespace std;

map<string, int> str_to_indx;

int leader[1000002];

int find(int a){
    if(leader[a] == a || leader[a] == 0){
        return a;
    }
    int b = find(leader[a]);
    leader[a] = b;
    return b;
}

void join(int a ,int b){
    int x = find(a), y = find(b);
    if(x==y){
        return;
    }
    leader[x] = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    int indx = 1;
    string curr1, curr2;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> curr1;
        if(curr1[0] == 's'){
            cin >> curr1 >> curr2;
            if(str_to_indx.find(curr1) == str_to_indx.end()){
                str_to_indx[curr1] = indx;
                indx++;
            }
            if(str_to_indx.find(curr2) == str_to_indx.end()){
                str_to_indx[curr2] = indx;
                indx++;
            }
            if(find(str_to_indx[curr1]) == find(str_to_indx[curr2])){
                cout << "Tak\n";
            }
            else{
                cout << "Nie\n";
            }
        }
        else{
            cin >> curr1 >> curr2;
            
            if(str_to_indx.find(curr1) == str_to_indx.end()){
                str_to_indx[curr1] = indx;
                indx++;
            }
            if(str_to_indx.find(curr2) == str_to_indx.end()){
                str_to_indx[curr2] = indx;
                indx++;
            }
            join(str_to_indx[curr1], str_to_indx[curr2]);
        }
    } 
}