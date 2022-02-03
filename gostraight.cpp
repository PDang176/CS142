#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int main(){
    int size;
    cin >> size;

    vector<vector<int>> biscuits(size, vector<int>(2));
    for(int i = 0; i < size; i++){
        cin >> biscuits[i][0] >> biscuits[i][1];
    }

    int max = 0;
    map<pair<double, double>, int> line; // slope, y-int

    pair<double, double> equation;
    double rise, run, m, intercept;
    for(int i = 0; i < size - 1; i++){ // Create a line between every 2 coordinates
        for(int j = i + 1; j < size; j++){
            rise = biscuits[j][1] - biscuits[i][1];
            run = biscuits[j][0] - biscuits[i][0];
            m = rise / run;

            intercept = (-1 * m * biscuits[j][0]) + biscuits[j][1];

            equation = make_pair(m, intercept);
            line[equation] = 0; // Inserting equation
        }
    }

    for(int i = 0; i < biscuits.size(); i++){ // Check each coordinate with every equation
        for(auto it = line.begin(); it != line.end(); it++){
            equation = it->first;
            if(biscuits[i][1] == equation.first * biscuits[i][0] + equation.second){
                it->second++;
                if(it->second > max){
                    max = it->second;
                }
            }
        }
    }

    cout << max;

    return 0;
}