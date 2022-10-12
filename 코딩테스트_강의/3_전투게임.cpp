#include <bits/stdc++.h>
using namespace std;
//백준 컬러볼과 유사 문제

// 학생 구조체
struct Student { 
	int num, power;
	char team;
	Student(int a, int b, int c) {
		num = a;
		team = b;
		power = c;
	}
	bool operator < (const Student& b)const {	// power를 기준으로 오름차순 정렬
		return power < b.power;
	}
};

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	int n, sum=0;
	cin >> n;	// 학생수
	vector<int> result(n);	// 결과값 벡터
	vector<Student> st;		// 구조체 벡터
	unordered_map<char, int> team;	// 팀 점수 누적할 hash map
	
	for (int i = 0; i < n; i++) {
		char t;
		int p;
		cin >> t >> p;
		st.push_back(Student(i, t, p));
	}
	sort(st.begin(), st.end());

	int j = 0;
	for (int i = 1; i < n; i++) {	// i==0 일때는 result=0 이므로 i는 1부터 시작
		for (; j < i; j++) {		// j도 결국 n번밖에 안도는거.
			if (st[i].power > st[j].power) {	// 공격력이 더 크다면
				sum += st[j].power;				// 사로잡을 수 있으므로 누적 점수에 더해준다.
				team[st[j].team] += st[j].power;// 잡힌 학생이 속하는 해당 team의 점수에도 누적해준다.
			}
			else {
				break;
			}
		}
		// 해당 학생 번호에 (누적 점수 - 해당 팀 점수) 결과를 넣어준다.
		result[st[i].num] = sum - team[st[i].team];
		
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}