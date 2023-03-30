#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int tab1[26], tab2[26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    for(unsigned int i=0; i<str1.length(); i++){
        tab1[str1[i]-'a']++;
    }
    for(unsigned int i=0; i<str2.length(); i++){
        tab2[str2[i]-'a']++;
    }
    string res1, res2;
    int len = 0;
    int ftab[26];
    for(unsigned int i=0; i<26; i++){
        tab1[i] = min(tab1[i], tab2[i]);
        tab2[i] = tab1[i];
        len += tab1[i];
    }
    for(unsigned int i=0; i<str1.length(); i++){
        if(tab1[str1[i]-'a'] != 0){
            tab1[str1[i]-'a']--;
            res1.push_back(str1[i]);
        }
    }
    for(unsigned int i=0; i<str2.length(); i++){
        if(tab2[str2[i]-'a'] != 0){
            tab2[str2[i]-'a']--;
            res2.push_back(str2[i]);
        }
    }
    if(len>0)    
        cout << len << '\n' << res1 << '\n' << len << '\n' << res2;
    else
        cout << "BRAK";
}