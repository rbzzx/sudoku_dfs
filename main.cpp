#include<iostream>
#include<vector>
using namespace std;

// 检测数独是否满足要求
bool check_sudoku(vector<int> sudoku, int n){

    // 定位所在格的行、列
    int row = n / 9;
    int col = n % 9;

    // 定位所在的九宫格
    int row_9 = row / 3;
    int col_9 = col / 3;

    int i;

    // 判断行内是否有重复数字
    for(i = 0; i < 9; i++){
        if(row + i == n) continue;
        if(sudoku[row + i] == sudoku[n]) return false;
    }

    // 判断列内是否有重复数字
    for(i = 0; i < 9; i++){
        if(col + i * 9 == n) continue;
        if(sudoku[col + i * 9] == sudoku[n]) return false;
    }

    // 判断九宫格内是否有重复数字
    for(i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((row_9 + i) * 9 + col_9 + j == n) continue;
            if(sudoku[(row_9 + i) * 9 + col_9 + j] == sudoku[n]) return false;
        }
    }

    // 通过检测，返回true
    return true;
}

// 解决数独方法实现
bool solve_sudoku(vector<int> sudoku, int n, int* temp){
    int i;

    // 最后一格
    if(n == 80){
        if(!temp[n]) return true;
        for(i = 1; i <= 9; i++){
            sudoku[n] = i;
            if(!check_sudoku(sudoku, n)) continue;
            break;
        }
        if(i <= 9) return true;
        else return false;
    }

    // 常规判定
    if(!temp[n]) return solve_sudoku(sudoku, n + 1, temp);
    for(i = 1; i <= 9; i++){
        sudoku[n] = i;
        if(!check_sudoku(sudoku, n)) continue;
        if(!solve_sudoku(sudoku, n + 1, temp)) continue;
        break;
    }
    if(i <= 9) return true;
    return false;
}

//输出数独至屏幕
void print_sudoku(vector<int> sudoku){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<sudoku[i * 9 + j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    // vector<int> s = {0, 0, 0, 0, 0, 5, 0, 0, 8, 
    //                  0, 1, 0, 3, 6, 0, 2, 0, 0, 
    //                  0, 0, 0, 0, 0, 2, 1, 0, 4, 
    //                  6, 0, 0, 1, 0, 0, 3, 4, 2, 
    //                  0, 0, 9, 0, 0, 0, 5, 0, 0, 
    //                  0, 7, 1, 0, 0, 0, 0, 0, 0, 
    //                  7, 2, 0, 0, 0, 0, 0, 0, 5, 
    //                  0, 0, 6, 5, 3, 0, 0, 0, 0, 
    //                  0, 8, 0, 0, 0, 0, 0, 6, 0};
    
    vector<int> s = {0, 0, 0, 9, 0, 0, 0, 0, 0, 
                     0, 0, 0, 0, 0, 0, 5, 6, 8, 
                     2, 0, 0, 0, 0, 0, 0, 0, 1, 
                     0, 1, 0, 0, 0, 6, 4, 0, 0, 
                     0, 8, 4, 2, 3, 0, 0, 7, 0, 
                     0, 0, 0, 0, 0, 5, 0, 0, 9, 
                     0, 0, 3, 0, 8, 0, 0, 0, 0, 
                     9, 2, 0, 3, 0, 0, 0, 0, 0, 
                     0, 0, 8, 0, 0, 0, 0, 4, 2};
    int temp[81];
    for(int i = 0; i < 81; i++){
        temp[i] = !s[i];
    }
    bool mark = solve_sudoku(s, 0, temp);
    if(mark == false) cout<<"Failed"<<endl;
    else print_sudoku(s);
    getchar();
    return 0;
}
