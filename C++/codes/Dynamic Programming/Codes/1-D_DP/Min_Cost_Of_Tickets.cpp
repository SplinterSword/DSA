// https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

// Top Down Approach
// T.C. = O(1)
// S.C. = O(n)

// Bottom Up Approach
// T.C. = O(1)
// S.C. = O(n)

// Bottom Up Space Optimisation Approach
// T.C. = O(1)
// S.C. = O(1)


int bruteForce(int n, vector<int> &days, vector<int> &cost, int index){
    // Base Case
    if (index >= n){
        return 0;
    }

    // 1 day pass
    int option1 = cost[0]+ bruteForce(n, days, cost, index+1);
    
    // 7 day pass
    int i;
    for(i = index; i<n&&days[i] < days[index] + 7; i++);
    int option2 = cost[1] + bruteForce(n, days, cost, i);

    // 30 day pass
    for(i = index; i<n&&days[i] < days[index] + 30; i++);
    int option3 = cost[2] + bruteForce(n, days, cost, i);

    return min(option1, min(option2,option3));
}

int solveTop(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    // Base Case
    if (index >= n){
        return 0;
    }

    if (dp[index] != -1){
        return dp[index];
    }

    // 1 day pass
    int option1 = cost[0]+ solveTop(n, days, cost, index+1, dp);
    
    // 7 day pass
    int i;
    for(i = index; i<n&&days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solveTop(n, days, cost, i, dp);

    // 30 day pass
    for(i = index; i<n&&days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solveTop(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2,option3));
    return dp[index];
}

int solveBottom(int n, vector<int> &days, vector<int> &cost){

    // Base Case
    vector<int> dp(n+1,INT_MAX);
    dp[n] = 0;

    for (int k=n-1; k>=0; k--){
        // 1 day pass
        int option1 = cost[0]+ dp[k+1];
        
        // 7 day pass
        int i;
        for(i = k; i<n&&days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        // 30 day pass
        for(i = k; i<n&&days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2,option3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Brute Force Method
    // return bruteForce(n, days, cost, 0); 

    // Top Down Method
    // vector<int> dp(n+1, -1);
    // return solveTop(n, days, cost, 0, dp);

    // Bottom up Approach
    // return solveBottom(n, days, cost);

    // Bottom up Space Optimisation Approach
    int ans = 0;

    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for( int day: days){

        //step1: remove expired days
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }

        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }

        //step2: add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        //step3: ans update
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}