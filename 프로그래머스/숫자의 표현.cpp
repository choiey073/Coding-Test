#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    // n 자체로 답은 이미 1개 있음
    int answer = 1;
    
    // n의 절반까지만 반복문 돌리면 됨.
    for(int i =1;i<=n/2;i++){
        int sum = i;
        // i부터 j까지 더하기
        for(int j = i+1; j<n;j++){
            sum += j;
            if(sum == n)
                answer++;
            else if(sum > n)
                break;
        }
    }
    
    return answer;
}