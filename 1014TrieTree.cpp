#include<iostream>
#include<string>
using namespace std;

const int MAX = 26;

struct TrieNode{
	int counts;
	bool isWord;
	TrieNode* next[MAX];
	//constructor
	TrieNode(){
		counts = 0;
		isWord = false;
		for(int i = 0; i < MAX; ++i)
			next[i] = NULL;
	}
};

void insertNode(TrieNode* root, string word){
	 int n = word.length();
	 if(root == NULL || n == 0) return;
	 TrieNode* p = root;
	 for(int i = 0; i < n; ++i){
		 if(p -> next[ word[i] - 'a'] == NULL){ //insert the node
			  p -> next[ word[i]-'a' ] = new TrieNode();
			  p -> next[ word[i] - 'a'] -> counts  = 1; // counts initializes 1
		 }else{
			  p -> next[word[i] - 'a' ] -> counts ++;
		 }
		 p = p -> next[ word[i] - 'a' ];
	 }
	 p -> isWord = true;

}

int search(TrieNode*root, string word){
	int n = word.length();
	if(root == NULL || n == 0) return 0;
	TrieNode* p = root;
	for(int i = 0; i < n; ++i){
		  if(p -> next[ word[i] - 'a'] == NULL)  return 0;
		  p = p -> next[ word[i] - 'a' ];		 
	  }
	return  (p == NULL? 0: p -> counts);
}

int main(void){
	int nodeNum, testNum;
	TrieNode* root =  new TrieNode();   // a dummy root  node
	string words;
	cin >> nodeNum;
	for(int i =0; i < nodeNum; ++i){
		cin >> words;
		insertNode(root, words);
	}
	cin >> testNum;
	for(int i = 0; i < testNum; ++i){
		 cin >> words;
		 cout << search(root,words) << endl;
	}
	return 0;
}