class ProductOfNumbers {
public:
    vector<int>pfxOfProducts;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0){
            pfxOfProducts.clear();
            return;
        }
        if(pfxOfProducts.size() == 0){
            pfxOfProducts.push_back(num);
        }
        else{
            int last = pfxOfProducts.back();
            pfxOfProducts.push_back(num*last);
        }
    }
    
    int getProduct(int k) {
        if(pfxOfProducts.size()<k) return 0;
        int sz = pfxOfProducts.size();
        return pfxOfProducts[sz-1]/(sz-k-1<0 ? 1 : pfxOfProducts[sz-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */