/*Given a number positive number n, find value of f0 + f1 + f2 + …. + fn where fi indicates i’th Fibonacci number. Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5, …

Input  : n = 3
Output : 4
Explanation : 0 + 1 + 1 + 2  = 4

Input  :  n = 4
Output :  7
Explanation : 0 + 1 + 1 + 2 + 3  = 7
Since the answer can be very large, answer modulo 1000000007 should be printed.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll F[2][2] = {{1,1},{1,0}};

//(a+b)%x = (a%x + b%x)%x
//(a*b)%x = ((a%x) * (b%x))%x
//(a-b)%x = ((a%x) -(b%x) + x)%x;
//(a/b)%x = ((a%x)*(b^-1%x))%x;
//b^-1 is the multiplicative modulo inverse of b and x

void S_multiply(){
    ll x =  (((F[0][0]%1000000007)*(F[0][0]%1000000007))%1000000007 + ((F[0][1]%1000000007)*(F[1][0]%1000000007))%1000000007)%1000000007; 
    ll y =  (((F[0][0]%1000000007)*(F[0][1]%1000000007))%1000000007 + ((F[0][1]%1000000007)*(F[1][1]%1000000007))%1000000007)%1000000007; 
    ll z =  (((F[1][0]%1000000007)*(F[0][0]%1000000007))%1000000007 + ((F[1][1]%1000000007)*(F[1][0]%1000000007))%1000000007)%1000000007; 
    ll w =  (((F[1][0]%1000000007)*(F[0][1]%1000000007))%1000000007 + ((F[1][1]%1000000007)*(F[1][1]%1000000007))%1000000007)%1000000007; 
    
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
}

void multiply(ll M[2][2]){
    ll x =  (((F[0][0]%1000000007)*M[0][0])%1000000007 + ((F[0][1]%1000000007)*M[1][0])%1000000007)%1000000007; 
    ll y =  (((F[0][0]%1000000007)*M[0][1])%1000000007 + ((F[0][1]%1000000007)*M[1][1])%1000000007)%1000000007; 
    ll z =  (((F[1][0]%1000000007)*M[0][0])%1000000007 + ((F[1][1]%1000000007)*M[1][0])%1000000007)%1000000007; 
    ll w =  (((F[1][0]%1000000007)*M[0][1])%1000000007 + ((F[1][1]%1000000007)*M[1][1])%1000000007)%1000000007; 
    
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
}

void power(ll n){
    if(n==0 || n==1) return;
    ll M[2][2] = {{1,1},{1,0}};
    power(n/2);
    S_multiply();
    
    if(n%2!=0){
        multiply(M);
    }
}

ll sumFibonacci(ll n){
    if(n==0) return 0;
    if(n==1) return 2;
    if(n==2) return 3;
    
    //int F[2][2] = {{1,1},{1,0}};
    
    power(n+1);
    return F[0][0];
}

int main()
 {
	ll t;
	cin>>t;
	
	while(t--){
	    F[0][0]=1;
	    F[0][1]=1;
	    F[1][0]=1;
	    F[1][1]=0;
	    ll n;
	    cin>>n;
	    cout<<(sumFibonacci(n)-1)<<endl;
	}
	return 0;
}
