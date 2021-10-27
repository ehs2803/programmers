// level2
// 성공. 최단거리 - 다익스트라, map
#include <iostream>
#include <vector>
#include <map>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;

// 각 노드에 연결되어 있는 노드를 담는 배열
vector<pair<int,int> > graph[51];
// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[51];
// 최단 거리 테이블 만들기
int d[51];

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int getSmallestNode(int n) {
    int min_value = INF;
    int index = 0; // 가장 최단 거리가 짧은 노드
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

// 다익스트라 알고리즘
void dijkstra(int start, int n) {
    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }
    // 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
    for (int i = 0; i < n - 1; i++) {
        // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = getSmallestNode(n);
        visited[now] = true;
        // 현재 노드와 연결된 다른 노드를 확인
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    fill_n(d,51,INF);
    fill_n(visited,51,false);

    map<pair<int,int>,int> m;
    for(int i=0;i<road.size();i++){
        int cost = road[i][2];
        int x = min(road[i][0], road[i][1]);
        int y = max(road[i][0], road[i][1]);
        if(m.find({x,y})!=m.end()){
            int c = m[{x,y}];
            if(c>cost) m[{x,y}]=cost;
        }
        else {
            m.insert({{x, y}, cost});
        }
    }
    map<pair<int,int>,int>::iterator iter;
    for(iter = m.begin(); iter!=m.end(); iter++){
        graph[(*iter).first.first].push_back({(*iter).first.second, (*iter).second});
        graph[(*iter).first.second].push_back({(*iter).first.first, (*iter).second});
    }

    dijkstra(1,N);

    int answer = 0;
    for(int i=1;i<=N;i++) cout<<d[i]<<' ';
    for(int i=1;i<=N;i++){
        if(d[i]<=K) answer++;
    }

    return answer;
}
/*
테스트 1 〉	통과 (0.03ms, 4.32MB)
테스트 2 〉	통과 (0.02ms, 4.32MB)
테스트 3 〉	통과 (0.03ms, 3.66MB)
테스트 4 〉	통과 (0.02ms, 4.26MB)
테스트 5 〉	통과 (0.04ms, 3.66MB)
테스트 6 〉	통과 (0.02ms, 4.32MB)
테스트 7 〉	통과 (0.02ms, 4.34MB)
테스트 8 〉	통과 (0.02ms, 4.28MB)
테스트 9 〉	통과 (0.02ms, 4.34MB)
테스트 10 〉	통과 (0.03ms, 3.69MB)
테스트 11 〉	통과 (0.03ms, 4.27MB)
테스트 12 〉	통과 (0.05ms, 3.69MB)
테스트 13 〉	통과 (0.04ms, 4.26MB)
테스트 14 〉	통과 (0.26ms, 4.33MB)
테스트 15 〉	통과 (0.38ms, 4.27MB)
테스트 16 〉	통과 (0.03ms, 4.33MB)
테스트 17 〉	통과 (0.04ms, 4.21MB)
테스트 18 〉	통과 (0.13ms, 4.33MB)
테스트 19 〉	통과 (0.60ms, 4.26MB)
테스트 20 〉	통과 (0.12ms, 4.33MB)
테스트 21 〉	통과 (0.64ms, 4.19MB)
테스트 22 〉	통과 (0.17ms, 4.27MB)
테스트 23 〉	통과 (0.51ms, 4.33MB)
테스트 24 〉	통과 (0.42ms, 4.33MB)
테스트 25 〉	통과 (0.61ms, 4.25MB)
테스트 26 〉	통과 (0.65ms, 4.33MB)
테스트 27 〉	통과 (0.61ms, 4.27MB)
테스트 28 〉	통과 (0.71ms, 4.28MB)
테스트 29 〉	통과 (0.64ms, 4.33MB)
테스트 30 〉	통과 (0.64ms, 4.34MB)
테스트 31 〉	통과 (0.04ms, 4.32MB)
테스트 32 〉	통과 (0.06ms, 4.27MB)
 */