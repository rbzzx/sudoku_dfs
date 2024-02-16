#include<iostream>
using namespace std;

struct sudoku{
    public:
    int value;
    int x_pos;
    int y_pos;
    bool mark = 0;

    sudoku(int v, int x, int y){
        value = v;
        x_pos = x;
        y_pos = y;
    }
};

int main(){

}
