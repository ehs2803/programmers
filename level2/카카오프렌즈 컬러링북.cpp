// level2
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check[100][100];

int bfs(vector<vector<int>> &picture, int sx, int sy, int color,int m, int n){
    int size_of_one_area=0;
    queue<pair<int,int>> q;

    q.push({sx,sy});
    check[sx][sy]= true;
    size_of_one_area++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(picture[nx][ny]!=color) continue;
            if(check[nx][ny]) continue;

            q.push({nx,ny});
            check[nx][ny]= true;
            size_of_one_area++;
        }

    }

    return size_of_one_area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) check[i][j]= false;
    }
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]== false && picture[i][j]!=0){
                number_of_area++;
                cout<<i<<' '<<j<<endl;
                int area_size = bfs(picture, i, j, picture[i][j],m,n);
                if(area_size> max_size_of_one_area) max_size_of_one_area=area_size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
/*
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<int>> &picture, bool **check, int sx, int sy, int color, int m, int n){
    int size_of_one_area=0;
    queue<pair<int,int>> q;

    q.push({sx,sy});
    check[sx][sy]= true;
    size_of_one_area++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(picture[nx][ny]!=color) continue;
            if(check[nx][ny]) continue;

            q.push({nx,ny});
            check[nx][ny]= true;
            size_of_one_area++;
        }

    }

    return size_of_one_area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    bool **check = new bool*[100];
    for(int i=0;i<100;i++) check[i]=new bool[100];
    fill(&check[0][0], &check[m-1][n-1], false);
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]== false && picture[i][j]!=0){
                number_of_area++;
                cout<<i<<' '<<j<<endl;
                int area_size = bfs(picture, check, i, j, picture[i][j],m,n);
                if(area_size> max_size_of_one_area) max_size_of_one_area=area_size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
*/
/*
테스트 1 〉	통과 (2.70ms, 4.33MB)
 */