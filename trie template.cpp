#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define asc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(x) for(int i=0; i<x; i++)
#define forj(x) for(int j=0; j<x; j++)

const int N = 1000001;
int flag=0;
struct node{
	int words;
	int prefixes;
	node* edges[10];

	node(){
		words = 0;
		prefixes = 0;
		fori(10)edges[i] = NULL;
	}

};

char firstchar(){
	char c;
	return c;
}

class trie{

	public:
		node* root;
	trie(){
		root = new node();
	}

	// void insert(node* ptr,string s){
	// 	if (s.empty()){
	// 		ptr->words = ptr->words + 1;
	// 	}
	// 	else{
	// 		ptr->prefixes = ptr->prefixes + 1;
	// 		char c = firstchar();
	// 		if (ptr->edges[c - '0'] == NULL){
	// 			ptr->edges[c - '0'] = new node();
	// 		}
	// 		//cutchar
	// 		insert(ptr->edges[c - '0'], s);
	// 	}
	// }

	// int countPrefixes(node* ptr, string s){
	// 	if (s.empty()){
	// 		return ptr->prefixes;
	// 	}
	// 	else{
	// 		char c = firstchar();
	// 		if (ptr->edges[c - '0'] == NULL){
	// 			return 0;
	// 		}
	// 		else{
	// 			//cutchar
	// 			countPrefixes(ptr->edges[c - '0'], s);
	// 		}
	// 	}
	// }

	int countPrefixes( string s){
		node* ptr=root;
		int len=s.length();
		fori(len){
			char c = s[i];
			if (ptr->edges[c - '0'] == NULL){
				return 0;
			}
			else{
				ptr=ptr->edges[c-'0'];
			}
		}
		return ptr->prefixes;
	}
	int countWords( string s){
		node* ptr=root;
		int len=s.length();
		fori(len){
			char c = s[i];
			if (ptr->edges[c - '0'] == NULL){
				return 0;
			}
			else{
				ptr=ptr->edges[c-'0'];
			}
		}
		return ptr->words;
	}

	void insert(string s){
		int len=s.length();
		node* ptr=root;
		fori(len){
			
			ptr->prefixes = ptr->prefixes + 1;
			if(ptr->prefixes>0 && ptr->words>0)flag=1;
			char c=s[i];
			if (ptr->edges[c - '0'] == NULL){
				ptr->edges[c - '0'] = new node();
			}
			ptr=ptr->edges[c-'0'];
			
		}
		ptr->words=ptr->words+1;		
	}

	// int countWords(node* ptr, string s){
	// 	if (s.empty()){
	// 		return ptr->prefixes;
	// 	}
	// 	else{
	// 		char c = firstchar();
	// 		if (ptr->edges[c - '0'] == NULL){
	// 			return 0;
	// 		}
	// 		else{
	// 			//cutchar
	// 			countWords(ptr->edges[c - '0'], s);
	// 		}
	// 	}
	// }
};

　

int main(){
		int t;
		sc(t);
		while(t--){
			trie mytrie=new trie();
			flag=0;
			int n;
			string s;
			fori(n){
				cin>>s;
				mytrie.insert(s);
			}
			if(flag==0)printf("%s\n","NO");
			else printf("%s\n", "YES");
		}
}




 
