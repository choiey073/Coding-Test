#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size()/2; // N마리의 포켓몬 선택.
    set <int> s;
    for(int i = 0; i < nums.size(); i++){
        s.insert(nums[i]);
    }
    
    if(s.size() <= N){  // 선택해야하는 포켓몬보다 포켓몬 종류가 적은 경우
        answer = s.size();
        cout << answer;
    }
    else{   //  선택해야 하는 포켓몬이 포켓몬 종류보다 많은 경우
        answer = N;
    }
    
    return answer;
}