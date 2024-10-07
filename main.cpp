#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    int delete_column =a-1;
    int delete_row =b-1;
    int size[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> size[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << size[i][j] << "\t";
        }
        cout << endl;
    }
    char move = 'q';
    int row = 1, col = 1;
    while (move != 'z') {
        cin >> move;
        switch (move) {
            case 'w':
                delete_column = col;
                delete_row = row;
                col = col - 1;break;
            case 'a':
                delete_row = row;
                delete_column = col;
                row = row - 1;break;
            case 's':
                delete_column = col;
                delete_row = row;
                col = col + 1;break;
            case 'd':
                delete_row = row;
                delete_column = col;
                row = row + 1;break;
            default:cout << move << endl;
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                size[col][row] = 1;
                size[delete_column][delete_row] = 0;
                cout << size[i][j] << "\t";
            }
            cout << endl;
        }
    }
    return 0;

}