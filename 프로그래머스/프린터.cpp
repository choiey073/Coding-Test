#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    int d[10] = {0,};
    
    for(int i=0; i<priorities.size(); i++){
        q.push(i);
        d[priorities[i]]++;
    }
    
    bool flag = true;
    while(!q.empty()){
        flag = true;
        int n = q.front();
        q.pop();
        
        for(int i=priorities[n]+1; i<10; i++){
            if(d[i]!=0){
                flag = false;
                break;
            }
        }
        
        if(!flag){
            q.push(n);
        }
        else{
            answer++;
            d[priorities[n]]--;
            if(n == location) return answer;
        }
    }
}