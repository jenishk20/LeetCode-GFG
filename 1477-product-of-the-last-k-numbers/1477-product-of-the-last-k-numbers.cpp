class ProductOfNumbers {
public:
    vector<int>pfxOfProducts;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(pfxOfProducts.size() == 0){
            pfxOfProducts.push_back(num);
        }
        else{
            int last = pfxOfProducts.back();
            pfxOfProducts.push_back(num);
        }
    }
    
    int getProduct(int k) {
        int ans = 1;
        for(int i=pfxOfProducts.size()-k;i<pfxOfProducts.size();i++){
            if(pfxOfProducts[i] == 0) return 0;
            ans *= pfxOfProducts[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */