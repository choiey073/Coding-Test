#include <bits/stdc++.h>
using namespace std;

// 영화관 최초 방해 
// 시간 복잡도 관련 문제. 이중포문 돌리면 시간 복잡도가 O(n^2)
// stack을 사용해야함. Stack 사용시 시간 복잡도 O(n)
// 백준 사이트에서 '탑'이라는 문제 풀어보기☆
// 프로그래머스 - 주식가격

/*
input.txt

7
54 52 57 50 52 53 51

*/

int main() {
    ios_base::sync_with_stdio(false);   //동기화 비활성화 시켜 속도 높임.
    freopen("input.txt", "rt", stdin);
    // 내가 누구의 시청을 방해하는지 확인
    int n;
    cin >> n;
    
    stack<int> s;
    vector<int> h(n+1), result(n+1, 0);
    // h는 학생의 앉은 키, result는 결과값
    
	for(int i=1;i<n;i++){
	    cin >> h[i];
	}
	
	for(int i =n; i>=1;i--){
	    while(!s.empty() && h[i]<h[s.top()]){
    	    // stack이 비어있지 않을 때 + stack의 가장 위(top)의 학생의 방해학생일 때
	        result[s.top()]=i; // 결과 기록
	        s.pop();
	    }
	    s.push(i);
	}
	
	for(int i=1;i<n;i++){
	    cout << result[i] << " ";
	}
	
	return 0;
}