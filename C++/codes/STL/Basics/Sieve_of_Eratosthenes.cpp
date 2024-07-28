// The most efficient algorithm to find the all the prime no. in a given range

#include <iostream>
#include <vector>
using namespace std;

void sieve_of_eratosthenes(int n){

    // Assume everything as prime
    vector<bool> prime(n,true);

    prime[0] = prime[1] = false;

    // Turn all the non-prime no. false
    for (int i = 2;i*i<=n;i++){
        if (prime[i]){
            for(int j = i*i ;j <= n ;j = j+i){
                prime[j] = false;
            }
        }
    }

    // print all the prime no.
    for (int i=2;i<=n;i++){
        if (prime[i]){
            cout << i << " ";
        }
    }
    return;
}

int main(){
    int n;
    cin>> n;

    // Function to find prime no. in a given range
    sieve_of_eratosthenes(n);
    return 0;
}