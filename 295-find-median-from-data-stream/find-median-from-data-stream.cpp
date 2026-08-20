class MedianFinder {
public:

    // Smaller half
    priority_queue<int> maxHeap;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // Step 1: Put number into maxHeap
        maxHeap.push(num);

        // Step 2: Make sure every element
        // in maxHeap <= every element in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int x = maxHeap.top();
            maxHeap.pop();

            minHeap.push(x);
        }

        // Step 3: Balance sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            int x = maxHeap.top();
            maxHeap.pop();

            minHeap.push(x);
        }
        else if (minHeap.size() > maxHeap.size()) {
            int x = minHeap.top();
            minHeap.pop();

            maxHeap.push(x);
        }
    }
    
    double findMedian() {

        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Even number of elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};