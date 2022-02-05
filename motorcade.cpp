#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double convert_time(int L, int speed){
    return (double) L / speed * 60;
}

double total_time(int W, int L, int n, vector<vector<int>> const & trucks){
    vector<double> s(n);
    int prev_weight = trucks[0][0];
    int prev_size = 1;

    s[0] = convert_time(L, trucks[0][1]);

    vector<double> prev_times;
    prev_times.push_back(s[0]);

    for(int i = 1; i < n; i++){
        if(prev_weight + trucks[i][0] <= W){ // Check if we can add the new truck into the previous batch
            double next_time = convert_time(L, trucks[i][1]);
            prev_weight += trucks[i][0]; // Increment previous weight
            prev_size++; // Increment previous batch size
            prev_times.push_back(max(prev_times.back(), next_time));
            s[i] = s[i - 1] - prev_times[prev_size - 2] + prev_times.back();
        }
        else{ // Can't add to previous batch
            double next_time = convert_time(L, trucks[i][1]);
            s[i] = s[i - 1] + next_time; // Create a new batch with the next truck
            int curr_weight = trucks[i][0]; // The current weight of the new batch
            int next_size = 1;

            for(int j = 1; j < prev_size; j++){ // Loop through all the trucks in the previous batch except first one
                if(curr_weight + trucks[i - j][0] <= W){ // Check to see if we take one truck will it be under the weight limit
                    double prev_time = prev_times[prev_size - j - 1];
                    next_time = max(next_time, convert_time(L, trucks[i - j][1]));

                    if(s[i] > s[i - 1] - prev_times.back() + prev_time + next_time){ // If adding truck is worth it
                        s[i] = s[i - 1] - prev_times.back() + prev_time + next_time;
                        curr_weight += trucks[i - j][0];
                        next_size++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            prev_times.clear();
            prev_size = next_size;
            prev_weight = curr_weight;
            prev_times.push_back(convert_time(L, trucks[i - prev_size + 1][1]));
            for(int j = prev_size - 2; j >= 0; j--){
                prev_times.push_back(max(prev_times.back(), convert_time(L, trucks[i - j][1])));
            }
        }
    }

    return s.back();
}

int main(){
    int W, L, n;
    cin >> W >> L >> n;

    // trucks[i][0] = w; trucks[i][1] = s (km/h);
    vector<vector<int>> trucks(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin >> trucks[i][0] >> trucks[i][1];
    }

    cout << fixed;
    cout << setprecision(8);
    cout << total_time(W, L, n, trucks);

    return 0;
}