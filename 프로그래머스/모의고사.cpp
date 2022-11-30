#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[5] = {1,2,3,4,5}; //  5
    int two[8] = {2,1,2,3,2,4,2,5};   // 8
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};    // 10
    
    vector <int> score(3);  // 점수
    
    for(int i = 0; i<answers.size();i++){
        if(one[i % 5] == answers[i])   score[0]++;
        if(two[i % 8] == answers[i])   score[1]++;
        if(three[i % 10] == answers[i])   score[2]++;
    }
    
    int max_score = *max_element(score.begin(), score.end());
    cout << score[0];
    
    for(int i =0;i<3;i++){
        if(score[i] == max_score)   answer.push_back(i+1);
    }
        
    return answer;
}