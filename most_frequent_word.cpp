#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

// Brute Force Approach:
// TC: O(n^2)
// AS: O(1)
// string mostFrequentWord(string arr[], int n) 
// {
//     map<int, pair<int, string>> hashmap;
//     int max_freq_key = 0;
//     for(int i = 0; i < n; i++){
//         int flag = true;
//         for (auto x = hashmap.begin(); x != hashmap.end(); x++){
//             if(x->second.second == arr[i]){
//                 x->second.first += 1;
//                 flag = false;
//                 if(hashmap[max_freq_key].first < x->second.first)
//                     max_freq_key = x->first;
//                 break;
//             }
//         }
//         if(flag){
//             hashmap[i].first += 1;
//             hashmap[i].second = arr[i];
//         }
//     }
//     for(auto x: hashmap){
//         if(hashmap[max_freq_key].first == x.second.first)
//             max_freq_key = x.first;
//     }
//     // for(auto x: hashmap)
//     //     cout<< x.first<< " - {"<< x.second.first<< ":"<< x.second.second<< "} "<< endl;
    
//     return hashmap[max_freq_key].second;
// }

// Optimal Approach:
// TC: O(n)
// AS: O(1)
string mostFrequentWord(string arr[], int n) 
{
    unordered_map<string, int> freq;
    int max_freq = INT_MIN;
    for(int i = 0; i < n; i ++){
        freq[arr[i]]++;
        max_freq = max(max_freq, freq[arr[i]]);
    }
    string result = "";
    for(int i = 0; i < n; i ++){
        if(freq[arr[i]] == max_freq){
            result = arr[i];
            freq[arr[i]]--;
        }
    }
    return result;
}

int main(){
    // string strs[] = {"hit", "ball", "git", "hit", "git", "hit"};
    string strs[] = {"hit", "ball", "git", "hit", "git", "hit", "git"};
    int size = sizeof strs/sizeof strs[0];

    cout<< "\nThe most Frequent Word in a array if string is: "<< mostFrequentWord(strs, size)<< endl;

    return 0;
}