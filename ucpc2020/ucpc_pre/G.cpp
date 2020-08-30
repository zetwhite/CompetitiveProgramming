#include <iostream> 
#include <vector> 
#include <cstring>
#include <set>

using namespace std; 
#define T 200000

vector<int> adj[T+1]; 
int* rumored; 

bool believe(int here){
    int check = 0;
    int adjCount = adj[here].size(); 
    for(int i =0; i < adjCount; i++){
        int neigh = adj[here][i]; 
        if(rumored[neigh] != -1)
            check++; 
    } 
    if((adjCount+1)/2 <= check)
        return true; 
    return false; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N; 
    cin >> N; 
    rumored = new int[N+1]; 
    set<int> Next; 
    memset(rumored, -1, sizeof(int)*(N+1)); 

    for(int i = 1; i <= N; i++){
        int cnt = 0; 
        while(1){
            int tmp; 
            cin >> tmp; 
            if(tmp == 0) 
                break; 
            adj[i].push_back(tmp); 
        }
    }

    int sec = 0; 
    vector<int> saver; 

    int starter; 
    cin >> starter; 
    for(int i = 0; i < starter; i++){
        int tmp; 
        cin >> tmp; 
        saver.push_back(tmp); 
    }

    while(saver.size() != 0){
        for(int i = 0; i < saver.size(); i++){
            rumored[saver[i]] = sec; 
        }
        for(int i = 0; i < saver.size(); i++){
            for(int j = 0; j < adj[saver[i]].size(); j++){
                int tmp = adj[saver[i]][j]; 
                if(rumored[tmp] == -1)
                    Next.insert(tmp); 
            }
        }
        saver.clear();
        sec++; 
        set<int>::iterator it; 
        for(it = Next.begin(); it != Next.end(); ++it){
            if(believe(*it)){
                saver.push_back(*it);
            } 
        }
        Next.clear(); 
    } 

    for(int i = 1; i <= N; i++)
        cout << rumored[i] << " "; 
    cout << endl; 
    return 0; 
}