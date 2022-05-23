//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
#include <cmath>
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
vector<vector<int>> sum_prime; // 2차원 배열
vector<int> ary; // 1차원 배열
vector<int> res = vector<int>(0);

//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)
#define MAX 3000

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void sol(vector<int> &visit, queue<int> q){
    while(1){
        if(q.empty()) break;
        if(!visit[q.front()]) break;
        q.pop();
    }

    if(q.empty()){
        for(int i = 0; i < (int)visit.size(); i++){
            if(visit[i] == 2) res.push_back(ary[i]);
        }
        return;
    }
    int idx = q.front();
    // printf("idx : %d\n", idx);
    visit[idx] = 1;
    // printVector(visit);
    for(int i = 0; i < (int)sum_prime[idx].size(); i ++){
        // printf("idx : %d i : %d\n", idx, i);
        if(visit[sum_prime[idx][i]]) continue;
        visit[sum_prime[idx][i]] = 1;
        sol(visit, q);
        visit[sum_prime[idx][i]] = 0;
    }
}




int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    ary = vector<int>(n, 0);
    FOR(n){
        scanf("%d", &ary[i]);
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        q.push(i);
    }
        

    vector<int> prime = vector<int>(MAX, 1);
    prime[0] = prime[1] = 0;
    for(int i = 0; i < (int)sqrt(MAX); i++){
        if(prime[i]){
            for(int j = i*i; j < MAX; j += i){
                prime[j] = 0;
            }
        }
    }

    sum_prime = vector<vector<int>>(n, vector<int>(0));
    for(int i = 0; i < n-1; i ++){
        for(int j = i+1; j < n; j++){
            if(i == j) continue;
            if(prime[ary[i]+ary[j]]){
                sum_prime[i].push_back(j);
                sum_prime[j].push_back(i);
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     printVector(sum_prime[i]);
    // }
    vector<int> tmp = vector<int>(n, 0);
    tmp[0] = 1;
    for(int i = 0; i < (int)sum_prime[0].size(); i++){
        tmp[sum_prime[0][i]] = 2;
        sol(tmp, q);
        for(int j = 1; j < n; j++){
            tmp[j] = 0;
        }
    }

    printVector(res);   
	
}