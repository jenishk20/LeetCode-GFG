class NumberContainers {
public:
    map<int,int>ma;
    map<int,set<int>>container;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ma.find(index) == ma.end()){
            ma[index] = number;
            container[number].insert(index);
        }
        else{
            if(ma[index] == number) return;
            set<int>temp = container[ma[index]];
            auto it = temp.find(index);
            temp.erase(it);
            container[number].insert(index);

            if(temp.size() == 0){
                container.erase(ma[index]);
            }
            else
                container[ma[index]] = temp;
                
            ma[index] = number;
            
        }
        
    }
    
    int find(int number) {
        if(container.find(number) == container.end()) return -1;
        return *(container[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */