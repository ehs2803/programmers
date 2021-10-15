// level2
// 성공. dfs로 하면 시간초과로 실패. bfs하면 성공.
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > map;
int map_cnt[100][100];
bool check[100][100];
int n,m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(){
    int cnt=1;
    queue<pair<int, pair<int,int>> > q;
    q.push({cnt,{0,0}});
    check[0][0]= true;
    map_cnt[0][0]=cnt;
    cnt++;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int ocnt = q.front().first;
        q.pop();


        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = ocnt+1;

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(map[nx][ny]==0) continue;
            if(check[nx][ny]) continue;

            map_cnt[nx][ny]=ncnt;
            check[nx][ny]= true;
            q.push({ncnt,{nx,ny}});
        }

    }
}

int solution(vector<vector<int> > maps)
{
    map=maps;
    n=maps.size();
    m=maps[0].size();

    bfs();

    int answer = 0;
    if(map_cnt[n-1][m-1]==0) answer=-1;
    else answer=map_cnt[n-1][m-1];
    return answer;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.27MB)
테스트 2 〉	통과 (0.01ms, 4.32MB)
테스트 3 〉	통과 (0.01ms, 3.67MB)
테스트 4 〉	통과 (0.01ms, 3.66MB)
테스트 5 〉	통과 (0.01ms, 3.63MB)
테스트 6 〉	통과 (0.01ms, 3.68MB)
테스트 7 〉	통과 (0.01ms, 4.33MB)
테스트 8 〉	통과 (0.01ms, 4.26MB)
테스트 9 〉	통과 (0.01ms, 4.27MB)
테스트 10 〉	통과 (0.01ms, 4.21MB)
테스트 11 〉	통과 (0.01ms, 4.27MB)
테스트 12 〉	통과 (0.01ms, 4.27MB)
테스트 13 〉	통과 (0.01ms, 4.32MB)
테스트 14 〉	통과 (0.01ms, 4.27MB)
테스트 15 〉	통과 (0.01ms, 4.33MB)
테스트 16 〉	통과 (0.01ms, 4.34MB)
테스트 17 〉	통과 (0.02ms, 3.66MB)
테스트 18 〉	통과 (0.01ms, 4.32MB)
테스트 19 〉	통과 (0.01ms, 4.33MB)
테스트 20 〉	통과 (0.02ms, 4.27MB)
테스트 21 〉	통과 (0.01ms, 4.33MB)
효율성  테스트
테스트 1 〉	통과 (0.20ms, 4.17MB)
테스트 2 〉	통과 (0.21ms, 4.18MB)
테스트 3 〉	통과 (0.36ms, 4.11MB)
테스트 4 〉	통과 (0.30ms, 4.09MB)
 */

/*
#include<vector>
using namespace std;

vector<vector<int> > map;
bool check[100][100];
int n,m;

void dfs(int x, int y, int cnt){
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(map[x][y]==0) return;


    if(check[x][y]==true && map[x][y]<cnt) return;

    map[x][y]=cnt;
    check[x][y]= true;

    dfs(x + 1, y, cnt+1);
    dfs(x, y + 1, cnt+1);
    dfs(x - 1, y, cnt+1);
    dfs(x, y - 1, cnt+1);
}

int solution(vector<vector<int> > maps)
{
    map=maps;
    n=maps.size();
    m=maps[0].size();

    dfs(0,0,1);

    int answer = 0;
    if(map[n-1][m-1]==1) answer=-1;
    else answer=map[n-1][m-1];
    return answer;
}
 정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.32MB)
테스트 2 〉	통과 (0.01ms, 4.27MB)
테스트 3 〉	통과 (0.01ms, 4.27MB)
테스트 4 〉	통과 (0.01ms, 4.33MB)
테스트 5 〉	통과 (0.01ms, 4.33MB)
테스트 6 〉	통과 (0.01ms, 3.66MB)
테스트 7 〉	통과 (0.01ms, 4.27MB)
테스트 8 〉	통과 (0.01ms, 4.29MB)
테스트 9 〉	통과 (0.01ms, 4.32MB)
테스트 10 〉	통과 (0.02ms, 4.32MB)
테스트 11 〉	통과 (0.01ms, 4.27MB)
테스트 12 〉	통과 (0.01ms, 4.28MB)
테스트 13 〉	통과 (0.01ms, 4.27MB)
테스트 14 〉	통과 (0.01ms, 4.32MB)
테스트 15 〉	통과 (0.01ms, 4.27MB)
테스트 16 〉	통과 (0.01ms, 4.2MB)
테스트 17 〉	통과 (0.01ms, 4.32MB)
테스트 18 〉	통과 (0.01ms, 4.33MB)
테스트 19 〉	통과 (0.01ms, 4.33MB)
테스트 20 〉	통과 (0.01ms, 4.21MB)
테스트 21 〉	통과 (0.01ms, 4.32MB)
효율성  테스트
테스트 1 〉	실패 (시간 초과)
테스트 2 〉	실패 (시간 초과)
테스트 3 〉	실패 (시간 초과)
테스트 4 〉	실패 (시간 초과)
*/