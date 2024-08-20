vector<int> dijkstra(int n,vector<vector<int>>& adj,int s){
    vector<int> dis(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int node=q.top().second;
        int d=q.top().first;
        q.pop();
        for(auto it:adj){
            if(dis[it[0]]>it[1]+d){
                dis[it[0]]=it[1]+d;
                q.push({it[1]+d,it[0]});
            }
        }
    }
    return dis;
}