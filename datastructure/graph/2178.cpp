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

void printArray(int *arr, int _size){
	FOR(_size){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


int map[100][100];
int visit[100][100];

vector<pair<int, int>> _move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int n, m;
    scanf("%d%d", &n, &m);
    char a[101];
    for(int i = 0; i < n; i++){
        scanf("%s", a);
        for(int j = 0; j < m; j++){
            map[i][j] = (a[j] == '1') ? 1 : 0;
            visit[i][j] = 0;
        }
        // printArray(map[i], m);
    }
	int result = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    while(!q.empty()){
        pair<pair<int, int>, int> temp = q.front();
        q.pop();
        if((temp.first.first == n-1) && (temp.first.second == m-1)){
            result = temp.second;
            break;
        }
        for(int i = 0; i < 4; i++){
            pair<int, int> loc = {temp.first.first+_move[i].first, temp.first.second+_move[i].second};
            if(loc.first > -1 && loc.first < n && loc.second > -1 && loc.second < m){
                if(!visit[loc.first][loc.second] && map[loc.first][loc.second]){
                    q.push({loc, temp.second+1}); visit[loc.first][loc.second] =1;
                }
                    
            }
        }
    }

    printf("%d", result);
	
}