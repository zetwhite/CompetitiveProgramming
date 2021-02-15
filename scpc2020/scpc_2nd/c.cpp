#include <iostream>
#include <algorithm> 
#include <cstring>
#include <queue>
#include <set>
using namespace std;

int Answer;

void update(multiset<int>& maxHeap, multiset<int>& minHeap, int del, int val){
        if(*maxHeap.rbegin() >= del){
            auto iter = maxHeap.find(del);
            if(iter != maxHeap.end())
                maxHeap.erase(iter); 
        }
        else{
            auto iter = minHeap.find(del); 
            if(iter != minHeap.end()) 
                minHeap.erase(iter); 
        }
        if(maxHeap.size() == 0){
            int mov = *minHeap.begin(); 
            minHeap.erase(minHeap.begin()); 
            maxHeap.insert(mov); 
        }

        if((*maxHeap.rbegin()) > val)
            maxHeap.insert(val); 
        else 
            minHeap.insert(val); 
        
        if(maxHeap.size() < minHeap.size()){
            int mov = *minHeap.begin(); 
            minHeap.erase(minHeap.begin()); 
            maxHeap.insert(mov); 
        }
        else if(maxHeap.size() > minHeap.size() + 1){
            auto last = maxHeap.end(); 
            last --; 
            int mov = *last; 
            maxHeap.erase(last);
            minHeap.insert(mov); 
        }
}

void init(multiset<int>& maxHeap, multiset<int>& minHeap, int* paid, int size){
    maxHeap.insert(paid[0]); 
    for(int i = 1; i < size; i++){
        update(maxHeap, minHeap, -1, paid[i]); 
    }
}

void printMedian(multiset<int>& maxHeap, multiset<int>& minHeap){
   /* cout << "==================" << endl; 
    for(auto it = maxHeap.begin(); it != maxHeap.end(); it++){
        cout << *it << " "; 
    }
    cout << endl; 
    cout << "==================" << endl; 
    for(auto it = minHeap.begin(); it != minHeap.end(); it++){
        cout << *it << " ";
    }
    cout << endl; 

    cout << "middle = "; */
    if(maxHeap.size() == minHeap.size())
        cout << *minHeap.begin() << " "; 
    else 
        cout << *maxHeap.rbegin() << " "; 
}

int solve(){
    multiset<int> maxHeap; 
    multiset<int> minHeap; 
    int n, k, q; 
    cin >> n >> k >> q;  

    int pay[n]; 
    int paid[n-k+1];
 
    for(int i = 0; i < n; i++){
        cin >> pay[i]; 
    } 

    int sum = 0; 
    for(int j = 0; j < k; j++){
        sum += pay[j]; 
    }
    paid[0] = sum; 
    for(int i = 1; i < n-k+1; i++){
        paid[i] = paid[i-1] - pay[i-1] + pay[i+k-1];  
    }
    init(maxHeap, minHeap, paid, n-k+1);
    printMedian(maxHeap, minHeap); 
    //printMedian(tree, n-k+1); 

    int day, money ; 
    for(int i = 0; i < q; i++){
        cin >> day >> money; 
        day--; 
        int start = day - (k-1); 
        if(start < 0) 
            start = 0; 
        if(day > (n-k+1))
            day = n-k; 
        int diff = money - pay[day]; 
        for(int j = start; j <= day; j++){
            //cout << "old = " << paid[j] << endl; 
            //cout << "update = " << paid[j] + diff << endl; 
            update(maxHeap, minHeap, paid[j], paid[j] + diff); 
            paid[j] += diff; 
        } 
        printMedian(maxHeap, minHeap); 

    }
    return 0; 
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cout << "Case #" << test_case+1 << endl;
        solve(); 
	}

	return 0;//Your program should return 0 on normal termination.
}