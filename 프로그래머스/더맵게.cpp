#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue <int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    // 우선순위 큐 생성
    // greater이면 min heap(가장 앞 부분에 가장 낮은 값이 온다.)
    // s.begin()부터 s.end()까지 push해주는 것과 동일
    
    while(pq.size()>1 && pq.top()<K) { // 크기 1 이면 탈출하며 top이 K보다 크면 탈출
        int one = pq.top(); // 첫 번째로 작은 값
        pq.pop();
        int two = pq.top(); // 두 번째로 작은 값
        pq.pop();
        int scoville = one + (two*2); 
        pq.push(scoville);      // 우선순위 큐에 PUSH 
        answer++;               // 최소 횟수 증가
    }
    
    if(pq.top()<K) return -1;
    else return answer; // 모든 요소가 K 이상이면 최소 횟수 return
    
    
    return answer;
}