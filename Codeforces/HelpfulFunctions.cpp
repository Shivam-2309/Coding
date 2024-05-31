/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define endl '\n'
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
bool sieve[NUM];
void sieveOfEratosthenes() {
    memset(sieve, true, sizeof(sieve));
    sieve[1] = false;
    sieve[0] = false; 
    for (ll p = 2; p * p <= NUM; p++) {
        if (sieve[p]) {
            for (ll i = p * p; i <= NUM; i += p)
                sieve[i] = false;
        }
    }
}
    // Computation of String Matching in O(M+N) time
    void computeLPSArray(string &pat, int M, int *lps)
	{
		int len = 0;
		lps[0] = 0;
		int i = 1;

		while (i < M)
		{
			if (pat[i] == pat[len])
			{
				len++;
				lps[i] = len;
				i++;
			}
			else
			{
				if (len != 0)
				{
					len = lps[len - 1];
				}
				else
				{
					lps[i] = 0;
					i++;
				}
			}
		}
	}

	vector<int> KMPSearch(string &pat, string &txt)
	{
		vector<int> v;
		int M = pat.length();
		int N = txt.length();
		int lps[M];
		computeLPSArray(pat, M, lps);

		int i = 0;
		int j = 0;
		while (i < N)
		{
			if (pat[j] == txt[i])
			{
				j++;
				i++;
			}

			if (j == M)
			{
				v.push_back(i - j);
				j = lps[j - 1];
			}
			else if (i < N && pat[j] != txt[i])
			{
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}

		return v;
	}
// returns sorted prime factorisation in sqrt(N)
vector<ll> primefactorisation1(int n)
{
    vector<ll> factorisation;
    for (ll d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorisation.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
    {
        factorisation.push_back(n);
    }
    return factorisation;
}
// O(r) Time Complexity
ll nCr(int n, int r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

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

// This would return a new array which contains the indexes in o
vector<ll> srtOnIndexes(vector<ll> &v){
    ll n = v.size();
    vector<ll> ord(n);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int i, int j){
        return v[i] > v[j];
    });
    return ord;
}

// ll mminvprime(ll a, ll b)
// { // gives modulo inverse of a wrt b where b is prime
//     return binpowmod(a, b - 2, b);
// }
// ll mod_add(ll a, ll b, ll m=MOD)
// {
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mod_mul(ll a, ll b, ll m=MOD)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll mod_sub(ll a, ll b, ll m=MOD)
// {
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mod_div(ll a, ll b, ll m=MOD)
// {
//     a = a % m;
//     b = b % m;
//     return (mod_mul(a, mminvprime(b, m), m) + m) % m;
// }

vector<int> dijkstra(int n, int src, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e7);
        vector<bool> vis(n,false);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = true;

            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < dist[v])
                {
                    dist[v] = dis + w;
                    pq.push({dist[v], v});
                }
            }
        }
     return dist;
}

void add_divs(ll x, map<ll, ll>&divs){
    // In a map it stores all the prime divisors of a number
    ll i = 2;
    while(i * i <= x){
        while (x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) divs[x]++;
}

void insertionSort(vector<ll> &v){
    ll n = v.size();

    for(ll i=1; i<n; i++){
        ll j = i;
        while(j >= 1 && v[j]<v[j-1]){
            swap(v[j], v[j-1]);
            j--;
        }
    }

    for(ll i=0; i<n; i++){
        cout << v[i] << " ";
    }cout << endl;
}

void bubbleSort(vector<ll> &v){
    ll n = v.size();

    for(ll i=n-1; i>=0; i--){
        for(ll j=0; j<i; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }

    for(ll i=0; i<n; i++){
        cout << v[i] << " ";
    }cout << endl;
}

void selectionSort(vector<ll> &v){
    ll n = v.size();

    for(ll i=0; i<n; i++){
        ll mini = i;
        for(ll j=i+1; j<n; j++){
            if(v[j] < v[i]){
                mini = j;
            }
        }
        swap(v[i], v[mini]);
    }

    for(ll i=0; i<n; i++){
        cout << v[i] << " ";
    }cout << endl;
}

void m2sa(vector<ll> &arr, ll low, ll mid, ll high){
    vector<ll> temp; 
    ll left = low;      
    ll right = mid + 1;   

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(ll s, ll e, vector<ll> &v){
    if(s >= e){
        return;
    }

    ll mid = (s + e)/2;
    mergeSort(s, mid, v);
    mergeSort(mid+1, e, v);
    // Left and Right are now sorted
    // Now I need to merge two sorted arrays such that (s -> mid && mid+1 -> e are already sorted)
    m2sa(v, s, mid, e);
}

ll findPartition(ll lo, vector<ll> &v){
    ll n = v.size();
    ll cnt = 0;
    ll val = v[lo];

    for(ll i=0; i<n; i++){
        if(v[i] < val) cnt++;
    }

    swap(v[cnt], v[lo]);

    ll i = cnt+1;
    ll j = lo;

    while(i < n && j < cnt){
        if(v[i] > val && v[j] < val){
            swap(v[i], v[j]);
            i++;
            j++;
        }
        else if(v[i] > val && v[j] > val){
            j++;
        }
        else{
            i++;
        }
    }
}

void quickSort(ll lo, ll hi, vector<ll> &v){
    if(lo < hi){
        ll partitionIndex = findPartition(lo, v);
        quickSort(lo, partitionIndex-1, v);
        quickSort(partitionIndex+1, hi, v);
    }
}

void solve(){
    vector<ll> arr = {5,8,3,2,1,6};
    // vector<ll> IndexedArr = srtOnIndexes(arr);
    quickSort(0, arr.size()-1, arr);
    for(ll i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }cout << endl;
    // for(auto &it: IndexedArr){
    //     cout << it << " ";
    // }cout << endl;
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
// Read the question again

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> denominations;
    denominations.push_back(2);
    denominations.push_back(3);
    denominations.push_back(5);
    f(0, 8, ds, ans, denominations);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 0;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */
