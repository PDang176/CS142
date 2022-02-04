#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Steps:
        1) Check cardinal directions
            a) Check if within boundary
            b) Check if we haven't visited it yet within this recursive call
            c) Check if it fits the requirements of being shorter than the current position
        2) Within each direction check if we have already been there before
            a) If so then we use the stored length rather than continuing our recursive calls
        3) At the end we store the max of all 4 cardinal directions into our memory
        4) If we couldn't check any direction we return the current length and set the memory as 1
    
*/
int longest_length(vector<vector<int>> const & h, vector<vector<int>> & mem, vector<vector<bool>> visited, int i, int j){
    int max_length = 1;

    // We have visited this node
    visited[i][j] = true;

    // Up
    if(i - 1 >= 0 && !visited[i - 1][j] && h[i][j] > h[i - 1][j]){
        if(mem[i - 1][j] != 0){
            max_length = max(max_length, 1 + mem[i - 1][j]);
        }
        else{
            max_length = max(max_length, 1 + longest_length(h, mem, visited, i - 1, j));
        }
    }
    // Down
    if(i + 1 < h.size() && !visited[i + 1][j] && h[i][j] > h[i + 1][j]){
        if(mem[i + 1][j] != 0){
            max_length = max(max_length, 1 + mem[i + 1][j]);
        }
        else{
            max_length = max(max_length, 1 + longest_length(h, mem, visited, i + 1, j));
        }
    }
    // Left
    if(j - 1 >= 0 && !visited[i][j - 1] && h[i][j] > h[i][j - 1]){
        if(mem[i][j - 1] != 0){
            max_length = max(max_length, 1 + mem[i][j - 1]);
        }
        else{
            max_length = max(max_length, 1 + longest_length(h, mem, visited, i, j - 1));
        }
    }
    // Right
    if(j + 1 < h[i].size() && !visited[i][j + 1] && h[i][j] > h[i][j + 1]){
        if(mem[i][j + 1] != 0){
            max_length = max(max_length, 1 + mem[i][j + 1]);
        }
        else{
            max_length = max(max_length, 1 + longest_length(h, mem, visited, i, j + 1));
        }
    }
    
    mem[i][j] = max_length;
    return max_length;
}

int main(){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> h(r, vector<int>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> h[i][j];
        }
    }

    // Store the longest path length at each index
    vector<vector<int>> mem(r, vector<int>(c, 0));
    
    // Store visited nodes
    vector<vector<bool>> visited(r, vector<bool>(c, false));

    int max_length = 1;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mem[i][j] != 0){
                max_length = max(max_length, mem[i][j]);
            }
            else{
                max_length = max(max_length, longest_length(h, mem, visited, i, j));
            }
        }
    }

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         cout << mem[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << max_length;

    return 0;
}