#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    map <string, int> m;
    m[words[0]]++;
    
    for(int i =1; i< words.size();i++ ){
        if(words[i].front() != words[i-1].back() || m[words[i]] !=0 ){
            return {(i%n)+1, (i/n)+1};
        }
        m[words[i]]++;
    }
    return {0,0};
}