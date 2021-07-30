#include <iostream> 
#include <climits> 
using namespace std;
typedef long long ll;  


int main(){
  /*ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);*/
  cout << fixed; 
  cout.precision(9); 
  int T; 
  cin >> T; 
  int W, H; 
  int x1, y1, x2, y2; 
  int w, h; 
  
  int rows; 
  int cols; 
  
  for(int i = 0; i < T; i++){
    cin >> W >> H; 
    cin >> x1 >> y1 >> x2 >> y2; 
    cin >> w >> h; 

    rows = x2 - x1; 
    cols = y2 - y1; 

    if(rows + w > W && cols + h > H){
      cout << -1 << endl; 
      continue; 
    }
    
    if(rows + w > W){ // have to space in col 
      int mv1 = y1; 
      int mv2 = H - y2; 
      double maxFree = h - max(mv1, mv2); 
      if(maxFree >= 0 )
        cout << maxFree << endl; 
      else 
        cout << double(0) << endl;  
      continue; 
    }

    if(cols + h > H){
      int mv1 = x1; 
      int mv2 = W - x2; 
      double maxFree = w - max(mv1, mv2); 
      if(maxFree >= 0 )
        cout << maxFree << endl; 
      else 
        cout << double(0) << endl;  
      continue; 
    }

      int mv1 = y1; 
      int mv2 = H - y2; 
      double maxFree1 = h - max(mv1, mv2); 
      if(maxFree1 <= 0)
        maxFree1 = 0; 

      int mv3 = x1; 
      int mv4 = W - x2; 
      double maxFree2 = w - max(mv3, mv4);
      if(maxFree2 <= 0)
        maxFree2 = 0; 

      double final = maxFree1; 
      if(final > maxFree2)
        final = maxFree2; 
    cout << final << endl; 
  }
  return 0; 
}