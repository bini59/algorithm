//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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


// print Vector<int>
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// print Array<int>
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int map[10][10];

int bfs(pair<int, int> size){

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    int virus[10][10];
    memcpy(virus, map, sizeof(int)*10*10);
    int res = 0;
    int visited[10][10] = {0};
    queue<int> q;

    for (int i = 0; i < size.first; i++){
        for (int j = 0; j < size.second; j++){
            if(virus[i][j] == 2 && !visited[i][j]){
                q.push(i * 10 + j);
                visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front() / 10;
                    int y = q.front() % 10;
                    q.pop();

                    for (int k = 0; k < 4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < size.first && ny >= 0 && ny < size.second){
                            if(!virus[nx][ny] && !visited[nx][ny]){
                                visited[nx][ny] = 1;
                                virus[nx][ny] = 2;
                                q.push(nx * 10 + ny);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < size.first; i++){
        for (int j = 0; j < size.second; j++){
            if(!virus[i][j])
                res++;
        }
    }
    return res;
}

int makeWall(int k, int wall, pair<int, int> size){
    int res = 0;
    if(k == 3){
        if(wall)
            return 0;

        return bfs(size);
    }
    for (int i = 0; i < size.first; i++){
        for (int j = 0; j < size.second; j++){
            if(!map[i][j]){
                map[i][j] = 1;
                res = max(res, makeWall(k + 1, wall - 1, size));
                map[i][j] = 0;
            }
        }
    }
    return res;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }


    int result = makeWall(0, 3, make_pair(n, m));

    printf("%d", result);
}