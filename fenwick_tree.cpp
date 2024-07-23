// FenwickTree or Binary Indexed Tree

class FenwickTree{
public:
    int len;
    vector<int> bits; // bits arr wil be 1-based pass id according to it

    FenwickTree(int n){
        len=n;
        bits.resize(n+1,0);
    }

    // for point update and range query
    void update(int id, int val){
        while(id<=len){
            bits[id]+=val;
            id+=(id & (-id));
        }
    }

    int query(int id){
        int ret=0;
        while(id>0){
            ret+=bits[id];
            id-=(id & (-id));
        }
        return ret;
    }

    // for range update and point query
    void range_update(int l,int r,int val){
        update(l,val);
        update(r+1,-val);
    }

    int point_query(int id){
        int ret=0;
        while(id>0){
            ret+=bits[id];
            id-=(id & (-id));
        }
        return ret;
    }
};

//for range_update and range_query
class FenwickTree{
public:
    vector<int> bits1,bits2;
    int len;

    FenwickTree(int n){
        len=n;
        bits1.resize(n+1);
        bits2.resize(n+1);
    }

    void update(vector<int>& bits,int id, int val){
        while(id<=len){
            bits[id]+=val;
            id+=(id & (-id));
        }
    }

    int query(vector<int>& bits,int id){
        int ret=0;
        while(id>0){
            ret+=bits[id];
            id-=(id & (-id));
        }
        return ret;
    }

    void range_update(int l,int r,int val){
        update(bits1, l, val);
        update(bits1, r+1, -val);
        update(bits2, l, val*(l-1));
        update(bits2, r+1, -val*r);
    }

    int range_query(int id){
        return query(bits1,id)*id-query(bits2,id);
    }
};

//t: O(log(N))
//s: O(N)

// example
// int main(){
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(3);
//     nums.push_back(4);
//     nums.push_back(7);
//     nums.push_back(10);
//     nums.push_back(15);
//     FenwickTree ft(6);
//     for(int i=0;i<nums.size();i++){
//         ft.update(i+1,nums[i]);
//     }
//     ft.update(3,1);
//     cout<<ft.query(4);
// }
