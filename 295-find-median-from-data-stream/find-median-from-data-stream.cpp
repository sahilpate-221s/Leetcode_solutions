class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> right_minHeap;
    priority_queue<int> left_maxHeap;
    MedianFinder() {}

    void addNum(int num) {
        left_maxHeap.push(num);

        // Step 2: balance -> move top of left to right
        right_minHeap.push(left_maxHeap.top());
        left_maxHeap.pop();

        if (left_maxHeap.size() - right_minHeap.size() > 1) {
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }

    double findMedian() {
        if (left_maxHeap.size() == right_minHeap.size()) {
            double val = (left_maxHeap.top() + right_minHeap.top()) / 2.0;
            return val;
        }
        return left_maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */