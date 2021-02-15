#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int main(){
  int t; 
  int n; 
  int tmp; 
  cin >> t; 
  for(int i = 0; i < t; i++){
    cin >> n; 
    vector<int> v;
    v.reserve(n); 

    for(int j = 0; j < n; j++){
      cin >> tmp; 
      v.emplace_back(tmp); 
    }
    sort(v.begin(), v.end()); 
    int min = v[0]; 
    int idx = 0;  
    for(; idx < n; idx++){
      if(min < v[idx]){
        break; 
      }
    }
    cout << n - idx << endl; 
  }
  return 0; 
}