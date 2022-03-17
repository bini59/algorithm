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


// Mod = 1000000007
int m;
// n, k = map(int, input().split())

// print((fact(n)*dcpow(fact(k), Mod-2)*dcpow(fact(n-k), Mod-2))%Mod)


// 벡터 표시기(int)
void printVector(vector<ll> arr){
	FOR((int)arr.size()){
		printf("%lld ", arr[i]);
	}

	printf("\n");
}

vector<vector<ll>> pascal;


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    ll result = 1;

	ll n, k;
	scanf("%lld %lld %d", &n, &k, &m);
    ll t = 1;
    int x = 0;

    pascal = vector<vector<ll>>(m, vector<ll>(m+2, 0));
    pascal[0][1] = 1;
    for(int i = 1; i< m;i++){
        for(int j = 1; j < i+2; j++){
            pascal[i][j] = (pascal[i-1][j]+pascal[i-1][j-1])%m;
        }
        // printVector(pascal[i]);
    }
    

    
    while(n){

        int x = n%m;
        int y = k%m;
        // printf("%d %d \n", x, y);
        if(y > x){result = 0; break;}

        n /= m;
        k /= m;
        // printf("tt: %d\n", pascal[x][y+1]);
        result = (result*(pascal[x][y+1]))%m;
    }

    printf("%lld", result);

	
}

