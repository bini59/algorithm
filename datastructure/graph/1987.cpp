//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
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

int visit[26];
char map[20][20];

typedef struct _msize
{
    int R;
    int C;
}Msize;
typedef struct _loc
{
    int x;
    int y;
}Loc;



int _move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int k, Loc l, Msize m){
    int res = k;
    for(int i = 0; i < 4; i++){
        int mx = l.x+_move[i][0];
        int my = l.y+_move[i][1];
        if(mx > -1 && mx < m.R && my > -1 && my < m.C){
            if(!visit[map[mx][my]-'A']){
                visit[map[mx][my]-'A'] = 1;
                res = max(dfs(k+1, {mx, my}, m), res);
                visit[map[mx][my]-'A'] = 0;
            }
        }
    }
    return res;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int R, C;
    scanf("%d%d", &R, &C);
    char s[21];
    FOR(R){
        scanf("%s", s);
        for(int j = 0; j < C; j++){
            map[i][j] = s[j];
        }
    }
    visit[map[0][0]-'A'] = 1;

	int result = dfs(1, {0, 0}, {R, C});

    printf("%d", result);
	
}
