#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<string,string> > dict;
    int n,m;
    cin >> n;
    map<string, string> synonym;
    for(int c1 = 0; c1 < n; c1++){
        string s1,s2;
        cin >> s1 >> s2;
        dict.push_back({s1, s2});
        for(int c2 = 0; c2 < c1; c2++){
            assert(s1 != dict[c2].first || s2 != dict[c2].second);
            if(dict[c2].second == s2 && dict[c2].first != s1){
                synonym[s1] = dict[c2].first;
                synonym[dict[c2].first] = s1;
            }
        }
    }

    cin >> m;
    for(int c1 = 0; c1 < m; c1++){
        string word;
        cin >> word;
        if(synonym.find(word) != synonym.end()){
            cout << synonym[word] << " ";
        }
        else{
            cout << word << " ";
        }
    }cout << "\n";
}