class DisjointSet{
private:
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++) parent.push_back(i);
    }

    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u),ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUpar(u),ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
