#include <iostream>
#include <string>
#include <list>
using namespace std;

void solve(){
    string s;
    cin >> s;
    list<bool> string_list;
    char first = s[0];
    bool all_same = true;
    for(int i = 0; i < s.size(); i++){
        string_list.push_back(bool(s[i]-'0'));
        if(first != s[i]){
            all_same = false;
        }
    }
    if(!all_same){
        list<bool>::iterator it1 = string_list.begin();
        it1++;
        list<bool>::iterator it2 = string_list.begin();
        while(it1 != string_list.end()){
            if(*it2 == *it1){
                string_list.insert(it1, !(*it2));
                it2++;
            }
            else{
                it1++;
                it2++;
            }
        }
    }
    list<bool>::iterator it = string_list.begin();
    for(;it!=string_list.end(); it++){
        cout << char((*it) + '0');
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}
