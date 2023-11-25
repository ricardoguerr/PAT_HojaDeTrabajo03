#include "Ejercicio02.h"
#include <map>
#include <algorithm>

vector<vector<string>>* Ejercicio02::groupAnagrams(vector<string>& strings)
{
    map<string, vector<string>> anagrams;

    for (string s : strings) {

        string sorted = s;
        sort(sorted.begin(), sorted.end());

        anagrams[sorted].push_back(s);
    }

    vector<vector<string>>* result = new vector<vector<string>>();

    for (auto pair : anagrams) {
        result->push_back(pair.second);
    }

    return result;
}
