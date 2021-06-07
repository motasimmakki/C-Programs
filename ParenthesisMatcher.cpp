#include<iostream>
#include<stack>
#include<tr1/unordered_map>
using namespace std::tr1;
using namespace std;

bool isBalancedParenthesis(string str){
	unordered_map<char, char> hashmap;
	stack<char> stack;
	hashmap['}'] = '{';
	hashmap[']'] = '[';
	hashmap[')'] = '(';

	for(int i = 0; i < str.length(); i++){
		if(hashmap.find(str[i]) == hashmap.end()){
			stack.push(str[i]);
		}
		else{
			if(hashmap[str[i]] == stack.top())
				stack.pop();
			else
				return false;
		}
	}
	if(stack.size() > 0)
		return false;
	return true;
}

int main(){
	// string str = "{}([{}])[]";
	string str = "{}({[}])[]";
	cout<< isBalancedParenthesis(str);
	
	return 0;
}