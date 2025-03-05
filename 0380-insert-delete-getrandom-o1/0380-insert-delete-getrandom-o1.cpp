class RandomizedSet {
public:

    map<int,int>ma;
    vector<int>ve;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ma.find(val) != ma.end()) return false;

        ve.push_back(val);
        ma[val] = ve.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(ma.find(val) == ma.end()) return false;

        int idx = ma[val];
        
        int lastEle = ve.back();
        
        ve.back() = val;
        ma[lastEle] = idx;
        ve.pop_back();
        ma.erase(val);
        ve[idx] = lastEle;
        
        return true;
    }
    
    int getRandom() {
        int sz = ve.size();
        
        return ve[rand()%(sz)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */