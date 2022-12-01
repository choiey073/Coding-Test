#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size()/2;
    set <int> s;
    for(int i=0; i<nums.size(); i++){
        s.insert(nums[i]);
    }
    if(s.size() <= n){
        answer = s.size();
    }
    else{
        answer = n;
    }
    
    return answer;
}