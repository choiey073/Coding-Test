#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 위상정렬

int n, m;
int result[1001];
vector <int> map[1001]; // 해당 과목 수강 후 들어야 할 과목 정보
int degree[1001];   // 선수 과목의 개수
queue <int> q;

int main(void) {
   
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        degree[b]++;    // 해당 과목의 선수 과목 개수
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {   // 선수 과목이 없다면,
            q.push(i);  
            result[i] = 1;      // 1학기에 수강 가능.
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // queue에서 원소를 꺼내면서 연결된 간선들을 제거
        for (int i = 0; i < map[now].size(); i++) {
            int next = map[now][i];
            degree[next]--;
            if (degree[next] == 0) {
                q.push(next);
                result[next] = result[now] + 1; // 현재 과목보다 한 학기 늦게 들어야함.
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}