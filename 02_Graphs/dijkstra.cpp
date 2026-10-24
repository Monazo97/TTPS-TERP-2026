typedef long long ll;
const ll INF = 1e18+7;

struct Arista {
    int from, to, w;
    Arista() {}
    Arista(int _from, int _to, int _w) {
        from = _from, to = _to, w = _w;
    }
};
 
struct Nodo {
    int id; ll dist;
    Nodo() {}
    Nodo(int _id, ll _dist) {
        id = _id, dist = _dist;
    }
    bool operator < (Nodo aux) const {
        return dist > aux.dist;
    }
 
};
 
vector <ll> dijkstra(int start, vector<vector<Arista>> &g, int n) {
    vector <ll> dist(n,INF);
    priority_queue <Nodo> pq;
    pq.push(Nodo(start,0));
    while(pq.size() > 0) {
        auto [cur,d] = pq.top();
        pq.pop();
        if(dist[cur] != INF) continue;
        dist[cur] = d;
        for(Arista a : g[cur]) {
            if(dist[a.to] == INF) {
                pq.push(Nodo(a.to,d+a.w));
            }
        }
 
    }
    return dist;
}