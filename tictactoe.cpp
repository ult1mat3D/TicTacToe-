
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

bool check_win(char (&m)[3][3], char p) {
    for (int i = 0; i < 3; i++)
        if (m[i][0] == p && m[i][1] == p && m[i][2] == p)
            return true;

    for (int j = 0; j < 3; j++)
        if (m[0][j] == p && m[1][j] == p && m[2][j] == p)
            return true;

    if (m[0][0] == p && m[1][1] == p && m[2][2] == p)
        return true;

    if (m[0][2] == p && m[1][1] == p && m[2][0] == p)
        return true;

    return false;
}

void draw_matrix(char (&matrix)[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


bool draw_a_point(int a, char (&matrix)[3][3], char element) {
    int row = (a - 1) / 3;
    int col = (a - 1) % 3;

    if (matrix[row][col] == '-') {
        matrix[row][col] = element;
        return true;
    } else {
        cout << "already chosen" << endl;
        return false;
    }
}


int main() {
    while (game) {
        cout << player << " Choice" << endl;
        draw_matrix(tictactoe);
        cin >> a;

        if (!draw_a_point(a, tictactoe, player))
            continue; 

        if (check_win(tictactoe, player)) {
            draw_matrix(tictactoe);
            cout << player << " win" << endl;
            break;
        }

        if (player == 'O') {
            player = 'X';
        } else {
            player = 'O';
        }
    }
}