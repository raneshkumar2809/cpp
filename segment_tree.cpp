// for range sum
// v=1, tl=0, tr=arr.size()-1
class SegTree{
public:
    int len;
    vector<int> t; // for point update
    // for range update
    vector<int> unpropUpd;
    vector<bool> isLazy;

    SegTree(int l){
        len=l;
        t.resize(4*len);
        unpropUpd.resize(4*len);
        isLazy.resize(4*len);
    }

    // t: o(n)
    void build(vector<int>& a,int v=1,int tl=0,int tr=len-1){
        if(tl==tr){
            t[v]=a[tl];
            return;
        }
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }

    // for point update query
    // t: o(log(n))
    // l and r are indices of query, tl and tr are indices of tree
    int query(int v=1,int tl=0,int tr=len-1,int l,int r){
        if(l>tr || r<tl) return 0;//no overlap
        if(tl>=l && tr<=r) return t[v]; //complete overlap
        int tm=(tl+tr)/2;
        int left=query(2*v,tl,tm,l,r);
        int right=query(2*v+1,tm+1,tr,l,r);
        return left+right;
    }

    // for point update
    //t: o(log(n))
    //id is index to be updated
    void update(int v=1,int tl=0,int tr=len-1,int id,int val){
        if(tl==id and tr==id){
            t[v]=val;
            return;
        }
        if(id>tr || id<tl) return;
        int tm=(tl+tr)/2;
        update(2*v,tl,tm,id,val);
        update(2*v+1,tm+1,tr,id,val);
        t[v]=t[2*v]+t[2*v+1];
    }

    //for range update query
    // t: o(log(n))
    int queryRange(int v=1,int tl=0,int tr=len-1,int l,int r){
        if(tl>r || tr<l1) return 0;
        if(tl>=l && tr=<r) return t[v];

        pushDown(v,tl,tr);
        int tm=(tl+tr)/2;
        int left=queryRange(2*v,tl,tm,l,r);
        int right=queryRange(2*v+1,tm+1,tr,l,r);
        return left+right;
    }

    // for range update
    // t: o(log(n))
    void updateRange(int v=1,int tl=0,int tr=len-1,int l,int r,int val){
        if(tl>r && tr<l) return;
        if(l<=tl && tr<=r){
            apply(v,tl,tr,val);
            return;
        }
        pushDown(int v,int tl,int tr);
        int tm=(tl+tr)/2;
        updateRange(2*v,tl,tm,l,r,val);
        updateRange(2*v+1,tm+1,tr,l,r,val);
        t[v]=t[2*v]+t[2*v+1];
    }

    void apply(int v,int tl,int tr,int val){
        if(tl!=tr){
            isLazy[v]=true;
            unpropUpd[v]+=val;
        }
        t[v]=(tr-tl+1)*val;
    }

    void pushDown(int v,int t1,int tr){
        if(!isLazy[v]) return;

        isLazy[v]=false;
        int tm=(tl+tr)/2;
        apply(2*v,tl,tm,unpropUpd[v]);
        apply(2*v+1,tm+1,tr,unpropUpd[v]);
        unpropUpd[v]=0;
    }
};

// s: o(n)
