#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Return the area of the passed in coordinate's block
// Parameters:
//      grid_row : The row length of the grid
//      grid_col : The col length of the grid
//      grid     : The grid itself
//      visited  : The coordinates already visited
//      i        : Current row location
//      j        : Current col location
int get_area(int grid_row, int grid_col, vector<vector<char>> const & grid, vector<vector<bool>> & visited, int i, int j);

int main(){
    int r, c;
    cin >> r >> c;

    int grid_row = 2 * r + 1;
    int grid_col = 2 * c + 1;

    vector<vector<char>> grid(grid_row, vector<char>(grid_col));
    vector<vector<bool>> visited(grid_row, vector<bool>(grid_col, false));

    for(int i = 0; i < grid_row; i++){
        for(int j = 0; j < grid_col; j++){
            cin >> grid[i][j];
            if(grid[i][j] != '.'){
                visited[i][j] = true;
            }
        }
    }

    vector<int> areas(4);
    int n = 0;

    for(int i = 0; i < grid_row; i++){
        for(int j = 0; j < grid_col; j++){
            if(!visited[i][j]){
                areas[n] = get_area(grid_row, grid_col, grid, visited, i, j);
                // We have 4 areas
                if(++n >= 4){
                    sort(areas.begin(), areas.end(), greater<>());
                    // Output all areas
                    for(int k = 0; k < n; k++){
                        cout << areas[k] << " ";
                    }
                    return 0;
                }
            }
        }
    }

    cout << "We shouldn't be here" << endl;

    return 0;
}

int get_area(int grid_row, int grid_col, vector<vector<char>> const & grid, vector<vector<bool>> & visited, int i, int j){
    if(visited[i][j]){
        return 0;
    }

    int p = 1;

    if(i % 2 == 0 || j % 2 == 0){ // Is a wall
        p = 0;
    }

    visited[i][j] = true;

    int left = get_area(grid_row, grid_col, grid, visited, i - 1, j);
    int right = get_area(grid_row, grid_col, grid, visited, i + 1, j);
    int up = get_area(grid_row, grid_col, grid, visited, i, j - 1);
    int down = get_area(grid_row, grid_col, grid, visited, i, j + 1);

    return left + right + up + down + p;
}