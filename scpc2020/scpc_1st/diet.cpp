#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std; 

int solve(){
    int N, K; 
    cin >> N >> K; 
    vector<int> menuA; 
    vector<int> menuB; 
    vector<int> result; 
    menuA.reserve(N);
    menuB.reserve(N); 

    for(int i = 0; i < N; i++){
        int cal; 
        cin >> cal; 
        menuA.push_back(cal); 
    }
    for(int i =0; i < N; i++){
        int cal; 
        cin >> cal; 
        menuB.push_back(cal); 
    }
    sort(menuA.begin(), menuA.end(), less<int>()); 
    sort(menuB.begin(), menuB.end(), less<int>()); 
    for(int i = 0; i < K; i++){
        result.push_back(menuA[i] + menuB[K-1-i]); 
    }
    sort(result.begin(), result.end(), greater<int>()); 
    return result[0]; 
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T; 
    cin >> T; 
    for(int i = 0; i < T; i++){
        int res = solve(); 
        cout << "Case #" << i+1 << "\n"; 
        cout << res << "\n"; 
    }
    return 0; 
}