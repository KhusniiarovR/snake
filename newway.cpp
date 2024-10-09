#include <iostream>
#include <random>
using namespace std;
int main() {
    int a,b;
    int snake_length = 5;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> int_distribution(1, 1000000000);
    cout << "Enter the size y,x: ";
    cin >> a >> b;
    cout << "Enter the length of the snake: ";
    cin >> snake_length;
    int size[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            size[i][j] = 0;
        }
    }
    int new_x = int_distribution(gen) % (a-1);
    int new_y = int_distribution(gen) % (b-1);
    size[new_x][new_y] = 999;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << size[i][j] << "\t";
        }
        cout << endl;
    }
    int x = static_cast<int>(a/2);
    int y = static_cast<int>(b/2);
    char move = 'q';
    while (move != 'z') {
        cin >> move;
        cout << "\tYour length: " << snake_length << endl;
        switch (move) {
            case 'a':
                y -= 1;
            if (size[x][y] == 999) {
                snake_length += 1;
                new_x = int_distribution(gen) % a;
                new_y = int_distribution(gen) % b;
                while(size[new_x][new_y] != 0) {
                    new_x = int_distribution(gen) % a;
                    new_y = int_distribution(gen) % b;
                }
                size[new_x][new_y] = 999;
            }
            else if (size[x][y] != 0) {move = 'z';cout << "GAME OVER\n";}break;
            case 'w':
                x -= 1;
            if (size[x][y] == 999) {
                snake_length += 1;
                new_x = int_distribution(gen) % a;
                new_y = int_distribution(gen) % b;
                while(size[new_x][new_y] != 0) {
                    new_x = int_distribution(gen) % a;
                    new_y = int_distribution(gen) % b;
                }
                size[new_x][new_y] = 999;
            }
            else if (size[x][y] != 0) {move = 'z';cout << "GAME OVER\n";}break;
            case 's':
                x += 1;
            if (size[x][y] == 999) {
                snake_length += 1;
                new_x = int_distribution(gen) % a;
                new_y = int_distribution(gen) % b;
                while(size[new_x][new_y] != 0) {
                    new_x = int_distribution(gen) % a;
                    new_y = int_distribution(gen) % b;
                }
                size[new_x][new_y] = 999;
            }
            else if (size[x][y] != 0) {move = 'z';cout << "GAME OVER\n";}break;
            case 'd':
                y += 1;
            if (size[x][y] == 999) {
                snake_length += 1;
                new_x = int_distribution(gen) % a;
                new_y = int_distribution(gen) % b;
                while(size[new_x][new_y] != 0) {
                    new_x = int_distribution(gen) % a;
                    new_y = int_distribution(gen) % b;
                }
                size[new_x][new_y] = 999;
            }
            else if (size[x][y] != 0) {move = 'z';cout << "GAME OVER\n";}break;
            default:cout << move << "?\n";break;
        }
        if (snake_length == a*b){move = 'z';cout << "You win\n";}
        if (move == 'z'){break;}
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
    return 0;
}