class LRUCache {
public:
    list<int> dll;
    // list ke node ka  address  batane ke liye
    map<int, pair<list<int>::iterator, int>> mp;
    // node     // Address aur value store karega map

    int n;
    LRUCache(int capacity) { n = capacity; }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);

        dll.push_front(key);
        // abb key ka address change hua to map me bhi changes hone
        mp[key].first = dll.begin(); // front me DLL me dalne se address o(1) me mil jayega 
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // element ko front me dalne ke liye ye functoin bana rhe hai DLL me
        // dalne ke liye
        makeRecentlyUsed(key);

        return mp[key].second;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0)
        {
            int key_tobe_deleted = dll.back();
            mp.erase(key_tobe_deleted);
            dll.pop_back();
            n++;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */