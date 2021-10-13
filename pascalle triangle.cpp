#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	if(numRows == 1)
		return {{1}};

	if(numRows == 2)
		return {{1}, {1, 1}};

	vector<vector<int>> ans;

	ans.push_back({1});
	ans.push_back({1, 1});

	for(int i = 1; i < numRows - 1; i++) {
		vector<int> tmp;
		tmp.push_back(1);

		for(int j = 0; j < ans[i].size() - 1; j++) {
			tmp.push_back(ans[i][j] + ans[i][j+1]);
		}

		tmp.push_back(1);

		ans.push_back(tmp);
	}

	return ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numRows;
	cin >> numRows;

	auto ans = generate(numRows);

	for(auto it:ans){
		for(auto val:it) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}
