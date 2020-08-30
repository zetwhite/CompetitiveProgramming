#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std ; 

class Node{
public: 
    Node(): 
    start(false), notErase(false), depth(-1){}
    vector<int> next; 
    int depth; 
    int final; 
    bool start; 
    bool notErase; 
}; 

Node* tree; 
int N, S, D; 

int getDepth(Node& here, int depth){
    here.depth = depth; 
    int final = -1; 
    int done = false; 
    for(int i = 0; i < here.next.size(); i++){
        if(tree[here.next[i]].depth == -1){
            done = true; 
            tree[here.next[i]].depth = depth + 1; 
            int tmp_final = getDepth(tree[here.next[i]], depth + 1);
            if(tmp_final > final){
                final = tmp_final; 
            }
        }
    }
    if(final == -1)
        here.final = depth; 
    else 
        here.final = final; 
    if(done == false)
        return depth;
    else
        return final; 
}

int getDistance(Node& here){
    if(here.final - here.depth <= D){
        return 0; 
    }
    int dist = 0; 
    for(int i = 0; i < here.next.size(); i++){
        if(tree[here.next[i]].depth > here.depth){
            Node& more = tree[here.next[i]]; 
            if((more.final - more.depth) >= D)
                dist += (getDistance(tree[here.next[i]]) + 1); 
        } 
    }
    return dist; 
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin >> N >> S >> D; 

    tree = new Node[N+1]; 
    tree[S].start = true; 
     
    for(int i = 0; i < N-1; i++){
        int x, y; 
        cin >> x >> y;
        tree[x].next.push_back(y);
        tree[y].next.push_back(x);  
    }
    getDepth(tree[S], 0); 
    cout << getDistance(tree[S]) * 2 << endl; 
    
    return 0; 
}