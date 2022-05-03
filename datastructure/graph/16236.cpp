//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
//#include <cmath>
//#include <algorithm>
//#include <string>

using namespace std;

/*
scanf, printf 쓰기.

cout 을 쓸때는 꼭 endl 말고 \n 쓰기.

아니면 밑에꺼 꼭 쓰기, 시간 개걸림.

*/



/*
범위 때문에 문제 안풀릴때는, 

index 0은 무시하고 1부터 시작해보기.. 은근 저거때문에 화날때가 많은거같음...
*/



/*
꼭 데이터 범위 확인하기!!
long long 범위 잘 확인해서 풀기.
*/
//typedef long long ll;


//자주 쓸 데이터들
//vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int map[20][20];

int check_fish(int n, int m, int shark){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if ((map[i][j] <= shark) &&(map[i][j] != 0)){
                return 1;
            }
        }
    }
    return 0;
}

int bfs(int x, int y, int n, int m){
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    
    int res = 0;
    pair<int, int> shark = make_pair(2, 0);
    pair<int, int> start = make_pair(x, y);

    pair<int, int> check = make_pair(0, 0);
    while(check_fish(n, m, shark.first)){
        queue<pair<int, int>> q;
        q.push(start);
        check.first = start.first; check.second = start.second;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[start.first][start.second] = 1;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && map[nx][ny] <= shark.first){
                    visited[nx][ny] = visited[cur.first][cur.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        int fish[3];
        fish[0] = 10000;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] < shark.first&& map[i][j] != 0 && visited[i][j] != 0){
                    if(visited[i][j] < fish[0]){
                        fish[0] = visited[i][j];
                        fish[1] = i;
                        fish[2] = j;    
                    }
                }
            }
        }
        if(fish[0] == 10000){
            break;
        }
        else{
            res += visited[fish[1]][fish[2]]-1;
            shark.second++;
            if(shark.first == shark.second){
                shark.first++;
                shark.second = 0;
            }
            start.first = fish[1];
            start.second = fish[2];
            map[fish[1]][fish[2]] = 0;
        }
        
    }
    return res;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n; scanf("%d", &n);
    int sx, sy = 0;
    int size = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                sx = i;
                sy = j;
                map[i][j] = 0;
            }
        }
    }

    printf("%d\n", bfs(sx, sy, n, n));

    int result = 0;
	
}
