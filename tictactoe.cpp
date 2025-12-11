
#include <iostream>
using namespace std;


int a;
bool game = true;
int counter = 0;
char player = 'O';


char tictactoe[3][3] = {
    { '-', '-', '-' },
    { '-', '-', '-' },
    { '-', '-', '-' }
};


void draw_matrix(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void draw_a_point(int a, char matrix[3][3], char element) {
    int row = (a - 1) / 3;
    int col = (a - 1) % 3;
    if (matrix[row][col] == '-') {
        matrix[row][col] = element;
    } else {
        cout << "already chosen" << endl;
    }
}


int main()
{
  while (game)  {
    cout << player << " "<< "Choice" << endl;
    draw_matrix(tictactoe);
    cin >> a;
    draw_a_point(a, tictactoe, player);
    if (player == 'O'){
        player = 'X';
    }
    else{
        player = 'O';
    }
  }
}