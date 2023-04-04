#include<stack>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

    string curr;
    int talerze;
    int temp;
    int q;
    cin>>talerze>>q;
    int height[talerze+1];
    fill_n(height, talerze+1, -1);
    
    for(int i=0;i<q;i++){
        cin>>curr;
        if(curr=="odloz"){
            cin>>temp;
            s.push(temp);
            height[temp]=s.size();
        }
        else if(curr=="zdejmij"){
            height[s.top()] = -1;
            s.pop();
        }
        else{
            cin>>temp;
            if(height[temp]==-1){
                cout<<-1<<'\n';
            }
            else{
                cout<<s.size()-height[temp]<<'\n';
            }
        }
    }
}