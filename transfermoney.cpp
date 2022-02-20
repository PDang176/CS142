#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<float, int> p;

class Graph{
    int n;
    vector<pair<int, int>> *neighbors;

    public:
        Graph(int n){
            this->n = n;
            neighbors = new vector<pair<int, int>>[n];
        }
        void addEdge(int x, int y, int z){
            neighbors[x].push_back(make_pair(y, z));
            neighbors[y].push_back(make_pair(x, z));
        }
        void min_money(int src, int dest);
};

void Graph::min_money(int src, int dest){
    priority_queue<p, vector<p>, less<p>> pq;

    vector<float> distance(n, 0);

    // Distance, Index
    pq.push(make_pair(1.0, src));
    distance[src] = 1;

    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for(it = neighbors[curr].begin(); it != neighbors[curr].end(); it++){
            int v = (*it).first;
            int w = (*it).second;

            float weight = (1 - (w / 100.0)) * distance[curr];
            if(weight > distance[v]){
                distance[v] = weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    cout << 100.0 / distance[dest];
}

int main(){
    int n, m;
    cin >> n >> m;

    Graph g(n);

    int x, y, z;

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        g.addEdge(x - 1, y - 1, z);
    }

    int src, dest;
    cin >> src >> dest;

    g.min_money(src - 1, dest - 1);

    return 0;
}