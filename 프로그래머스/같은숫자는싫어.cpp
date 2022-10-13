#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    /*
    아래 두줄로 한번에 풀 수 있음.

    // unique begin~end 연속 중복 원소 제거
    // erase : 중복되는 지점 첫 이터레이터 ~ arr.end(마지막 이터레이터) 제거
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); 
    vector<int> answer = arr;
    */

    
    vector<int> answer;
    
    answer.push_back(arr[0]);
    for(int i =1;i<arr.size();i++){
        if(arr[i-1]!=arr[i]) answer.push_back(arr[i]);
    }
    
    return answer;
}