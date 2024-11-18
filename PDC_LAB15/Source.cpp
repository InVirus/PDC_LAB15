#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int n;
vector<int> board;

bool isSafe(int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}



void solve(int row) {
    if (row == n) {  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1); 
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть кількість ферзів (n): ";
    cin >> n;

    board.resize(n);

    cout << "Можливі розміщення ферзів на шахівниці " << n << "x" << n << ":" << endl;
    solve(0);

    return 0;
}
