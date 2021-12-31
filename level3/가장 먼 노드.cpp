#include <string>
#include <vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<int> graph[20001];
int dist[20001];

void dijkstra(int start){
    priority_queue<pair<int , int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now]<d) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = d + 1;
            if(cost< dist[graph[now][i]]){
                dist[graph[now][i]] = cost;
                pq.push({cost, graph[now][i]});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {

    fill(dist, dist+n+1, INF);

    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    dijkstra(1);

    int answer = 0;
    int best=-1;
    for(int i=1;i<=n;i++){
        if(dist[i]>best) best=dist[i];
    }
    for(int i=0;i<=n;i++){
        if(dist[i]==best) answer++;
    }
    return answer;
}