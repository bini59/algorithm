//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
#include <stack>
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
#define FOR(n) for(int i = 0; i < (n); i++)


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


int getWeigth(char operate){
    switch (operate){
    case '(':
        return 0;
    case '-':
    case '+':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
    default:
        break;
    }
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    stack<char> s;

    char oper[101];

    scanf("%s", oper);
    int length = 0;
    while(oper[length] != '\0'){
        if(oper[length] >= 'A' && oper[length] <= 'Z'){
            printf("%c", oper[length]);
        }
        else{
            if(oper[length] == '(')
                s.push(oper[length]);
            else if(oper[length] == ')'){
                while(s.top() != '('){
                    printf("%c", s.top());
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty()&&(getWeigth(oper[length]) <= getWeigth(s.top()))){
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(oper[length]);
            }
        }
        length++;
    }

    while(!s.empty()){
        printf("%c", s.top());
        s.pop();
    }

	return 0;
	
}