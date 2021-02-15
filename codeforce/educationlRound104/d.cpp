#include <iostream> 

using namespace std; 


const int MAXA = 44723; 
bool a_arr[MAXA]; 
int cnt[MAXA]; 

void dp(){
  a_arr[0] = false; 
  a_arr[1] = false; 
  a_arr[2] = false; 
  for(int a = 3; a < MAXA; a++){
    long long n = ( a * a + 1 )/2; 
    long long b = n - 1; 
    long long c = n; 
    if(c == a*a - b)
      a_arr[a] = true; 
    else 
      a_arr[a] = false; 
  }
  int sum = 0; 
  for(int a = 0; a < MAXA; a++){
    if(a_arr[a])
      sum++; 
    cnt[a] = sum; 
  }
}

int solve(int n){
  dp(); 
  int a = 0; 
  for(; a < MAXA; a++){
    long long loc = (a * a + 1) / 2; 
    if( loc > n )
      break; 
  }
  a--; 
  return cnt[a]; 
}

int main(){
  int T; 
  cin >> T;
  int n; 
  for(int i = 0; i < T; i++){
    cin >> n; 
    cout << solve(n) << endl;  
  }
  return 0; 
}