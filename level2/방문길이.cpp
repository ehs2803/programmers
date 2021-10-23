// level2
// 성공. 구현, set자료형, "UDU"의 경우 가는 경로와 되돌아오는 경로를 같은 경로로 취급해야함.
#include <string>
#include <set>
using namespace std;


int solution(string dirs) {
    int cx=0, cy=0;
    set<pair<pair<int,int>,pair<int,int>>> s;

    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            if(cy==5) continue;
            s.insert({{cx,cy},{cx,cy+1}});
            s.insert({{cx,cy+1},{cx,cy}}); // 같은 경로 취급
            cy += 1;
        }
        else if(dirs[i]=='D'){
            if(cy==-5) continue;
            s.insert({{cx,cy},{cx,cy-1}});
            s.insert({{cx,cy-1},{cx,cy}}); // 같은 경로 취급
            cy -= 1;
        }
        else if(dirs[i]=='R'){
            if(cx==5) continue;
            s.insert({{cx,cy},{cx+1,cy}});
            s.insert({{cx+1,cy},{cx,cy}}); // 같은 경로 취급
            cx += 1;
        }
        else if(dirs[i]=='L'){
            if(cx==-5) continue;
            s.insert({{cx,cy},{cx-1,cy}});
            s.insert({{cx-1,cy},{cx,cy}}); // 같은 경로 취급
            cx -= 1;
        }
    }

    int answer = s.size()/2;
    return answer;
}
/*
테스트 1 〉	통과 (0.02ms, 4.31MB)
테스트 2 〉	통과 (0.01ms, 4.26MB)
테스트 3 〉	통과 (0.01ms, 4.32MB)
테스트 4 〉	통과 (0.05ms, 4.2MB)
테스트 5 〉	통과 (0.07ms, 4.27MB)
테스트 6 〉	통과 (0.02ms, 3.71MB)
테스트 7 〉	통과 (0.01ms, 4.32MB)
테스트 8 〉	통과 (0.02ms, 4.26MB)
테스트 9 〉	통과 (0.02ms, 4.27MB)
테스트 10 〉	통과 (0.02ms, 4.26MB)
테스트 11 〉	통과 (0.02ms, 4.27MB)
테스트 12 〉	통과 (0.04ms, 4.31MB)
테스트 13 〉	통과 (0.04ms, 4.32MB)
테스트 14 〉	통과 (0.03ms, 4.32MB)
테스트 15 〉	통과 (0.03ms, 4.27MB)
테스트 16 〉	통과 (0.11ms, 4.38MB)
테스트 17 〉	통과 (0.11ms, 3.66MB)
테스트 18 〉	통과 (0.13ms, 3.62MB)
테스트 19 〉	통과 (0.10ms, 4.26MB)
테스트 20 〉	통과 (0.11ms, 4.33MB)
 */