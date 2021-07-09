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
//typedef long long ll;


//자주 쓸 데이터들
vector<vector<int>> sudoku; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(k, n) for(int i = k; i < (n); i++)

int find(vector<int> &v, int p){
    FOR(0, v.size()){
        if(v[i] == p) return i;
    }
    return -1;
}



int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    sudoku = vector<vector<int>>(10, vector<int>(10, 0));
    vector<pair<int, int>> z;

    vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // input num
    FOR(1, 10){        
        for(int j = 1; j < 10; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) z.push_back(make_pair(i, j));
        } 
    }

    vector<vector<int>> possible;

    FOR(0, z.size()){
        possible.push_back({});

        number = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int j = 1; j < 10; j++) {
            if(j != z[i].second) number = number.erase(remove(number.begin(), number.end(), sudoku[z[i].first][j]), number.end());
        }
        for(int j = 0; j < number.size(); j++) possible[i].push_back(number[j]);

        number = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int j = 1; j < 10; j++) {
            if(j != z[i].first) number = number.erase(remove(number.begin(), number.end(), sudoku[j][z[i].second]), number.end());
            
        }
        for(int j = 0; j < number.size(); j++) possible[i].push_back(number[j]);

        number = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int x = (z[i].first-1/3)*3; int y = (z[i].second-1/3)*3;
        for(int j = 1+x; j < 4+x; j++){
            for(int k = 1+y; k < 4+y; k++){
                if(!((j == z[i].first)&&(k == z[i].second))) number = number.erase(remove(number.begin(), number.end(), sudoku[j][k]), number.end());
            }    
        }
    }

    FOR(0, possible.size()){
        for(int j = 0; j < possible[i].size(); j++) cout << possible[i][j] << ' ';
        cout << '\n';
    }

	int result = 0;
	
}