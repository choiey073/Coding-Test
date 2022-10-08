#include <bits/stdc++.h>
using namespace std;

// 효율성을 O(n)으로
// 해쉬, 슬라이딩 윈도우

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    string S, T;    // S>T
    cin>>S>>T;    
    int cnt=0;
    unordered_map<char,int> sh, th; // S의 HashMap, T의 HashMap

    for(auto x:T) th[x]++;

    int L=T.size()-1;   // 맨 처음 sh의 길이
    for(int i=0; i<L;i++)   sh[S[i]]++;
    // T.size()-1개만큼만 sh map을 구현해놓음.
    // 여기서는 auto 아니라서 S[i]로 key값 직접 넣어줘야함.
        
    int lt=0;
    // 현재 sh의 index는 L-1까지 있음. rt는 L부터 돌아야함.
    for(int rt=L; rt<S.size(); rt++){
        sh[S[rt]]++;        // S[rt]를 key로 하여 sh의 value 추가
        if(sh==th)  cnt++;  // 두 맵이 같다면 count. map에 == 연산자 사용 가능.
        sh[S[lt]]--;    // S[lt]가 key인 곳은 value-1 해줘야함.
        
        if(sh[S[lt]]==0)    sh.erase(S[lt]);  //value가 0이면 해당 key 제거
        lt++;
    }
    
    cout << cnt;
    
    return 0;
}