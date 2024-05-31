#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

double squareRoot(ll number, ll precision)
{
    ll start = 0, end = number;
    ll mid;
 
    // variable to store the answer
    float ans;
 
    // for computing integral part
    // of square root of number
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
 
        // incrementing start if integral
        // part lies on right side of the mid
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }
 
        // decrementing end if integral part
        // lies on the left side of the mid
        else {
            end = mid - 1;
        }
    }
 
    // For computing the fractional part
    // of square root upto given precision
    float increment = 0.1;
    for (ll i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
 
        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
	    ll r; cin>>r;
	    ll c = 0;
	    for (int k=0; k<=r; k++){
	        ll x = r-k;
	        ll a = squareRoot(pow(r,2)-pow(x,2), 3);
	        ll b = squareRoot(pow(r+1,2)-pow(x,2), 3);
	        if (pow(x,2) + pow(b,2) == pow(r+1,2)) b--;
	        if (pow(x,2) + pow(a,2) < pow(r,2)) a++;
	        c += b-a+1;
	        
	    }
	    c -= 2;
	    c *= 4;
	    c += 4;
	    cout<<c<<endl;
	}
	return 0;
}