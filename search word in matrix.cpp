#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Trie {
public:
	Trie* childrens[26] = {};
	bool isWord ;
	string word;

	Trie() {
		isWord = false;
		word = "";
	}

	void insert(string word) {
		Trie* curr = this;

		for(auto it:word) {
			it -= 'a';
			if(curr->childrens[it] == nullptr)
				curr->childrens[it] = new Trie();
			curr = curr->childrens[it];
		}

		curr->isWord =true;
		curr->word = word;
	}
};


bool dfs(vector<vector<char>>& board, Trie* root, int i, int j, unordered_set<string>& s) {
	if(root == nullptr)
		return false;

	if(root->isWord)
		s.insert(root->word);

	if(i >= board.size() || i < 0 || j >= board[i].size() || j < 0 || board[i][j] == '#')
		return false;

	char tmp = board[i][j];
	board[i][j] = '#';

	bool ans =  false;

	for(int l = 0; l < 26; l++) {
		char cc = 'a' + l;
		if(root->childrens[l] != nullptr)
			if(i+1<board.size() && i+1>=0 && j>=0 && j<board[0].size()&& board[i+1][j] == cc)
					dfs(board,root->childrens[l],i+1,j,s);

			if(i-1<board.size() && i-1>=0 && j>=0 && j<board[0].size()&& board[i-1][j] == cc)
					dfs(board,root->childrens[l],i-1,j,s);

			if(i<board.size() && i>=0 && j+1>=0 && j+1<board[0].size()&& board[i][j+1] == cc)
				dfs(board,root->childrens[l],i,j+1,s);

			if(i<board.size() && i>=0 && j-1>=0 && j-1<board[0].size()&& board[i][j-1] == cc)
				dfs(board,root->childrens[l],i,j-1,s);

	}

	board[i][j] = tmp;

	return ans;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	unordered_set<string> s;
	Trie  t;

	for(auto word: words) {
		t.insert(word);
	}

	for(int k = 0; k < 26; k++) {
		if(t.childrens[k] != nullptr){
			char aa = 'a' + k;
			Trie* ptr = t.childrens[k];

			if(ptr != nullptr){
				for(int i = 0; i < board.size(); i++) {
					for(int j = 0; j < board[i].size(); j++) {
						if(board[i][j] == aa) {
							dfs(board, t.childrens[k], i, j, s);
						}
					}
				}
			}
		}

	}

	vector<string> ans;

	for(auto it: s)
		ans.push_back(it);

	return ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));

	int wordL;
	cin >> wordL;

	vector<string> words(wordL);


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for(int i = 0; i < wordL; i++) {
		cin >> words[i];
	}


	vector<string> ans = findWords(board, words);

	for(auto it: ans) {
		cout << it << " ";
	}
	return 0;
}
