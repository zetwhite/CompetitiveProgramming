#include <iostream> 
#include <cstring>
#include <vector> 

typedef long long ll; 
using namespace std; 

const ll m = 1000000007; 
const int MAXN = 500; 
bool observation[MAXN][MAXN]; 
int observCont[MAXN];
bool used[MAXN]; 

void initUsed(){
    memset(used, 0, sizeof(bool)*MAXN); 
}

int getFacto(int n) {
    ll value = 1; 
    for(int i = 1; i <= n; i++){
        value = value * i; 
        value %= m; 
    }
    return value; 
}

vector<int> IsCycle(int n, int size){
    bool isCycle = true; 
    vector<int> cycle; 
    for(int i = 0; i < size; i++){
        if(observation[n][i] == 1){
            if(memcmp(observation[n], observation[i], sizeof(bool)*size) != 0){
                isCycle = false; 
                break; 
            }
            else
                cycle.push_back(i);  
        }
    }
    if(isCycle == true && cycle.size() == observCont[n]){
        for(int i = 0; i < cycle.size(); i++){
            used[cycle[i]] = true; 
        }
        return cycle; 
    }
    cycle.clear(); 
    return cycle; 
}

vector<int> findPointer(vector<int>& cycle, int N){
    vector<int> pointer; 
    for(int i = 0; i <N; i++){
        if(observCont[i] == cycle.size() + 1){
            bool success = true; 
            for(int j = 0; j < cycle.size(); j++){
                if(observation[i][cycle[j]] == 0){
                    success = false; 
                    break; 
                }
            }
            if(success)     
                pointer.push_back(i); 
        }
    }
    return pointer; 
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int N; 
    cin >> N; 
    initUsed(); 

    for(int i = 0; i < N; i++){
        int cnt = 0; 
        for(int j = 0; j < N; j++){
            cin >> observation[i][j]; 
            if(observation[i][j]) 
                cnt++; 
        }
        observCont[i] = cnt; 
    }

    vector<vector<int>> cycleBin; 
    for(int i = 0; i < N; i++){
        if(used[i] == false && observCont[i] > 1){
            vector<int> res = IsCycle(i, N); 
            if(res.size() != 0)
                cycleBin.push_back(res); 
        }
    }

    ll result = 1; 
    vector<int> pointer; 
    for(int i = 0; i < cycleBin.size(); i++){
        result *= getFacto(cycleBin[i].size() - 1); 
        result %= m; 
        pointer = findPointer(cycleBin[i], N); 
        for(int j = 0; j < pointer.size(); j++){
            result *= cycleBin[i].size(); 
            result %= m; 
        } 
    }
    cout << result % m << endl; 
    return 0; 
}