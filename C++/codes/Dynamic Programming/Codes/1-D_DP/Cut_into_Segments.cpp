// https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=PROBLEM
// Same as Min_Coins.cpp but replace min with max function

// Top Down Approach
// T.C. = O(x*n)
// S.C. = O(x)

// Bottom Up Approach
// T.C. = O(x*n)
// S.C. = O(x)

int solveTop(vector<int> &nums, int n, vector<int> &dp){
	// Base Case
	if (n == 0){
		return 0;
	}
	if (n < 0){
		return -1;
	}

	if (dp[n] != -2){
		return dp[n];
	}

	dp[n] = -1;

	for(int i=0;i<nums.size();i++){
		int ans = solveTop(nums,n-nums[i],dp);
		if (ans != -1){
			dp[n] = max(dp[n],1+ans);
		}
	}
	return dp[n];
}

int solveBottom(vector<int> &nums, int n){
	vector<int> dp(n+1,-1);
	dp[0] = 0;

	for(int i=1;i<=n;i++){
        for(int j = 0; j<nums.size(); j++){
            if (i - nums[j] >= 0 && dp[i-nums[j]] != -1){
                dp[i] = max(dp[i],1+dp[i-nums[j]]);
            }
        }
    }
	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int> nums;
	nums.push_back(x);
	nums.push_back(y);
	nums.push_back(z);

	vector<int> dp(n+1,-2);
	// int ans = solveTop(nums, n, dp);
	int ans = solveBottom(nums, n);
	if (ans == -1){
		ans = 0;
	}
	return ans;
}