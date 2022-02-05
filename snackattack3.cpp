#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_points(vector<vector<vector<int>>> const & matrix, 
                int n,
                int t,
                int max_time,
                int r,
                int c, 
                int points){

    if(matrix[t][r][c] < 0){ // Hit by boulder
        return 0;
        //points /= 2;
    }
    else if(matrix[t][r][c] > 0){
        points += matrix[t][r][c];
        //cout << r << " " << c << " " << t << ": " << points << endl;
    }

    if(t == max_time){
        return points;
    }

    int up = 0, down = 0, left = 0, right = 0, still = 0;

    // Up
    if(r - 1 >= 0){
        up = max_points(matrix, n, t + 1, max_time, r - 1, c, points);
    }
    // Down
    if(r + 1 < n){
        down = max_points(matrix, n, t + 1, max_time, r + 1, c, points);
    }
    // Left
    if(c - 1 >= 0){
        left = max_points(matrix, n, t + 1, max_time, r, c - 1, points);
    }
    // Right
    if(c + 1 >= 0){
        right = max_points(matrix, n, t + 1, max_time, r, c + 1, points);
    }
    // Still
    still = max_points(matrix, n, t + 1, max_time, r, c, points);

    points = max({up, down, left, right, still});

    return points;
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

    vector<vector<vector<int>>> matrix(max_time + 1, vector<vector<int>>(n, vector<int>(n, 0)));

    for(int i = 0; i < p; i++){
        matrix[ popcorn[i][2] ][ popcorn[i][0] ][ popcorn[i][1] ] ++;
    }

    for(int i = 0; i < b; i++){
        matrix[ boulder[i][2] ][ boulder[i][0] ][ boulder[i][1] ] --;
    }

    //cout << endl;

    cout << max_points(matrix, n, 0, max_time, r, c, 0);

    return 0;
}