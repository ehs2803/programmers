#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> graph[201];
int visited[201];

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n]=1;
    
    while(!q.empty()){
        int newN = q.front();
        q.pop();
        for(int i=0;i<graph[newN].size();i++){
            if(visited[graph[newN][i]]==0){
                q.push(graph[newN][i]);
                visited[graph[newN][i]]=1;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(i!=j && computers[i][j]==1){
                graph[i+1].push_back(j+1);
                //graph[j+1].push_back(i+1); // 주석해제해도 정답처리됨.
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
    
    int answer = 0;    
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            bfs(i);
            answer++;
        }
    }
    

    return answer;
}
//20220101