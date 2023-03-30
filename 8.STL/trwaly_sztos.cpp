#include<iostream>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

enum action{
    Add = 0,
    Remove = 1,
    Revert = 2,
    No = 3
};

pair<action, int> actions[200001];
int revert[200002];

stack<int> curr;
map<int,stack<int>> to_revert;
int revert_indx = 0;


int main(){

    int q;
    cin >> q;
    fill(revert, revert+200002, 200001);

    char temp;
    int num;
    for(int i=0; i<q; i++){
        cin >> temp;
        if(temp=='+'){
            cin >> num;
            actions[i].first = Add;
            actions[i].second = num;
        }
        else if(temp=='-'){
            actions[i].first = Remove;
        }
        else{
            cin >> num;
            revert[i] = i - num;
            actions[i].first = Revert;
            actions[i].second = num;
        }
    }
    sort(revert,revert+q);

    
    for(int i=0; i<q; i++){
        if(revert[revert_indx]==i){
            //cout << "added to a map " << i << ' ' << revert_indx <<'\n';
            revert_indx++;
            while(revert[revert_indx]==revert[revert_indx-1] && revert[revert_indx]!=200001){
                revert_indx++;
            }
            to_revert[i] = curr;
        }
        if(actions[i].first == Add){
            //cout<< "Added "<<actions[i].second<<'\n';
            curr.push(actions[i].second);
        }
        else if(actions[i].first == Remove){
            //cout << "removed\n";
            curr.pop();
        }
        else if(actions[i].first == Revert){
            //cout<<"Reverted " << actions[i].second<<'\n';
            curr = to_revert[i-actions[i].second];
        }
        //cout<<"moai " << curr.size() << '\n';
        if(curr.size() > 0){    
            cout << curr.top() << '\n';
        }
        else{
            cout << "-1\n";
        }
    }
}