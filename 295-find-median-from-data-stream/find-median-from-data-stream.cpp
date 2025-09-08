class MedianFinder {
public:
// we create two headps one left_max_heap and right_min_heap

    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>, greater<int>>right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // we will make sure that the left max heap size should be greater than the right min heap
        if(left_max_heap.empty() || num < left_max_heap.top())
        {
            left_max_heap.push(num);
        }
        else
        {
            right_min_heap.push(num);
        }

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1)
        {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size())
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size())
        {
            double median = (left_max_heap.top() + right_min_heap.top() ) / 2.0;
            return median;
        }
        // agar odd numberes hai to left max heap se nikal denge
        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */