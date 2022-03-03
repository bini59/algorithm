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
//vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)


// Mod = 1000000007

// n, k = map(int, input().split())

// print((fact(n)*dcpow(fact(k), Mod-2)*dcpow(fact(n-k), Mod-2))%Mod)

#define MOD 1000000007


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

ll fact(int a){
	ll res = 1;
	while(a > 1){
		res *= a;
		a -= 1;
		res %= MOD;
	}
	return res;
}

ll dcpow(int a, int p){
	ll res = 1;
	while(p){
		if(p & 1){
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		p >>= 1;
	}

	return res;
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

	int n, k;
	scanf("%d%d", &n, &k);

	ll A = fact(n)%MOD;
	ll B = dcpow(fact(k), MOD-2)*dcpow(fact(n-k), MOD-2);
	B %= MOD;
	ll result = (A*B)%MOD;


    printf("%ld ", A);
    printf("%ld ", B);

	printf("%ld", result);
	
}

