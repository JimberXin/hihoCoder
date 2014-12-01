#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<vector<int> > triangle){
   int n = triangle.size();
   if(n == 0) return 0;
   int* dp = new int[n];
   dp[0] =triangle[0][0];
   int i, j = 0;
   for(i = 1; i < n; ++i){
     dp[i] = dp[i-1] + triangle[i][i];  // deal with n-1
     for(j = i-1; j > 0; --j) 
       dp[j] = triangle[i][j] + max(dp[j-1], dp[j]);  //deal with 1-- (n-2)
     dp[0] = dp[0] + triangle[i][0];    //deal with 0
   }
   int result = 0;
   for(int i = 0; i < n; ++i)
     result = max(result, dp[i]);
   delete[] dp;
   return result;
}

int main(void){
	
   int level, elements;
   cin >> level;
   vector<vector<int> > triangle;
   vector<int> each;
   for(int i = 0; i< level; ++i){
     for(int j = 0; j <= i; ++j){
       cin >> elements;
       each.push_back(elements);
     }
     triangle.push_back(each);
     each.clear();
   }
   int res = maxSum(triangle);
   cout << res << endl;
   return 0;
}
