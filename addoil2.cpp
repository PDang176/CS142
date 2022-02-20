#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;

class Graph{
    int n;
    vector<p> *neighbors;

    public:
        Graph(int n){
            this-> n = n;
            neighbors = new vector<p>[n];
        }
        void addEdge(int x, int y, int z){
            neighbors[x].push_back(make_pair(y, z));
            neighbors[y].push_back(make_pair(x, z));
        }
        void max_tank(int src);
};

void Graph::max_tank(int src, int dest){
    priority_queue<p, vector<p>, greater<p>> pq;

    vector<int> distance(n, INT_MAX);

    // Distance, Index
    pq.push(make_pair(0, src));
    distance[src] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();

        vector<p>::iterator it;
        for(it = neighbors[curr].begin(); it != neighbors[curr].end(); it++){
            int v = (*it).first;
            int w = (*it).second;

            int weight = w > distance[curr] ? w : distance[curr];
            if(weight < distance[v]){
                distance[v] = weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    int max = distance[0];
    for(int i = 1; i < n; i++){
        if(distance[i] > max){
            max = distance[i];
        }
    }
    cout << max;
}

int main(){
    int n, m;
    cin >> n >> m;

    Graph g(n);

    int x, y, z;

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        g.addEdge(x, y, z);
    }

    g.max_tank(0);

    return 0;
}