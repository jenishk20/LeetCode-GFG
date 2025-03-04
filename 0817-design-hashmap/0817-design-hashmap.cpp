class MyHashMap {
public:
    vector<list<pair<int,int>>>buckets;
    int sz = 10000;
    MyHashMap() {
        buckets.resize(sz);
    }
    
    void put(int key, int value) {
        int no = key%sz;
        auto &it = buckets[no];
        for(auto &itr : it){
            if(itr.first == key){
                itr.second = value;
                return;
            }
        }
        it.emplace_back(key,value);
    }
    
    int get(int key) {
        int no = key%sz;
        auto &it = buckets[no];
        for(auto itr : it){
            if(itr.first == key){
                return itr.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int no = key%sz;
        auto &it = buckets[no];
        for(auto itr = it.begin();itr != it.end();itr++){
            if(itr->first == key){
                it.erase(itr);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */