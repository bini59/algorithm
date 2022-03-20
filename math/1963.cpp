//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
#include <cmath>
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
typedef long long ll;


//자주 쓸 데이터들
//vector<vector<int>> pln; // 2차원 배열
vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)

typedef struct g{
	int n;
	vector<struct g*> childs;
}node;

int bfs(vector<node> &graph, int size, int target, int start){
	int result = 1000000000;

	vector<bool> visited(size, false);
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[q.front().first] = true;

	while(!q.empty()){
		pair<int, int> temp = q.front();
		q.pop();
		for(int i = 0; i < (int)graph[temp.first].childs.size(); i++){
			int t = graph[temp.first].childs[i]->n;
			// if(t > size) continue;
			// printf("%d %d  ", t, target);
			if(t == target && !visited[t]){
				// printf("%d ", t);
				if(temp.second+1 < result){
					result = temp.second + 1;
					continue;
				}
			}
			if(!visited[t]){
				q.push({t, temp.second+1});
				visited[t] = true;
			}
		}
	}
	if(result  == 1000000000) result = -1;

	return result;
}

// 벡터 표시기(int)
void printVector(vector<node> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i].n);
	}

	printf("\n");
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

	int n = 10000;

    ary = vector<int>(n+1, 1);

    for(int i = 2; i < (int)(sqrt(n)+2); i++){
        if(ary[i] == 1){
            for(int j = i*i; j < n+1; j= j+i){
                ary[j] = 0;
            }
        }
    }
    ary[0] = ary[1] = 0;


	vector<node> graph = vector<node>(10000, {0, {}});
	for(int i = 1000; i < 10000; i++){
		if(ary[i]) {
			graph[i].n = i;
			// printf("%d ", graph[i].n);
		}
		
	}
	for(int i = 1000; i < 10000; i++) {
		if(ary[i]){
			vector<struct g*> tmp;
			int a[4] = {i/1000, (i/100)%10, (i/10)%10, i%10};
// 			printf("a : %d %d %d %d\n", a[0], a[1], a[2], a[3]);
			for(int j = 0; j < 4; j++){
				for(int k = j?0:1; k < 10; k++){
					if(k == a[j]) continue;
					int x = 0;
					for(int s = 0; s < 4; s++){
						x+= s == j ? k*(int)pow(10, 3-s) : a[s]*(int)pow(10, 3-s);
					}
					if(ary[x]) {
				// 	printf("%d, %d : %d\n", i, j, x);
						// printf("%d ", x);
						tmp.push_back(&graph[x]);
					}
				}
			}
			graph[i].childs = tmp;

		}	
	}
	// for(int i = 0; i < (int)graph[2017].childs.size(); i++){
	// 	printf("%d ", graph[2017].childs[0]->n);
	// }
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		int res = bfs(graph, 10000, b, a);
		if(a == b) res = 0;
		if(res != -1)
			printf("%d\n", res);
		else
			printf("Impossible\n");
	}

	return 0;
}
