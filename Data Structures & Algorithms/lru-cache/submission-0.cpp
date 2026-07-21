class LRUCache {
public://brute force -> using pair vector
    vector<pair<int,int>>cache;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                int val=cache[i].second;

                //used hua h abhi to vapas push back krdo
                pair<int,int>temp=cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        //agar pehle se key exist krta h to new value ke corresponding push krna h na
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});//push new pair
                return;
            }
        }
        //if key is not present to check kro kahi size full to nhi h
        if(cache.size()==n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }
        else{
            //agar size bhi full nhi h to simple push krdo
            cache.push_back({key,value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */