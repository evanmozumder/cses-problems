// https://cses.fi/problemset/task/2431

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll power(ll p){
	ll base=1;
	while(p--)base*=10;
	return base;
}

int main(){
  ll q,k,nth_digit=9,prev;
  cin>>q;
	while(q--){
		cin>>k;
		int i=2;
		prev=9,nth_digit=9;
		if(k<10){ // if k is single digit number
			cout<<k<<endl;
			continue;
		}
		// checking which digit range k falls
		for(i;k>nth_digit;i++){
			prev=nth_digit;
			nth_digit+=(9*i*power(i-1));
		}
		prev+=1; // first i-th digit(3 digit number starts from 190, prev stores that)
		i-=1;
		ll lowest = power(i-1); // lowest i-th digit number(100 is the lowest 3digit number)
		ll digits = k-prev+1; // total number of digits prev to k
		ll nmbr = lowest+(digits/i)-1; // exact number that contains k-th digit
		ll digits_covered = (digits/i)*i; // checking if any digits remain

		if(digits_covered<digits){
			nmbr+=1;
			string ans = to_string(nmbr);
			cout<<ans[digits-digits_covered-1]<<endl;
		}else if(digits==digits_covered){
			string ans = to_string(nmbr);
			cout<<ans.back()<<endl;
		}
	} 
}
