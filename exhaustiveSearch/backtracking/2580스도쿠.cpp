//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
//#include <cmath>
//#include <algorithm>
//#include <string>

#include <ctime>

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
vector<vector<int>> plane; // 2차원 배열
// vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

vector<pair<int, int>> loc;

//for문 간단하게.
#define FOR(i, n) for(int i = 0; i < (n); i++)

void printAry(vector<vector<int>> ary){
    for(int i = 0; i < (int)ary.size(); i++){
        for(int j = 0; j < (int)ary[i].size(); j++){
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }
}

bool check(){
    bool ch = true;

    vector<bool> nums = vector<bool>(9, false);
    for(int i = 0; i < 9; i++){
        nums = vector<bool>(9, false);
        for(int j = 0; j < 9; j++){
            nums[plane[i][j]-1] = true;
        }
        for(int j = 0; j < 9; j++){
            if(!nums[j]) return false;
        }
    }

    for(int i = 0; i < 9; i++){
        nums = vector<bool>(9, false);
        for(int j = 0; j < 9; j++){
            nums[plane[j][i]-1] = true;
        }
        for(int j = 0; j < 9; j++){
            if(!nums[j]) return false;
        }
    }

    printAry(plane);
    return ch;
}

void solution(vector<vector<int>> ableNums, int n){
    for(int i = 0; i < (int)ableNums[n].size(); i++){
        plane[loc[n].first][loc[n].second] = ableNums[n][i];


        if(n+1 == (int)ableNums.size()){
            if(check()){
                return;
            }
        }            
        else{
            vector<vector<int>> temp = ableNums;
            for(int j = n+1; j < (int)loc.size(); j++){
                if(loc[n].first == loc[j].first && loc[n].second == loc[j].second && (loc[n].first / 3 == loc[j].first / 3) && (loc[n].second / 3 == loc[j].second / 3)){
                    for(int k = 0; k < (int)temp[j].size(); j++){
                        if(temp[n][i] == temp[j][k]) {
                            temp[j].erase(temp[j].begin()+k);
                            break;
                        }
                    }
                        
                }
            }

            solution(temp, n+1);
        }
            
    }
}


vector<bool> searchRow(int col, int row){
    vector<bool> ch = vector<bool>(9, false);

    for(int i = 0; i < 9; i++){
        if(i == row) continue;
        if(plane[col][i] != 0) ch[plane[col][i]-1] = true;
    }
    return ch;
}

vector<bool> searchCol(int col, int row){
    vector<bool> ch = vector<bool>(9, false);

    for(int i = 0; i < 9; i++){
        if(i == col) continue;
        if(plane[i][row] != 0) ch[plane[i][row]-1] = true;
    }
    return ch;
}

vector<bool> searchSqr(int col, int row){
    vector<bool> ch = vector<bool>(9, false);

    int x = row/3;
    int y = col/3;

    for (int i = y*3; i < y*3+3; i++){
        for(int j = x*3; j < x*3+3; j++){
            if(i == col && j == row) continue;
            if(plane[i][j] != 0) ch[plane[i][j]-1] = true;
        }
    }
    return ch;
}

vector<int> mkNums(int col, int row){
    vector<int> able;

    vector<bool> ableCol = searchCol(col, row);
    vector<bool> ableRow = searchRow(col, row);
    vector<bool> ableSqr = searchSqr(col, row);

    for(int i = 0; i < 9; i++)
        if(!ableCol[i] && !ableRow[i] && !ableSqr[i]) able.push_back(i+1);

    return able;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    // time_t start, end;
    // double res;
    // start = time(NULL); // 시간 측정 시작.  

    plane = vector<vector<int>>(9, vector<int>(9, 0));
    
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> plane[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            if(plane[j][i] == 0) loc.push_back({j, i});
    }

    vector<vector<int>> ableNums = vector<vector<int>>((int)loc.size(), vector<int>(0));
    for(int i = 0; i < (int)loc.size(); i++){
        ableNums[i] = mkNums(loc[i].first, loc[i].second);
    }
    // printAry(ableNums);
    solution(ableNums, 0);

    // end = time(NULL); // 시간 측정 끝
    // res = (double)(end - start);
    // printf("%f", res);
}