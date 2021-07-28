#include<iostream>
#include<vector>
using namespace std;

int search(string pat, string txt) {
	// Brute Force Approach:
	// #Variation: 01
	// TC: O(n^2)
	// AS: O(1)

    // vector<int> alpha(26, 0);
    // int result = 0, k = pat.length();
    // for(int i = 0; i < k; i++)
    //     alpha[pat[i]-'a']++;
    // vector<int> alpha_checker(26, 0);
	// for(int i = 0; i < txt.length()-k+1; i++){
	//   // fill(alpha_checker.begin(), alpha_checker.end(), 0);
	//   alpha_checker.assign(alpha_checker.size(), 0);
	//    for(int j = i; j < i+k; j++){
	//       // cout<< txt[j];
	//        alpha_checker[txt[j]-'a']++;
	//    }
	//    int flag = true;
	//    for(int i = 0; i < 26; i++){
	//        if(alpha_checker[i] != alpha[i]){
	//            flag = false;
	//           // cout<< " - Break";
	//            break;
	//        }
	//    }
	//    if(flag)
	//        result++;
	//   // cout<< endl;
	// }
	//    return result;
    	
    // #Variation: 02
	// TC: O(n^2)
	// AS: O(1)

	// int gap = 0;
	// for(int i = 0; i <= txt.length(); i++){
	//     for(int i = 0; i < 26; i++)
	//         alpha_checker[i] = 0;
	//    while(i < k)
	//        i++;
	//    for(int j = gap; j < i; j++){
	//         // cout<< txt[j];
	//            alpha_checker[txt[j]-'a']++;
	//        }
	//        int flag = true;
	//        for(int i = 0; i < 26; i++){
	//            if(alpha_checker[i] != alpha[i]){
	//                flag = false;
	//                 // cout<< " - Break";
	//                break;
	//            }
	//        }
	//        if(flag)
	//            result++;
	//         // cout<< endl;
	//        gap++;
	//    }
	//    return result;
	   
	// Optimal Solution:
	// TC: O(n^2)
	// AS: O(1)

    vector<int> count_pat(26, 0), count_txt(26, 0);
    int count = 0;
    for(int i = 0; i < pat.length(); i++)
        count_pat[pat[i]-'a']++;
    for(int i = 0; i < pat.length(); i++)
        count_txt[txt[i]-'a']++;
    int i = 0, j = pat.length()-1, n = txt.length();
    while(i < n and j < n){
        if(count_txt == count_pat)
            count++;
        count_txt[txt[i]-'a']--;
        if(j+1 < n){
            count_txt[txt[j+1]-'a']++;
            j++;
        }
        i++;
    }
    return count;
}

int main(){
	string txt = "forxxorfxdofr", pat = "for";
	// string txt = "aabaabaa", pat = "aaba";

	cout<< "\nNumber of Anagrams for given String in Txt are: "<< search(pat, txt)<< endl;

	return 0;
}

// Sample Input: 01
// forxxorfxdofr
// for
// Output:
// 3

// Sample Input: 02
// aabaabaa
// aaba
// Output:
// 4