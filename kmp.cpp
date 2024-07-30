vector<int> kmp(string s){
    vector<int> lps(s.size(),0);
    for(int i=1;i<lps.size();i++){
        int prev_id=lps[i-1];
        while(prev_id>0 && s[i]!=s[prev_id]){
            prev_id=lps[prev_id-1];
        }
        lps[i]=prev_id+(s[i]==s[prev_id]?1:0);
    }
    return lps;
}

// T:O(s.size())
// S: O(s.size())