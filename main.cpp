#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
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
                col = col - 1;break;
            case 'a':
                row = row - 1;break;
            case 's':
                col = col + 1;break;
            case 'd':
                row = row + 1;break;
            default:cout << move << endl;
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                size[col][row] = 4;
                if (size[i][j] != 0) {
                    size[i][j] -= 1;
                }
                cout << size[i][j] << "\t";
            }
            cout << endl;
        }
    }
    return 0;

}