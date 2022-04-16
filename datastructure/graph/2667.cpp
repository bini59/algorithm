//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
//#include <cmath>
#include <algorithm>
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

int map[25][25];
int visit[25][25];

vector<pair<int, int>> _move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    char a[26];
    FOR(n){
        scanf("%s", a);
        for(int j = 0; j < n; j++) map[i][j] = (a[j] == '1') ? 1 : 0;
        for(int j = 0; j < n; j++) visit[i][j] = 0;
    }
    queue<pair<int, int>> Q;
    vector<int> result;
    FOR(n){
        for(int j = 0; j < n; j++){
            if(map[i][j] && !visit[i][j]) {
                Q.push({i, j});
                result.push_back(1);
                visit[i][j] = 1;
            }

            while(!Q.empty()){
                pair<int, int> temp = Q.front(); Q.pop();
                
                for(int i = 0; i < 4; i++){
                    pair<int, int> loc = {temp.first+_move[i].first, temp.second+_move[i].second};
                    if(loc.first > -1 && loc.first < n && loc.second > -1 && loc.second < n){
                        if(!visit[loc.first][loc.second] && map[loc.first][loc.second]){
                            Q.push(loc);
                            visit[loc.first][loc.second] = 1; 
                            result[(int)result.size()-1]++;
                        }
                            
                    }
                }
            }
        }
    }

    printf("%d\n", (int)result.size());
	sort(result.begin(), result.end());
    FOR((int)result.size()) printf("%d\n", result[i]);
}