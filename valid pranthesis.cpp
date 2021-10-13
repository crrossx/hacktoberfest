#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s) {
	stack<char> st;

	for(char it: s) {
		if(it == '{' || it == '(' || it == '[')
			st.push(it);
		else {
			if(st.empty())
				return false;

			char p = st.top();
			st.pop();

			if(!((p == '[' && it == ']') || (p == '{' && it == '}') || (p == '(' && it == ')')))
				return false;
		}
	}

	if(st.empty())
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << isValid(s) << endl;

	return 0;
}
