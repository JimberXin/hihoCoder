#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string stringPreprocess(string str){
	int n = str.length();
	string result;
	if(n == 0) return result;
	result = "$";
	for(int i = 0; i < n; ++i){
		result += "#";
		result += str[i];
	}
	result += "#^"; //different with the first one;
	return result;
}

int longestPal(string str){
	if(str.length() == 0 || str.length() == 1) 
		return str.length();
	string newStr = stringPreprocess(str);
	int n = newStr.length();
	int *P = new int[n];
	int right = 0, center = 1, i_mirror;
	int max_len = 0;
	for(int i = 1; i < n- 1; ++i){ //from 1 to n -1
		 i_mirror = 2*center - i;
		 if(right > i)
			 P[i] = (right - i > P[i_mirror] )?P[i_mirror]: right - i;
		 else
			 P[i] = 0;
		 while(newStr[i + P[i] +1] == newStr[ i - P[i] -1])
			     ++P[i];
		    if(i+P[i] > right){
				 center = i;
				 right = i + P[i];
			}
			max_len = max(max_len, P[i]);
	}
	return max_len;
}
int main(void){
	 int testNum;
	 cin >> testNum;
	 string str;
	 for(int i =0; i < testNum; ++i){
		  cin >> str;
		  cout << longestPal(str) << endl;
	 }
      return 0;
}