#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

double convert_time(int L, int speed){
    return (double) L / speed * 60;
}

double total_time(int W, int L, int n, vector<vector<int>> const & trucks){
    vector<double> s(n + 1);
    s[0] = 0.0;

    for(int i = 1; i <= n; i++){
        int weight = trucks[i][0];
        double max_time = convert_time(L, trucks[i][1]);
        s[i] = s[i - 1] + max_time;
        for(int j = i - 1; j > 0; j--){
            weight += trucks[j][0];
            if(weight > W){
                break;
            }
            max_time = max(max_time, convert_time(L, trucks[j][1]));
            s[i] = min(s[i], s[j - 1] + max_time);
        }
    }

    return s[n];
}

int main(){
    cout << fixed;
    cout << setprecision(8);

    int W, L, n;
    cin >> W >> L >> n;

    if(!n){
        cout << 0;
        return 0;
    }

    // trucks[i][0] = w; trucks[i][1] = s (km/h);
    vector<vector<int>> trucks(n + 1, vector<int>(2));
    trucks[0][0] = 0;
    trucks[0][1] = 0;

    for(int i = 1; i <= n; i++){
        cin >> trucks[i][0] >> trucks[i][1];
    }

    if(!W || !L){
        cout << 0;
        return 0;
    }

    double time = total_time(W, L, n, trucks);
    cout << time;

    return 0;
}