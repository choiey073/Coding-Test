#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue< pair<int,int> > q;
    priority_queue <int> pq;    // 우선순위 큐

    for(int i =0;i<priorities.size();i++){
        q.push({priorities[i],i});    // (i번째 원소의 우선순위, i번째 원소)
        pq.push(priorities[i]); // i번째 원소의 우선순위만 넣어주기
    }
    
    while(!q.empty() && !pq.empty()){
        if(q.front().first == pq.top()){    // q의 우선순위와 pq의 우선순위가 같다면
            answer++;
            if(q.front().second == location){   // q의 현재 front와 location이 같으면 return
                return answer;
            }
            q.pop();
            pq.pop();
        }
        else{
            // 해당 원소 맨 뒤로 보내기
            q.push({q.front().first, q.front().second});
            q.pop();
        }
    }
}