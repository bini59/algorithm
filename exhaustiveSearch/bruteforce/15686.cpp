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
#define MAX 987654321

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int sol(vector<int> visit, int K, int N, int stair){
    if(stair == N){
        // printf("\n\n%d %d %d\n", N, K, stair);
        // printVector(visit);
        int result = 0;
        for(int i = 0; i < (int)house.size(); i++){
            int temp = MAX;
            for(int j = 0; j < (int)chicken.size(); j++){
                if(!visit[j]){
                    continue;
                }
                // printf("%d %d %d %d\n", house[i].first, house[i].second, chicken[j].first, chicken[j].second);
                int x = 0;
                x += max(chicken[j].first, house[i].first) - min(chicken[j].first, house[i].first);
                x += max(chicken[j].second, house[i].second) - min(chicken[j].second, house[i].second);
                if (x < temp) temp = x;
            }
            result += temp;
        }
        // printf("\n");
        return result;
    }
    int result = MAX;
    for(int i = K; (i < 1+K+(int)chicken.size()-N) && (i < (int)chicken.size()); i++){
        visit[i] = 1;
        result = min(result, sol(visit, i+1, N, stair+1));
        visit[i] = 0;
    }

    return result;
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; i++){
        int temp;
        for(int j = 0; j < n; j++) {
            scanf("%d", &temp);
            if(temp == 1) house.push_back({i, j});
            if(temp == 2) chicken.push_back({i, j});
        }
    }

    vector<int> visit = vector<int>((int)chicken.size(), 0);
    printf("%d", sol(visit, 0, m, 0));

    
	int result = 0;
	
}