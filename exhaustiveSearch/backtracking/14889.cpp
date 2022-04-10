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
#define FOR(i, n) for(int i = 0; i < (n); i++)

vector<vector<int>> power;

int calculation(vector<int> team){
    int tp = 0;
    for(int i = 0; i < (int)team.size(); i++){
        for(int j = 0; j < (int)team.size(); j++){
            if(i != j){
                tp += power[team[i]-1][team[j]-1];
            }
        }
    }

    return tp;
}

// int teamPower(vector<int> start, vector<int> link){

// }


void combination(vector<int> numbers, int k, int n){
    vector<int> temp(n);
    for(int i = k; i < n+k-1; i++)
        temp[i-k] = numbers[i];
    
    for(int i = n+k-1; i < (int)numbers.size(); i++){
        temp[n-1] = numbers[i];
    }

}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int n = 0; 
    // scanf("%d", &n);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &power[i][j]);
        }
    }

	int result = 0;

    printf("%d", result);
	
}