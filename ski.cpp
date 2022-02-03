#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_length(vector<vector<int>> const & h, vector<vector<int>> const & mem, int i, int j, int length){
    int max_length = 1;

    // Up
    if(i - 1 > 0 && h[i][j] > h[i - 1][j]){
        max_length = max(max_length, longest_length(h, mem, i - 1, j, length + 1));
    }
    // Down
    if(i + 1 < h.size() - 1 && h[i][j] > h[i + 1][j]){
        max_length = max(max_length, longest_length(h, mem, i, j + 1, length + 1));
    }
    // Left
    if(j - 1 > 0 && h[i][j] > h[i][j - 1]){
        max_length = max(max_length, longest_length(h, mem, i, j - 1, length + 1));
    }
    // Right
    if(j + 1 < h[i].size() - 1 && h[i][j] > h[i][j + 1]){
        max_length = max(max_length, longest_length(h, mem, i, j + 1, length + 1));
    }
    
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
    vector<vector<int>> mem(r, vector<int>(c, 1));
    
    int max_length = 1;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            max_length = longest_length(h, mem, i, j, 1);
        }
    }

    cout << max_length;

    return 0;
}