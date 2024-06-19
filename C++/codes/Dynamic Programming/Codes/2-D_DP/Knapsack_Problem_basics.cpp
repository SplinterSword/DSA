// https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=SUBMISSION

// Brute Force Recursive Approach
// T.C. = O(n)
// S.C. = O(n)

// Top Down Approach
// T.C. = O(n*capacity)
// S.C. = O(n*capacity)

// Bottom Up Approach
// T.C. = O(n*capacity)
// S.C. = O(n*capacity)

// Bottom Up Space Optimisation Approach 
// T.C. = O(n)
// S.C. = O(2*capacity)

// Bottom Up Best Space Optimisation Approach
// T.C. = O(n)
// S.C. = O(capacity)

#include <bits/stdc++.h> 
int bruteForce(vector<int> &weight, vector<int> &value, int index, int capacity){
	// Base case
	// if only 1 item to steal, then just compare its weight with the knapsack capacity
	if (index == 0){
		if (weight[0] <= capacity){
			return value[0];
		}
		else{
			return 0;
		}
	}

	int include = 0;
	if (weight[index] <= capacity){
		include = value[index] + bruteForce(weight,value,index-1,capacity-weight[index]);
	}

	int exclude = 0 + bruteForce(weight,value,index-1,capacity);

	int ans = max(exclude,include);
	return ans;
}

int solveTopDown(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp){
	// Base case
	// if only 1 item to steal, then just compare its weight with the knapsack capacity
	if (index == 0){
		if (weight[0] <= capacity){
			return value[0];
		}
		else{
			return 0;
		}
	}

	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	int include = 0;
	if (weight[index] <= capacity){
		include = value[index] + solveTopDown(weight,value,index-1,capacity-weight[index],dp);
	}

	int exclude = 0 + solveTopDown(weight,value,index-1,capacity,dp);

	dp[index][capacity] = max(exclude,include);
	return dp[index][capacity];
}

int solveBottomUp(vector<int> &weight, vector<int> &value, int n, int capacity){
	
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));
	// Base case
	for(int w = weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity){
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
	}


	for(int i = 1; i<n; i++){
		for(int w=0; w<=capacity; w++){

			int include = 0;
			if (weight[i] <= w){
				include = value[i] + dp[i-1][w-weight[i]];
			}

			int exclude = 0 + dp[i-1][w];

			dp[i][w] = max(exclude,include);
		}
	}
	return dp[n-1][capacity];
}

int solveBottomUpSpaceOptimisation(vector<int> &weight, vector<int> &value, int n, int capacity){
	
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
	// Base case
	for(int w = weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity){
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
	}


	for(int i = 1; i<n; i++){
		for(int w=0; w<=capacity; w++){

			int include = 0;
			if (weight[i] <= w){
				include = value[i] + prev[w-weight[i]];
			}

			int exclude = 0 + prev[w];

			curr[w] = max(exclude,include);
		}
		prev = curr;
	}
	return prev[capacity];
}

int solveBottomUpBestSpaceOptimisation(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<int> curr(capacity+1, 0);
	// Base case
	for(int w = weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity){
			curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
	}


	for(int i = 1; i<n; i++){
		for(int w=capacity; w>=0; w--){

			int include = 0;
			if (weight[i] <= w){
				include = value[i] + curr[w-weight[i]];
			}

			int exclude = 0 + curr[w];

			curr[w] = max(exclude,include);
		}
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// brute force approach
	// return bruteForce(weight, value, n-1, maxWeight);

	// Top Down Approach
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
	// return solveTopDown(weight, value, n-1, maxWeight,dp);

	// Bottom Up Approach
	// return solveBottomUp(weight, value, n, maxWeight);

	// Bottom Up Space Optimisation Approach 
	// return solveBottomUpSpaceOptimisation(weight, value, n, maxWeight);

	// Bottom Up Best Space Optimisation Approach
	return solveBottomUpBestSpaceOptimisation(weight, value, n, maxWeight);
}