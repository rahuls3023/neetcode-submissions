class LRUCache {
public: // Optimal approach: Doubly linked list + map

    // List sirf keys store karegi.
    //
    // Front = Most Recently Used key
    // Back  = Least Recently Used key
    list<int> dll;

    /*
        Map ka structure:

        key -> {list me key ke node ka address, value}

        mp[key].first  = dll me us key ka iterator/address
        mp[key].second = us key ki actual value
    */
    map<int, pair<list<int>::iterator, int>> mp;

    /*
        n currently available empty spaces ko represent kar raha hai.

        Example:
        Capacity = 3
        Initially n = 3

        Ek new key insert hui:
        n = 2

        Teen keys insert hone ke baad:
        n = 0

        Agar ek aur new key insert hui:
        n = -1
        Iska matlab capacity exceed ho gayi,
        to LRU key delete karni padegi.
    */
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeMostRecentlyUsed(int key) {

        /*
            mp[key].first se dll me us key ke node ka
            iterator/address milega.

            Us node ko current position se remove kar rahe hain.
        */
        dll.erase(mp[key].first);

        /*
            Key abhi access/update hui hai,
            isliye ye most recently used ban gayi.

            Most recently used key ko front me rakhte hain.
        */
        dll.push_front(key);

        /*
            Key ko remove karke dobara front me insert kiya hai,
            isliye dll me iska address change ho gaya.

            Naya address dll.begin() hoga,
            kyunki key ab list ke front me hai.
        */
        mp[key].first = dll.begin();
    }
    
    int get(int key) {

        // Agar key map me nahi hai, cache me bhi nahi hai.
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        /*
            Key mil gayi hai aur abhi access hui hai,
            isliye ise most recently used banana padega.
        */
        makeMostRecentlyUsed(key);

        /*
            mp[key].second me actual value stored hai.

            mp[key]        -> {iterator, value}
            mp[key].second -> value
        */
        return mp[key].second;
    }
    
    void put(int key, int value) {

        // Case 1: Key already cache me present hai
        if (mp.find(key) != mp.end()) {

            /*
                Existing key ki value update kar rahe hain.

                mp[key].second actual value ko represent karta hai.
            */
            mp[key].second = value;

            /*
                Key abhi update hui hai,
                isliye ye most recently used ho gayi.
            */
            makeMostRecentlyUsed(key);
        }

        // Case 2: Key cache me present nahi hai
        else {

            /*
                New key ko front me insert karenge,
                kyunki ye abhi freshly use hui hai.
            */
            dll.push_front(key);

            /*
                Map me store karenge:

                key -> {dll me key ka address, value}

                dll.begin() = newly inserted key ka address
                value       = key ki actual value
            */
            mp[key] = {dll.begin(), value};

            // Ek empty space consume ho gayi
            n--;
        }

        /*
            n < 0 ka matlab capacity exceed ho gayi.

            Ye sirf tab ho sakta hai jab ek new key insert hui ho
            aur cache already full thi.
        */
        if (n < 0) {

            /*
                dll ke back me least recently used key hoti hai.

                dll.back() key deta hai, value nahi.
            */
            int keyToBeDeleted = dll.back();

            /*
                Map se bhi us key ki entry remove karni zaroori hai,
                warna map purane/deleted node ka address store karega.
            */
            mp.erase(keyToBeDeleted);

            // Doubly linked list se LRU key remove kar do
            dll.pop_back();

            /*
                Ek key remove ho gayi,
                isliye available-space count adjust kar diya.

                -1 se dobara 0 ho jayega.
            */
            n++;
        }
    }
};