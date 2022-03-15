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
typedef long long ll;


//자주 쓸 데이터들
vector<vector<ll>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)
#define Mod 1000000007

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

vector<vector<ll>> matrix(vector<vector<ll>> s, vector<vector<ll>> t){
    vector<vector<ll>> tt = {{0, 0}, {0, 0}};
    tt[0][0] = (s[0][0]*t[0][0] + s[0][1]*t[1][0])%Mod;
    tt[0][1] = (s[0][0]*t[0][1] + s[0][1]*t[1][1])%Mod;
    tt[1][0] = (s[1][0]*t[0][0] + s[1][1]*t[1][0])%Mod;
    tt[1][1] = (s[1][0]*t[0][1] + s[1][1]*t[1][1])%Mod;

    return tt;
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

	

    pln = vector<vector<ll>>(2, vector<ll>(2, 1));
    pln[1][1] = 0;
	vector<vector<ll>> result = {{1, 0}, {0, 1}};

    ll n = 0;
    scanf("%ld", &n);

    while(n){
        if(n&1)
            result = matrix(pln, result);
        pln = matrix(pln, pln);
        n = n >> 1;
    }

    printf("%ld", result[0][1]);


}