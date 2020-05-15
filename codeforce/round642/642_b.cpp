#include <iostream>
#include <queue>
using namespace std; 

int solve(int n, int k){
    priority_queue<int, vector<int>, greater<int>> a; 
    priority_queue<int> b; 
    for(int i = 0; i < n; i++){
        int num;
        cin >> num; 
        a.push(num); 
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num; 
        b.push(num); 
    }

    for(int i = 0; i <k; i++){
        int from_a = a.top(); 
        int from_b = b.top(); 
        if(from_a >= from_b)
            break;
        a.pop(); 
        b.pop(); 
        a.push(from_b); 
        b.push(from_a); 
    }

    int sum = 0; 
    while(!a.empty()){
        sum += a.top(); 
        a.pop(); 
    }
    return sum; 
}


int main(){
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k; 
        cout << solve(n, k) << endl;
    }
    return 0;
}