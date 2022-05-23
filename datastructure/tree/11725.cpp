//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
//#include <cmath>
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



void printTree(int tree[], int n){
    FOR(n){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
	int n; scanf("%d", &n);

	int tree[100001] = {0};

	tree[1] = -1;

    pair<int, int> p[100001];
    pair<int, int> q[100001];
    int top = -1;
    int pfirst = 0;
    int prear = 0;
    

	for(int i = 0; i < n-1; i++){
		int a, b; scanf("%d %d", &a, &b);
        if (tree[a] == 0 && tree[b] == 0){
            p[prear++] = {a, b};
            continue;
        }
		if(tree[a] == 0){
			tree[a] = b;
		}
		else if(tree[b] == 0){
			tree[b] = a;
		}
        // printTree(tree, n+1);
	}   
    sort(p, p+prear);
    // for(int i = 0; i < prear; i++){
    //     printf("(%d, %d) ", p[i].first, p[i].second);
    // }

    int mod = 0;
    while(pfirst != prear || top > -1){

        int a, b;
        if(!mod){
            a = p[pfirst].first;
            b = p[pfirst].second;
            pfirst = (pfirst+1)%100001;
            if(pfirst == prear) mod = 1;
        }
        else{
            a = q[top].first;
            b = q[top].second;
            top--;
            if(top == -1) mod = 0;
        }

        if(tree[a] == 0 && tree[b] == 0){
            if(!mod)q[++top] = {a, b};
            else {p[prear] = {a, b}; prear = (prear+1)%100001;}
            continue;
        }
        if(tree[a] == 0) tree[a] = b;
        else if(tree[b] == 0) tree[b] = a;
        
        if(mod) if(pfirst != prear) if(tree[p[pfirst].first] || tree[p[pfirst].second]) mod = 0;
        else if(top > -1)if(tree[q[top].first] || tree[q[top].second]) mod = 1;
    }
	for(int i = 2; i <= n; i++){
		printf("%d\n", tree[i]);
	}	
}
