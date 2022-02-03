#include <iostream>
#include <vector>

using namespace std;

void increment_points(int start, int end, int c, int& points){
    if(c == 1){
        points += 3 * (end - start + 1);
    }
    else{
        points += end - start + 1;
    }
}

int main(){
    int T, n, m;
    cin >> T >> n >> m;

    vector<vector<int>> time_n(n, vector<int>(3));
    vector<vector<int>> time_m(m, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> time_n[i][0] >> time_n[i][1] >> time_n[i][2];
    }
    for(int i = 0; i < m; i++){
        cin >> time_m[i][0] >> time_m[i][1] >> time_m[i][2];
    }

    int points = 0;

    int i = 0;
    int j = 0;
    vector<int> curr;
    if(time_n[0][0] < time_m[0][0]){
        curr = time_n[0];
        i++;
    }
    else{
        curr = time_m[0];
        j++;
    }

    vector<int> next;
    while(i < n || j < m){
        if(i < n && j < m){
            if(time_n[i][0] < time_m[j][0]){
                next = time_n[i++];
            }
            else{
                next = time_m[j++];
            }
        }
        else if(i < n){
            next = time_n[i++];
        }
        else{
            next = time_m[j++];
        }
        
        if(next[0] <= curr[1]){
            if(next[2] != curr[2]){
                if(curr[2] == 1){
                    if(next[1] > curr[1]){
                        increment_points(curr[0], curr[1], curr[2], points);
                        curr[0] = curr[1] + 1;
                        curr[1] = next[1];
                        curr[2] = next[2];
                    }
                }
                else{
                    if(curr[0] < next[0]){
                        increment_points(curr[0], next[0] - 1, curr[2], points);
                    }
                    if(curr[1] <= next[1]){
                        curr[0] = next[0];
                        curr[1] = next[1];
                        curr[2] = next[2];
                    }
                    else{
                        increment_points(next[0], next[1], next[2], points);
                        curr[0] = next[1] + 1;
                    }
                }
            }
            else{
                curr[1] = curr[1] < next[1] ? next[1] : curr[1];
            }
        }
        else{
            increment_points(curr[0], curr[1], curr[2], points);
            curr[0] = next[0];
            curr[1] = next[1];
            curr[2] = next[2];
        }
    }

    increment_points(curr[0], curr[1], curr[2], points);

    cout << points;

    return 0;
}