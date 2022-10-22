#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    string str, result;
    cin >> str;

    transform(str.begin(), str.end(),str.begin(), ::toupper);

    // 해당 알파벳의 남은 개수, 사용 여부 체크하는 hash map
    unordered_map <char, int> rest, check;
    
    for (auto x : str)   rest[x]++;

    for (auto x : str) {
        rest[x]--;  // 해당 문자열을 사용하므로 남은 개수 -1
        if (check[x] == 1) {    // 해당 문자열이 이미 사용되고 있다면
            continue;
        }
        while (result.size()!=0 && result.back()>x && rest[result.back()] > 0) {
            // 사전순 빠른 단어로 넣기 &&  남아있는 단어가 있을 때 교환
            check[result.back()] = 0;   // 해당 문자열이 사용 안된 상태로 바꿔주고
            result.pop_back();          // 해당 문자열 빼기
        }
        result.push_back(x);    // 더 빠른 문자열 넣어주기
        check[x] = 1;           // 문자열 사용했다고 check
    }
    cout << result;

    return 0;
}