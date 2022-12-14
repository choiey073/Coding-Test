#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++)
    {
        int m = arr1[i]|arr2[i];
        string res = "";
        
        for(int j = 0; j<n;j++)
        {
            if(m%2 == 0)
                res = " " + res;
            else
                res = "#" + res;
            // 한칸씩 오른쪽으로 밀기(shift)
            m = m >> 1;
        }
        answer.push_back(res);
    }
    
    return answer;
}