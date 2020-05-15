#include <iostream>
#include <cstring>
#include <queue>
using namespace std; 

class SubArr{
public: 
    int start_idx; 
    int end_idx;
    int len; 
    SubArr(int st, int ed, int l)
    :start_idx(st), end_idx(ed), len(l){}; 
}; 

bool operator < (const SubArr& l, const SubArr& r){
    if(l.len < r.len)
        return true; 
    else if(l.len == r.len)
        return (l.start_idx > r.start_idx);
    return false; 
}

void solve(int n){
    int* arr = new int[n+1]; 
    memset(arr, 0, sizeof(int)*(n+1)); 

    priority_queue<SubArr> q; 
    q.emplace(1, n, n); 
    for(int i = 1; i <= n; i++){
        SubArr here = q.top(); 
        q.pop(); 
        int mid = (here.start_idx + here.end_idx)/2; 
        arr[mid] = i;
        int len = (mid - here.start_idx); 
        if(len >= 1)
            q.emplace(here.start_idx, mid-1, len); 
        len = (here.end_idx - mid); 
        if(len >= 1)
            q.emplace(mid+1, here.end_idx, len); 
    }

    for(int i = 1; i <= n; i++)
        cout << arr[i] <<" "; 
    cout << endl; 
    delete arr; 
}  

int main(){
    int t; 
    cin >> t;
    int n;  
    for(int i = 0; i < t; i++){
        cin >> n; 
        solve(n); 
    }
    return 0; 
}