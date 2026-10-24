struct DSU {
    vector <int> link, tam;
    vector <vector<int>> comp;
    DSU(){}
    DSU(int n){
        link.resize(n); tam.resize(n,1);
        comp.resize(n);
        for(int i = 0; i < n; i++) {
            link[i] = i;
            comp[i].push_back(i);
        }
    }
 
    void join(int u, int v) {
        u = link[u];
        v = link[v];
        if(u == v) return;
        if(tam[v] > tam[u]) swap(u,v);
        for(int nodo : comp[v]) {
            link[nodo] = u;
            comp[u].push_back(nodo);
        }
        tam[u] += tam[v];
        tam[v] = 0;
        comp[v].clear();
    }
 
    bool same(int u, int v) {
        return link[u] == link[v];
    }
 
    int findLink(int u) {
        return link[u];
    }
 
    int calcTam(int u) {
        return tam[link[u]];
    }
 
};