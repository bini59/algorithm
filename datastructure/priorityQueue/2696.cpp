//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
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


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){

        priority_queue<ll> mx_h;
        priority_queue<ll> mn_h;
        int mid = 0;

        int result[10000];
        int Size = 0;

        int x; scanf("%d", &x);
        ll item;

        for(int j = 0; j < x; j++){
            if(!(j % 10) && j > 0)
                getchar();
            scanf("%lld", &item);
            if(j == 0){
                mid = item;
                result[Size++] = mid;
                continue;
            }
            if(mx_h.size() == mn_h.size()){
                if(item < mid)
                    mx_h.push(item);
                else{
                    // printf("push ");
                    mn_h.push(-item);
                }
            }
            else if(mx_h.size() > mn_h.size()){
                if(item > mid){
                    mn_h.push(-item);
                }
                else{
                    mn_h.push(-mid);
                    if(item < mx_h.top()){
                        mid = mx_h.top();
                        mx_h.pop();
                        mx_h.push(item);
                    }
                    else{
                        mid = item;
                    }
                }
            }
            else{
                if(item < mid){
                    mx_h.push(item);
                }
                else{
                    mx_h.push(mid);
                    if(item > -mn_h.top()){
                        mid = -mn_h.top();
                        mn_h.pop();
                        mn_h.push(-item);
                    }
                    else{
                        mid = item;
                    }
                }
            }
            // if(!mx_h.empty())
            //     printf("max %d ", mx_h.top());
            // printf("mid %d ", mid);
            // if(!mn_h.empty())
            //     printf("min %d ", -mn_h.top());
            // printf("\n");
            if(j % 2 == 0)
                result[Size++] = mid;
        }
        printf("%d\n", (x / 2) + (x % 2));
        for (int i = 0; i < Size; i++){
            printf("%d ", result[i]);
            if((i % 10) == 9)
                printf("\n");
        }
        printf("\n");
    }

	int result = 0;
	
}