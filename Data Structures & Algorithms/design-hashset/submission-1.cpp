class MyHashSet {
public:
    //optimal approach-> using list
    vector<list<int>>buckets;//no {key,value}pair , only key exists here
    int size=10000;
    MyHashSet() {
        buckets.resize(size);
    }
    
    void add(int key) {
        int bucket_no=key%size;

        auto &chain=buckets[bucket_no];//linked list milgyi , yahi humari chain h.

        //check kro key already present to nhi h
        for(auto &it:chain){
            if(it==key){
                return;
            }
        }
        chain.emplace_back(key);//insert kro agar key pehle se nhi h to
    }
    
    void remove(int key) {
        int bucket_no=key%size;
        
        auto &chain=buckets[bucket_no];//linked list milgyi , yahi humari chain h.

        for(auto it=chain.begin();it!=chain.end();it++){
            if(*it==key){
                chain.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int bucket_no=key%size;

        auto &chain=buckets[bucket_no];//linked list milgyi , yahi humari chain h.

        if(chain.empty()){
            return false;
        }

        for(auto &it:chain){
            if(it==key){
                return true;//key milgyi in list
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */