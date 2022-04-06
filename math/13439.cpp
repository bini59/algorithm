//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
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
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)
#define MOD 1000000009

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%lld ", arr[i]);
	}

	printf("\n");
}


void tmp(){

}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n, k;
    scanf("%d%d", &n, &k);


    vector<vector<int>> pln = vector<vector<int>>(k, vector<int>(n, 1));
    for(int i = 1; i < k; i++){
        for(int j = 1; j < n; j++){
            pln[i][j] = ((pln[i][j-1])%MOD+(pln[i-1][j])%MOD)%MOD;
        }
        // printVector(pln[i]);
    }


    vector<int> ary = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    vector<pair<int, ll>> number;
    for(int i = 0; i < (int)ary.size(); i++){
        number.push_back({ary[i], 0});
    }
    for(int i = 2; i <= n; i++){
        int x = i;
        for(int j = 0; j < (int)ary.size(); j++){
            while((x > 0)&&!(x % ary[j])){
                // printf("%d ", x);
                number[j].second = (pln[k-1][n-i]+number[j].second)%MOD;
                x /= ary[j];
            }
        }
        if(x > 33){
            ary.push_back(x);
            number.push_back({x, pln[k-1][n-i]});
        }
        // printf("\n");
    }
	ll result = 1;
    for(int i = 0; i < (int)number.size(); i++){
        // printf("%d ",number[i].second+1);
        result = (result*((number[i].second+1)%MOD))%MOD; 
    }
    printf("%lld", result);
	
    // printVector(ary);
}