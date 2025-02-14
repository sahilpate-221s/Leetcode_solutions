class ProductOfNumbers {
public:
    vector<int>answer;
    ProductOfNumbers() {
        
    }    
    void add(int num) {
        answer.push_back(num);
    }
    
    int getProduct(int k) {
        // vector<int>temp;
        int temp = 1;
        int n= answer.size();
        int i=n-1;
        while(k--)
        {
            temp *= answer[i];
            i--;
        }
        return temp;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */