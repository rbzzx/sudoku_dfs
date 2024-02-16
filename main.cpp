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

//解决数独方法实现
vector<int> solve_sudoku(vector<int> sudoku){

}

int main(){

}
