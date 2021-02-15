#include <iostream> 

using namespace std; 

int solve(){
  int n , k; 
  cin >> n >> k; 
  k--; 
  int move = 0; 
  if(n % 2 == 0){
    move = k;  
  }
  else{
    move = k; 
    move += (k/(n/2)); 
  } 
  int left = move % n; 
  return left + 1;  
}

int main(){
  int T; 
  cin >> T;
  for(int i = 0; i < T; i++){
    cout << solve() << endl; 
  }
  return 0; 
}