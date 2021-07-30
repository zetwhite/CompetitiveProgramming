#include <iostream> 
#include <vector> 
using namespace std; 
typedef long long ll; 


int main(){
  int T; 
  cin >> T; 
  
  int M = 5'00000; 
  
  int* first = new int[M+2]; 
  int* second = new int[M+2]; 
  int* fSum = new int[M+2];
  int* sSum = new int[M+2]; 

  int tmp1, tmp2; 
  ll sum = 0; 
  for(int i = 0; i < T; i++){
    cin >> M; 
    sum = 0; 
    for(int j = 0; j < M; j++){
      cin >> tmp1; 
      first[j] = tmp1; 
      sum += tmp1; 
      fSum[j] = sum; 
    }
    sum = 0; 
    for(int j = 0; j < M; j++){
      cin >> tmp1; 
      second[j] = tmp1; 
      sum += tmp1; 
      sSum[j] = sum; 
    }

    ll score = 1'000'000'000'000;
    ll s1, s2; 
    for(int link = 0; link < M; link++){
      s1 = fSum[M-1] - fSum[link];
      if(link != 0) 
        s2 = sSum[link - 1]; 
      else 
        s2 = 0; 
      ll _score = max(s1, s2); 
      if(score > _score)
        score = _score; 
    }
    cout << score << endl; 
  }

  return 0; 
}