#include <iostream> 
#include <climits> 
using namespace std;
typedef long long ll;  


long long getMinTime(ll currentValue, ll leftValue, ll time){
  if(leftValue <= 0){
    return time; 
  }
  ll totalTime = LLONG_MAX; 
  if(currentValue <= 6){
    ll _time = getMinTime(6, leftValue - 6, time + 15);
    if(totalTime > _time)
      totalTime = _time;
  }
  if(currentValue <= 8){
    ll _time = getMinTime(8, leftValue - 8, time + 20);
    if(totalTime > _time)
      totalTime = _time;
  }
  if(currentValue <= 10){
    ll _time = getMinTime(10, leftValue - 10, time + 25);
    if(totalTime > _time)
      totalTime = _time;
  }
  return totalTime; 
}

int main(){
  /*ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);*/

  long long arr[125];
  arr[0] = 0; 
  for(ll i = 1; i <= 120; i++){
    arr[i] = getMinTime(0, i, 0); 
    //cout << i << " = "  << arr[i] << endl; 
  }
  ll T; 
  ll freinds; 
  ll tums; 
  cin >> T; 
  for(int i = 0; i < T; i++){
    cin >> freinds; 
    tums = freinds/120; 
    cout << tums * arr[120] + arr[freinds%120] << endl; 
  }
  return 0; 
}