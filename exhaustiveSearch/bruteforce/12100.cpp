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
// vector<vector<int>> pln; // 2차원 배열
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


int move(vector<vector<int>> plane, int type, int K){
    printf("\n%dth %dtype will launch\n", K, type);
    int res = 0;
    int n = (int)plane.size();
    if(type == 0){
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > 0; j--){
                for(int k = j-1; k > -1; k--){
                    if (plane[i][k] == 0) continue;
                    else if(plane[i][k] == plane[i][j]) {
                        plane[i][j] *= 2; 
                        plane[i][k] = 0;
                        break;
                    }
                    else if(plane[i][j] == 0){
                        plane[i][j] = plane[i][k];
                        plane[i][k] = 0;
                        break;
                    }
                    else{
                        int temp = plane[i][k];
                        plane[i][k] = 0;
                        plane[i][j-1] = temp;
                        break;
                    }
                }
                res = max(res, plane[i][j]);
            }
        }
    }
    if(type == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    if (plane[i][k] == 0) continue;
                    else if(plane[i][k] == plane[i][j]) {
                        plane[i][j] *= 2; 
                        plane[i][k] = 0;
                        break;
                    }
                    else if(plane[i][j] == 0){
                        plane[i][j] = plane[i][k];
                        plane[i][k] = 0;
                        break;
                    }
                    else{
                        int temp = plane[i][k];
                        plane[i][k] = 0;
                        plane[i][j+1] = temp;
                        break;
                    }
                }
                res = max(res, plane[i][j]);
            }
        }
    }
    if(type == 2){
        for(int j = 0; j < n; j++){
            for(int i = n-1; i > 0; i--){
                for(int k = i-1; k > -1; k--){
                    if (plane[k][j] == 0) continue;
                    else if(plane[k][j] == plane[i][j]) {
                        plane[i][j] *= 2; 
                        plane[k][j] = 0;
                        break;
                    }
                    else if(plane[i][j] == 0){
                        plane[i][j] = plane[k][j];
                        plane[k][j] = 0;
                        break;
                    }
                    else{
                        int temp = plane[k][j];
                        plane[k][j] = 0;
                        plane[i][j-1] = temp;
                        break;
                    }
                }
                res = max(res, plane[i][j]);
            }
        }
    }
    if(type == 3){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n-1; i++){
                for(int k = i+1; k < n; k++){
                    if (plane[k][j] == 0) continue;
                    else if(plane[k][j] == plane[i][j]) {
                        plane[i][j] *= 2; 
                        plane[k][j] = 0;
                        break;
                    }
                    else if(plane[i][j] == 0){
                        plane[i][j] = plane[k][j];
                        plane[k][j] = 0;
                        break;
                    }
                    else{
                        int temp = plane[k][j];
                        plane[k][j] = 0;
                        plane[i+1][j] = temp;
                        break;
                    }
                }
                res = max(res, plane[i][j]);
            }
        }
    }

    printf("\n\n%dth %dtype move result\n", K, type);
    FOR(n){
        printVector(plane[i]);
    }

    if(K == 4){
        printf("\nreturn %d\n", res);
        return res;
    }

    for(int i = 0; i < 4; i++){
        int temp = move(plane, i, K+1);
        
        printf("\nreturned %d\n", temp);
        res = temp > res ? temp : res;
    }
    return res;
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<vector<int>> pln = vector<vector<int>>(n, vector<int>(n, 0));

    FOR(n){
        for(int j = 0; j < n; j++){
            scanf("%d", &pln[i][j]);
        }
    }

	int result = 0;
    FOR(4){
        result = max(result, move(pln, i, 0));
    }

    printf("%d", result);

	
}