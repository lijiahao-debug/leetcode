#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class LRUCache {
private:
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (!m.count(key))
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    void put(int key, int value) {
        if (m.count(key)) {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size) {
            int temp = l.back().first;
            l.pop_back();
            m.erase(temp);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

int main() {

    return 0;
}