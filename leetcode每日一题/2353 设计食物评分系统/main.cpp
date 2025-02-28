#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            h1[foods[i]] = { ratings[i], cuisines[i] };
            h2[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    }

    void changeRating(string food, int newRating) {
        pair<int, string>& tmp = h1[food];
        auto& st = h2[tmp.second];
        st.erase({ -tmp.first, food });
        st.insert({ -newRating, food });
        tmp.first = newRating;
    }

    string highestRated(string cuisine) {
        return h2[cuisine].begin()->second;
    }
private:
    map<string, pair<int, string>> h1;
    map<string, set<pair<int, string>>> h2;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    
    return 0;
}