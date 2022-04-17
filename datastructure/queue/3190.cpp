//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <deque>
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


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);


    int map[100][100];
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) map[i][j] = 0;
    int k; scanf("%d", &k);
    int an, am;
    for(int i = 0; i<k; i++){
        scanf("%d%d", &an, &am);
        map[an-1][am-1] = 2;
    }
    map[0][0] = 1;

    int second[10001] = {0};
    int l; scanf("%d", &l);
    int X; char c;
    for(int i = 0; i < l; i++){
        scanf("%d%c%c", &X, &c, &c);
        second[X] = (c =='D') ? 1 : 2;
    }

    int sec = 1;
    int move = 0;
    deque<pair<int, int>> dq;
    int x, y;
    x = y = 0;
    dq.push_back({x, y});
    map[x][y] = 1;
    int _move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(true){
        x += _move[move][0]; y += _move[move][1];
        // printf("x : %d y : %d size : %d\n", x, y, (int)dq.size());
        if(x < 0 || x >= n || y < 0 || y >= n){
            break;
        }
        if(map[x][y] == 2){
            map[x][y] = 1;
        }
        else if(map[x][y] == 1){
            break;
        }
        else{
            map[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        map[x][y] = 1;
        dq.push_front({x, y});
        if(second[sec] == 1){
            move = (move+1)%4;
        }
        else if(second[sec] == 2){
            move = (move+3)%4;
        }
        sec++;

    }
    printf("%d", sec);
	
}