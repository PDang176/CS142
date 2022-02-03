#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> temp = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> temp2 = {10, 11, 12};

    temp.insert(temp.begin() + 1, temp2);

    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[i].size(); j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}