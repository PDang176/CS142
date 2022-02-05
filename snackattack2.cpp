#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, p, b;
    cin >> n >> p >> b;

    int r, c;
    cin >> r >> c;

    vector<vector<int>> popcorn(p, vector<int>(3));
    for(int i = 0; i < p; i++){
        cin >> popcorn[i][0] >> popcorn[i][1] >> popcorn[i][2];
    }

    vector<vector<int>> boulder(b, vector<int>(3));
    for(int i = 0; i < b; i++){
        cin >> boulder[i][0] >> boulder[i][1] >> boulder[i][2];
    }

    return 0;
}