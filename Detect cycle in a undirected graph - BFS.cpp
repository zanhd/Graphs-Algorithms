#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD ((ll) 1e9 + 7)
#define MOD2 ((ll) 1e9 + 9)
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b)
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

const int N = 1e6 + 1;
vector<int> vis(N, 0);
vector<int> adj[N];

bool isCycle(int u)
{
	queue<pair<int, int>> Q; //{node,parent}
	Q.push({u, -1});
	vis[u] = 1;
	while (!Q.empty())
	{
		int node = Q.front().first;
		int parent = Q.front().second;
		Q.pop();

		for (auto v : adj[node])
		{
			if (v == parent) continue;
			if (vis[v]) return 1;

			Q.push({v, node});
			vis[v] = 1;
		}
	}
	return 0;
}

void Solve()
{
	int n, e; cin >> n >> e;

	loop(i, 1, e)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool is = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		if (isCycle(i)) { is = 1; break; } //checking each components of graph
	}
	cout << ((is) ? "Yes" : "No") << endl;
}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}