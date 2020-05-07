#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

inline void new_vector_vector(vector<vector<int>>& res){
    vector<int> tmp; 
    res.push_back(tmp);
}

void make_set(vector<vector<int>>& res, vector<int>& ms, int* limits){
    int res_max = 1; 
    new_vector_vector(res);
    vector<int>::iterator it = ms.begin();
    while (it != ms.end()){
        int i = 0; 
        int limit = limits[*it - 1];
        for(; i < res_max; i++){
            if(limit >= res[i].size() + 1){
                res[i].push_back(*it); 
                break; 
            }
        }
        if(i == res_max){
            new_vector_vector(res);
            res[i].push_back(*it); 
            res_max++;
        }
        it++;  
    }
    return;  
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, k; 
    cin >> n >> k;
    vector<int> ms;
    int* limits = new int[k];
    for(int i = 0; i < n; i++){
        int tmp; 
        cin >> tmp; 
        ms.push_back(tmp);
    }
    for(int j = 0; j < k; j++)
        cin >> limits[j];
    sort(ms.begin(),ms.end(), greater<int>());
    vector<vector<int>> res; 
    
    make_set(res, ms, limits);
    cout << res.size() << "\n"; 
    for(int i = 0; i < res.size(); i++){
        cout << res[i].size() << " ";
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n"; 
    }
    return 0;
}