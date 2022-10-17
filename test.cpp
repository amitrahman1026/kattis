#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

struct vector_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &v) const
    {
        return std::hash<T1>()(v.size());    
    }
};

int main(){
    vector<vector<string>> ans;
    unordered_map<vector<int>,vector<string>,vector_hash> m;
    string strs[6] = ["eat","tea","tan","ate","nat","bat"];
    for(int i = 0; i < strs.size(); i++){ // for each string, find its key(counting sort vector)
        // hash it
        string s = strs[i];
        vector<int> key(26,0);
        for(int j = 0; j < s.size(); j++){
            key[s[j]-'a']++;
        }
        if(!m.count(key)){
            vector<string> v;
            m[key] = v;
        }
        m[key].push_back(s);
    }
    for(auto i: m){
        ans.push_back(i);
    }
    return 0;
}