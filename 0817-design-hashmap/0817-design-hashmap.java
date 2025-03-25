class Pair<U,V>{
    public U first;
    public V second;
    public Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}

class Bucket{
    private LinkedList<Pair<Integer,Integer>>bucket;
    public Bucket(){
        bucket = new LinkedList<Pair<Integer,Integer>>();
    }

    public Integer find(Integer key){
        for(Pair<Integer,Integer> pair : this.bucket){
            if(pair.first.equals(key)){
                return pair.second;                
            }
        }
        return -1;
    }
    public void update(Integer key,Integer value){
        boolean found  = false;
        for(Pair<Integer,Integer> pair : this.bucket){
            if(pair.first.equals(key)){
                pair.second = value;
                found = true;
            }
        }
        if(!found){
            bucket.add(new Pair<Integer,Integer>(key,value));
        }
    }

    public void remove(Integer key){
        for(Pair<Integer,Integer> pair : this.bucket){
            if(pair.first.equals(key)){
                this.bucket.remove(pair);
                return;
            }
        }
    }
}
class MyHashMap {

    private int keySpace;
    private List<Bucket>hashTable;
    public MyHashMap() {
        keySpace = 769;
        hashTable = new ArrayList<Bucket>();

        for(int i=0;i<keySpace;i++){
            hashTable.add(new Bucket());
        }
    }

    
    public void put(int key, int value) {
        int hashVal = key % keySpace;
        hashTable.get(hashVal).update(key,value);
    }
    
    public int get(int key) {
        int hashVal = key % keySpace;
        return hashTable.get(hashVal).find(key);
    }
    
    public void remove(int key) {
        int hashVal = key % keySpace;
        hashTable.get(hashVal).remove(key);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */