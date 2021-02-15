#include <iostream> 

using namespace std; 

void solve(double n){
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      //cout << "[ " << i << " vs " << j << "] " << endl; 
      if(j == i + n/2){
        cout << 0 << " "; 
      }
      else if (j < i + n/2)
        cout << -1 << " "; 
      else 
        cout << 1 << " "; 
    }
  }
  cout << endl; 
}

int main(){
  int T; 
  cin >> T;
  int n; 
  for(int i = 0; i < T; i++){
    cin >> n; 
    solve(n);  
  }
  return 0; 
}