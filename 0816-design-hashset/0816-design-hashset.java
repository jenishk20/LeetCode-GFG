class Bucket{
    private LinkedList<Integer>container;
    public Bucket(){
        container = new LinkedList<Integer>();
    }

    public void insert(Integer key){
        int idx = container.indexOf(key);
        if(idx == -1){
            this.container.addFirst(key);
        }
    }
    public void delete(Integer key){
        System.out.println("KEY IS " +  key);
        this.container.remove(key);
    }

    public boolean exists(Integer key){
        return container.indexOf(key) != -1;
    }
}
class MyHashSet {

    private Bucket[] bucketArray;
    private int keyRange;
    public MyHashSet() {
        keyRange = 769;
        bucketArray = new Bucket[keyRange];
        for(int i=0;i<keyRange;i++){
            bucketArray[i] = new Bucket();
        }
    }
    
    public void add(int key) {
        int idx = key % keyRange;
        bucketArray[idx].insert(key);
    }
    
    public void remove(int key) {
        int idx = key % keyRange;
        bucketArray[idx].delete(key);
    }
    
    public boolean contains(int key) {
        int idx = key % keyRange;
        System.out.println(idx);
        return bucketArray[idx].exists(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */