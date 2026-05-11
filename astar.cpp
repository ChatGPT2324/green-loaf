#include <iostream>
using namespace std;

int main() {
    int open = 0;
    int closed = 0;

    int g[3][3] = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    int goal[3][3] = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };

    // Heuristic: count misplaced tiles
    int h = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i][j] != 0 && g[i][j] != goal[i][j]) {
                h++;
            }
        }
    }

    int f = open + h;

    cout << "Initial State:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHeuristic (h) = " << h << endl;
    cout << "Cost (g) = " << open << endl;
    cout << "f(n) = g(n) + h(n) = " << f << endl;

    return 0;
}