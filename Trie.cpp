//Max EOR
class Node {
private:
    Node* links[2];

public:
    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int bit) { return links[bit] != NULL; }

    Node* getKey(int bit) { return links[bit]; }

    void putKey(int bit) { links[bit] = new Node(); }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->putKey(bit);
            }
            node = node->getKey(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int ret = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                ret = ret | (1 << i);
                node = node->getKey(1 - bit);
            } else {
                node = node->getKey(bit);
            }
        }
        return ret;
    }
};

// longest common prefix
class Node{
private:
    Node *links[10];
public:
    Node(){
        for(int i=0;i<10;i++) links[i]=NULL;
    }

    Node *getKey(char ch){
        return links[ch-'0'];
    }

    void putKey(char ch){
        links[ch-'0']=new Node();
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root=new Node;
    }

    void insert(string s){
        Node *node=root;
        for(int i=0;i<s.length();i++){
            if(!node->getKey(s[i])){
                node->putKey(s[i]);
            }
            node=node->getKey(s[i]);
        }
    }

    int getMax(string s){
        Node *node=root;
        int ret=0;
        for(int i=0;i<s.length();i++){
            if(!node->getKey(s[i])) break;
            ret++;
            node=node->getKey(s[i]);
        }
        return ret;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            t.insert(s);
        }
        int ret=0;
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            ret=max(ret,t.getMax(s));
        }
        return ret;
    }
};

TC -> insert -> O(N),  search -> O(N)
SC -> O(N)
