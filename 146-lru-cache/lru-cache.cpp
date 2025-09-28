class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> umap;

    int n;
    LRUCache(int capacity) { n = capacity; }

    void makeRecentUsed(int key) {
        dll.erase(umap[key].first);
        dll.push_front(key);

        umap[key].first = dll.begin();
    }

    int get(int key) {
        if (umap.find(key) == umap.end())
            return -1;

        makeRecentUsed(key);
        return umap[key].second;
    }

    void put(int key, int value) {

        if (umap.find(key) != umap.end()) {
            umap[key].second = value;
            makeRecentUsed(key);
        } else {
            dll.push_front(key);
            umap[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            int del_key = dll.back();
            umap.erase(del_key);

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