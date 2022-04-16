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

int map[100][100][100];

vector<vector<int>> _move = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n, m, H;
    scanf("%d%d%d", &n, &m, &H);
    queue<vector<int>> q;
    for(int h = 0; h < H; h++){
        FOR(m) for(int j = 0; j < n; j++) {
            scanf("%d", &map[h][i][j]);
            if(map[h][i][j] == 1){
                q.push({i, j, h, 1});
            }
            if(map[h][i][j]==0){
                map[h][i][j] = 987654321;
            }
        }
    }

    while(!q.empty()){
        vector<int> temp = q.front(); q.pop();
        for(int k = 0; k < 6; k++){
            vector<int> loc = {_move[k][0]+temp[0], _move[k][1]+temp[1], _move[k][2]+temp[2], temp[3]+1};
            if(loc[0] < m && loc[0] > -1 && loc[1] < n && loc[1] > -1 && loc[2] < H && loc[2] > -1){
                if(map[loc[2]][loc[0]][loc[1]] > loc[3]){
                    q.push(loc);
                    map[loc[2]][loc[0]][loc[1]] = loc[3];
                }
            }
        }
    }

    int check = 0;
    int result = 0;
    for(int h = 0; h < H; h++){
        FOR(m){
            for(int j = 0; j < n; j++){
                if(map[h][i][j] == 987654321) check++;
                else result = max(result, map[h][i][j]);
                // printf("%d ", map[h][i][j]);
            }
            // printf("\n");
        }
        // printf("\n");
    }
	result = (check) ? -1 : result-1;
    printf("%d", result);
	
}