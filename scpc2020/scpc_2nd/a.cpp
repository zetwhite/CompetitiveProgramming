
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cstring> 
typedef long long ll; 
#define MAX 2000'000'000
using namespace std;

ll Answer;
int n; 
int* As; 
int* Bs; 
bool *Aused; 
bool *Bused; 
int* Anear; 
int* Bnear; 
int* matchResult; 

void setNear(int* src, int* dest, int* near){
    int dest_idx = 0; 
    int src_idx = 0 ; 
    while(src_idx < n){
        int old_diff = abs(src[src_idx] - dest[dest_idx]); 
        while(1){
            if(dest_idx + 1 >= n)
                break; 
            int diff = abs(src[src_idx] - dest[dest_idx+1]);
            if(diff < old_diff){
                old_diff = diff; 
                dest_idx++; 
            }
            else
                break; 
        }
        near[src_idx] = dest_idx; 
        src_idx++; 
    }
    cout << "setNear" << endl; 
    for(int i = 0; i < n; i++){
        cout << src[i] << " = " << dest[near[i]] << endl; 
    }
}

void init(int n){
    As = new int[n]; 
    Bs = new int[n]; 
    Aused = new bool[n]; 
    Bused = new bool[n]; 
    Anear = new int[n]; 
    Bnear = new int[n]; 
    matchResult = new int[n]; 

    int tmp; 
    for(int i = 0; i < n; i++){
        cin >> tmp; 
        As[i] = tmp; 
    }
    for(int i = 0; i < n; i++){
        cin >> tmp; 
        Bs[i] = tmp; 
    }

    sort(As, As+n); 
    sort(Bs, Bs+n); 
    memset(Aused, 0, n); 
    memset(Bused, 0, n);
    setNear(As, Bs, Anear); 
    setNear(Bs, As, Bnear);   
    memset(matchResult, -1, sizeof(int)*n); 
}

void end(){
    free(As); 
    free(Bs); 
    free(Aused); 
    free(Bused); 
    free(Anear); 
    free(Bnear); 
    free(matchResult);
}

int getNext(bool isA, int next){
    bool* used = Aused;
    int* values = As; 
    if(isA == false){
        used = Bused; 
        values = Bs; 
    } 
    if(used[next] == false)
        return next; 

    int move = 1; 
    while(1){
        int p_diff = MAX; 
        int m_diff = MAX; 
        int more = next + move; 
        int less = next - move; 
        if(more > n){
            more -= more; 
        }
        if(less < 0){
            more += more; 
        }
        if(used[more] == false)
            p_diff = abs(values[next +move] - values[next]); 
        if(used[less] == false)
            m_diff = abs(values[next] - values[less]); 
        if(p_diff == MAX && m_diff == MAX) 
             move++; 
        if(p_diff > m_diff)
            return more; 
        else
            return less; 
    }
}

bool match(bool A2B, int prev, int here){
    if(A2B){ //B->A->B
        if(prev == Anear[here]){
            Aused[here] = true; 
            Bused[prev] = true; 
            matchResult[here] = prev; 
            return true; 
        }
        else{
            go(!A2B, here); 
        }
    }
    else{ //A->B->A
        if(prev == Bnear[here]){
            Bused[here] = true;
            Aused[prev] = true; 
            matchResult[prev] = here; 
            return true; 
        }
        else{
            go(!A2B, here); 
        }
    }
}

int go(bool A2B, int start){
    int next = 0; 
    if(A2B){ //A=>B
        next = getNext(A2B, Anear[start]); 
        while(!match(!A2B, start, next)){
            next = getNext(A2B, Anear[start]); 
        }
    }
    else{ // B=> A 
        next = getNext(A2-move, Bnear[start]); 
        while(!match(!A2B, start, next)){
            next = getNext(A2B, )
        }
    }
    match(false, start, )
}

ll solve(){
    cin >> n; 
    init(n); 

    for(int i = 0; i < n; i++){
        int next = Anear[i]; 
        if(Aused[i] == true)
            continue; 
        while(match(false, i, next, "") != i){
            next = getNext(true, i); 
        }
    }    
    for(int i = 0; i < n; i++){
        cout << "A(" << As[i] << ") == B(" << Bs[matchResult[i]] << ")" << endl; 
    }

    end();
    return 0; 
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        Answer = solve(); 
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}