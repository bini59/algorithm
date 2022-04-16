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

int map[1000][1000];

vector<pair<int, int>> _move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    queue<vector<int>> q;

    FOR(m) for(int j = 0; j < n; j++) {
        scanf("%d", &map[i][j]);
        if(map[i][j] == 1){
            q.push({i, j});
        }
        // if(map[i][j]==0){
        //     map[i][j] = 987654321;
        // }
    }

    while(!q.empty()){
        int x = q.front()[0]; 
        int y = q.front()[1]; 
        q.pop();
        for(int k = 0; k < 4; k++){
            int move_x = _move[k].first+x;
            int move_y = _move[k].second+y;
            if(move_x < m && move_x > -1 && move_y < n && move_y > -1){
                if(map[move_x][move_y] == 0){
                    q.push({move_x, move_y});
                    map[move_x][move_y] = map[x][y]+1;
                }
            }
        }
    }

    int check = 0;
    int result = 0;
    FOR(m){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0) check++;
            else result = max(result, map[i][j]);
        }
    }
	result = (check) ? -1 : result-1;
    printf("%d", result);
	
}