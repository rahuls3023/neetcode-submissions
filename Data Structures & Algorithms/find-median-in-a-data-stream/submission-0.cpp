class MedianFinder {
public:
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num<left_max_heap.top()){
            left_max_heap.push(num);
        }   
        else{
            right_min_heap.push(num);
        }

        //always maintain the left_max_heap size+1 then right max heap size or equal to it

        if(left_max_heap.size()>right_min_heap.size()+1){
            //mtlb +1 to size ho skta tha but agar usse bhi jyada h to dikt h
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        // agar right ka size left se zyada ho gaya,
        // to right ka smallest element left me daal do
        else if(right_min_heap.size()>left_max_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        //agar dono ka size equal h iska mtlb even number of elements hai
        if(left_max_heap.size()==right_min_heap.size()){
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        else{
            //odd number of elements the
            return left_max_heap.top();
        }
    }
};
