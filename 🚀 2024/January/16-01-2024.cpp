//https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;

public:
    RandomizedSet() {
        //already initialized
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
        
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;

        int index = m[val];
        int last = v.back();

        m[last] = index;
        swap(v[index], v[v.size()-1]);

        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
       return v[rand() % v.size()];
    }
};
