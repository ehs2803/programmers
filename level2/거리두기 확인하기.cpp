// level2
// 성공. bfs, 구현
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool visit[5][5];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(vector<string> &map, int sx, int sy){
    int cnt=0;
    queue<pair<int, pair<int, int>> > q;
    q.push({cnt, {sx,sy}});
    visit[sx][sy]=true;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int c = q.front().first;
        q.pop();
        if(c==2) continue;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c+1;

            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(visit[nx][ny]==true || map[nx][ny]=='X') continue;
            if(nc>2) continue;

            if(map[nx][ny]=='P'){
                return false;
            }
            else{
                q.push({nc,{nx,ny}});
                visit[nx][ny]=true;
            }

        }

    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int t=0;t<places.size();t++){
        vector<string> place = places[t];
        bool check=true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j]=='P'){
                    //visit false로 초기화
                    fill(&visit[0][0], &visit[4][4], false);
                    //bfs
                    bool IsFar = bfs(place,i,j);
                    if(IsFar== false){
                        check= false;
                        //cout<<i<<' '<<j<<endl;
                        break;
                    }
                }
            }
            if(check== false) break;
        }
        if(check== false) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}
