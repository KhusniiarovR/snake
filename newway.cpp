#include <iostream>
using namespace std;
int main() {
    int a,b,new_x,new_y;
    srand(24);
    int snake_length=5;
    cin >> a >> b;
    int size[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            size[i][j] = 0;
        }
    }
    new_x = rand() % (a-1);
    new_y = rand() % (b-1);
    size[new_x][new_y] = 999;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << size[i][j] << "\t";
        }
        cout << endl;
    }
    int x = a-3;
    int y = b-3;
    char move = 'q';
    while (move != 'z') {
        cin >> move;
        switch (move) {
            case 'a':
                y -= 1;
                if (size[x][y] == 999) {
                    snake_length += 1;
                    new_x = rand() % (a-1);
                    new_y = rand() % (b-1);
                    size[new_x][new_y] = 999;
                }
                else if (size[x][y] != 0) {move = 'z';}break;
            case 'w':
                x -= 1;
                if (size[x][y] == 999) {
                    snake_length += 1;
                    new_x = rand() % (a-1);
                    new_y = rand() % (b-1);
                    size[new_x][new_y] = 999;
                }
            else if (size[x][y] != 0) {move = 'z';}break;
            case 's':
                x += 1;
                if (size[x][y] == 999) {
                    snake_length += 1;
                    new_x = rand() % (a-1);
                    new_y = rand() % (b-1);
                    size[new_x][new_y] = 999;
                }
            else if (size[x][y] != 0) {move = 'z';}break;
            case 'd':
                y += 1;
                if (size[x][y] == 999) {
                    snake_length += 1;
                    new_x = rand() % (a-1);
                    new_y = rand() % (b-1);
                    size[new_x][new_y] = 999;
                }
            else if (size[x][y] != 0) {move = 'z';}break;
            default:cout << move << "?\n";break;
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (size[i][j] != 0 && size[i][j] != 999) {
                    size[i][j] -= 1;
                }
                else if (size[i][j] == 999){size[x][y] += 1;}
                size[x][y] = snake_length;
                cout << size[i][j] << "\t";
            }
            cout << endl;
        }
    }
    cout << "GAME OVER\n";
    return 0;
}