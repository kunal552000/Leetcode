/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the 
mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/


//CODE


class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<long> maxh;
    priority_queue<long,vector<long>,greater<long>> minh;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxh.empty() || maxh.top() > num)
            maxh.push(num);
        
        else
            minh.push(num);
        
        if(maxh.size() > minh.size()+1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        
        else if(minh.size() > maxh.size() + 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
        
    }
    
    double findMedian() {
        
        if(maxh.size() == minh.size())
            return (maxh.top() + minh.top()) / 2.0;
        
        else if(maxh.size() > minh.size())
            return (2 * maxh.top()) / 2.0;
        
        return (2 * minh.top()) / 2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
