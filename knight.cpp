#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct knight{
    int x, y;
    int moves;
    knight(){}
    knight(int x, int y, int moves)
        : x(x), y(y), moves(moves){
    }
};

bool inBoard(int x, int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int minimum_steps(string s, string t, int b_size, vector<string> const & blocked){
    vector<vector<int>> knight_moves { // All posible knight movements
        {-2, -1},
        {-1, -2},
        {1, -2},
        {2, -1},
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1}
    };

    queue<knight> q; // Queue of knights we need to check

    // Changing chess notation to integers
    vector<int> start = {s[0] - 'a', s[1] - '0' - 1};
    vector<int> target = {t[0] - 'a', t[1] - '0' - 1};

    q.push(knight(start[0], start[1], 0)); // Pushing the initial starting position into the queue

    knight temp;
    int x, y;
    vector<vector<bool>> visited(8, vector<bool>(8)); // Initializing 64 squares to visit

    for(int i = 0; i < b_size; i++){ // If it's blocked we consider it as visited so we don't check the location
        x = blocked[i][0] - 'a';
        y = blocked[i][1] - '0' - 1;
        visited[x][y] = true;
    }

    visited[start[0]][start[1]] = true; // Setting the start node to be visited

    while(!q.empty()){ // Looping until there are no more knights to check
        temp = q.front(); // Checking each knight one at a time
        q.pop();

        if(temp.x == target[0] && temp.y == target[1]){
            return temp.moves; // We have reached the target
        }

        for(int i = 0; i < 8; i++){ // Check all possible knight moves (up to 8)
            x = temp.x + knight_moves[i][0];
            y = temp.y + knight_moves[i][1];

            if(inBoard(x, y) && !visited[x][y]){ // If the new move is within the board and hasn't been checked
                visited[x][y] = true;
                q.push(knight(x, y, temp.moves + 1)); // Push the new knight + 1 move
            }
        }
    }

    return -1; // If we return -1 then it is not reachable
}

int main(){
    int b_size;
    vector<string> blocked;
    string s, t;

    int board_count = 1;
    int move_count;

    cin >> b_size;
    while(b_size != -1){
        blocked.resize(b_size);
        for(int i = 0; i < b_size; i++){
            cin >> blocked[i];
        }
        cin >> s >> t;

        move_count = minimum_steps(s, t, b_size, blocked);
        cout << "Board " << board_count++ << ": ";
        if(move_count >= 0){
            cout << move_count << " moves" << endl;
        }
        else{
            cout << "not reachable" << endl;
        }

        cin >> b_size;
    }

    return 0;
}