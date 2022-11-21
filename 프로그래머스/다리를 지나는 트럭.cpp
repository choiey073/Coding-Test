#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
    int idx = 0;    // 차량 지목용 인덱스
    int sum = 0; // 다리에 올라와있는 차량들의 무게
    queue <int> q;  // 현재 다리를 건너는 트럭 체크
    
    while(1){
        
        if(idx == truck_weights.size()){ // 마지막 트럭인 경우
            answer += bridge_length;    // 마지막 트럭이 지나가는 시간 추가
            break;
        }
        
        answer++; // 시간초 증가
        
        // 차가 다리를 다 건넌 경우
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        
        // 다리에 다음 차가 진입 가능하다면
        if(sum + truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        // 진입이 불가하다면 0을 push함으로서 시간초 계산
        else{
            q.push(0);
        }
    }
    return answer;
}