#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int SIZE = 10;
    int num_points;
    cin >> num_points;

    vector<vector<char>> grid(SIZE, vector<char>(SIZE, '.'));

    int x, y;
    char comma;
    for (int i = 0; i < num_points; ++i) {
        cin >> x >> comma >> y;
        if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE) {
            grid[y - 1][x - 1] = '1'; // Adjust coordinates to fit array indices
        } else {
            cerr << "Invalid coordinates: " << x << ", " << y << endl;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == '1') {
                cout << "x";
            } else {
                int count = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int nx = i + dx;
                        int ny = j + dy;
                        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && grid[nx][ny] == '1') {
                            ++count;
                        }
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }

    return 0;
}
