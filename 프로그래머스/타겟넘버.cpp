#include <string>
#include <vector>
using namespace std;

// DFS
int answer = 0;
void DFS(vector <int> numbers, int target, int sum, int index){
    // 종료조건
    if(index == numbers.size()){    // 마지막 원소까지 사용한 경우
        if(sum == target){          // 마지막 원소까지 사용하고, target과 값이 같은 경우
            answer ++;
        }
        return; // 마지막 원소까지 사용했지만 값이 다른 경우는 return
    }
    // 트리구조 DFS
    // 조건이 만족되지 않으면 계속 탐색
    DFS(numbers, target, sum + numbers[index], index+1);
    DFS(numbers, target, sum - numbers[index], index+1);
}


int solution(vector<int> numbers, int target) {
    
    // 처음에는 sum = 0,  index = 0
    DFS(numbers, target, 0,0);
    
    return answer;
}