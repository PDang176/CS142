#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

using namespace std;

/*
    Parameters:
        Popcorn: Location and time of all popcorn kernals
        Boulder: Location and time of all boulders
        p: Total number of popcorn kernals
        b: Total number of boulders
        n: Dimension of our grid
        r: row coordinate of player
        c: col coordinate of player
        t: Current time
        max_time: Maximum time before game ends

    Steps:
        1) Check to see if we collected a popcorn
        2) Check to see if we hit a boulder
        3) Check to see if the game has ended
        4) Check all cardinal directions + staying in same location
            a) Increase time by 1
*/
int max_points(vector<vector<int>> const & popcorn, 
                vector<vector<int>> const & boulder, 
                int p, 
                int b, 
                int n, 
                int r, 
                int c, 
                int t, 
                int max_time,
                int points){
                    
    // Check to see if we collected a popcorn
    for(int i = 0; i < p; i++){
        if(t == popcorn[i][2] && r == popcorn[i][0] && c == popcorn[i][1]){
            points++;
            //cout << "Popcorn: " << r << " " << c << " " << t << " " << points << endl;
        }
    }
    
    // Check to see if we hit a boulder
    for(int i = 0; i < b; i++){
        if(t == boulder[i][2] && r == boulder[i][0] && c == boulder[i][1]){ // Consider run dead
            points /= 2;
            return points;
            //cout << "Boulder: " << r << " " << c << " " << t << " " << points << endl;
            break;
        }
    }

    // Checking if game has ended
    if(t == max_time){
        return points;
    }

    // Checking each direction the player can move after 1 unit of time

    int temp_points = 0;

    // Up
    if(r - 1 >= 0){
        temp_points = max(temp_points, max_points(popcorn, boulder, p, b, n, r - 1, c, t + 1, max_time, points));
    }
    // Down
    if(r + 1 < n){
        temp_points = max(temp_points, max_points(popcorn, boulder, p, b, n, r + 1, c, t + 1, max_time, points));
    }
    // Left
    if(c - 1 >= 0){
        temp_points = max(temp_points, max_points(popcorn, boulder, p, b, n, r, c - 1, t + 1, max_time, points));
    }
    // Right
    if(c + 1 < n){
        temp_points = max(temp_points, max_points(popcorn, boulder, p, b, n, r, c + 1, t + 1, max_time, points));
    }
    // Stand Still
    temp_points = max(temp_points, max_points(popcorn, boulder, p, b, n, r, c, t + 1, max_time, points));

    return temp_points;
}

int main(){
    int n, p, b;
    cin >> n >> p >> b;

    int r, c;
    cin >> r >> c;

    int max_time = 0;

    vector<vector<int>> popcorn(p, vector<int>(3));
    for(int i = 0; i < p; i++){
        cin >> popcorn[i][0] >> popcorn[i][1] >> popcorn[i][2];
        max_time = max(max_time, popcorn[i][2]);
    }

    vector<vector<int>> boulder(b, vector<int>(3));
    for(int i = 0; i < b; i++){
        cin >> boulder[i][0] >> boulder[i][1] >> boulder[i][2];
    }

    cout << max_points(popcorn, boulder, p, b, n, r, c, 0, max_time, 0);

    return 0;
}