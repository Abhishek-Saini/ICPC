#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;
using namespace std;

// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
// #define x first
// #define y second
#define pb push_back
#define mp make_pair
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define Error3(a,b,c) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<")\n";
#define Error4(a,b,c,d) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<")\n";
#define Error5(a,b,c,d,e) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" , "<<#e<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<" , "<<(e)<<")\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) (((x)<<1)+1)
#define R(x) (((x)<<1)+2)
#define umap unordered_map
//#define double long double
#define mod 1000000007
#define mod1 1000000009
#define LIMIT 10000000000000000LL
#define INF 10000000000LL
#define MAX1 1000000000
//#define si(n) scanf("%d",&n)
//#define sii(n,m) scanf("%d%d",&n,&m)
//#define pi(n) printf("%d\n",n)
const int inf=0x3f3f3f3f;
const long double pi=acos(-1.0);
#define MAX 50010
// #define N 100000
const string debug_line="yolo";
#define debug error(debug_line)
const double PI=4*atan(1);
#define read() freopen("mergedoutput.txt","r",stdin)
#define write() freopen("output.txt","w",stdout)
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;

class BracketSequenceDiv2
{
public:
	ll dp[101][101];
	bool visited[101][101];

	int getPos(int index,char c,string &s){
		int size1=s.size();
		int answer1=s.size();
		For(i,index,size1){
			if(s[i]==c){
				answer1=i;
				break;
			}
		}
		return answer1;
	}

	void tryAll(int b,int numOpen,string &s){
		// Error(b,numOpen);
		if(visited[b][numOpen]){
			return ;
		}
		else{
			if(b==s.size()){
				if(numOpen==0){
					dp[b][numOpen]=1;
					visited[b][numOpen]=true;
					return ;
				}
				else{
					dp[b][numOpen]=0;
					visited[b][numOpen]=true;
					return ;
				}
			}
			else{
				ll res=0;
				if(numOpen==0){
					res++;
				}
				int getFirstPos=getPos(b,'(',s);
				if(numOpen+1<=(s.size()/2) && getFirstPos<s.size()){
					tryAll(getFirstPos+1,numOpen+1,s);
					res=(res+dp[getFirstPos+1][numOpen+1])%mod;
				}
				getFirstPos=getPos(b,')',s);
				if(numOpen>0 && getFirstPos<s.size()){
					//Error3(b,getFirstPos+1,numOpen-1);
					tryAll(getFirstPos+1,numOpen-1,s);
					res=(res+dp[getFirstPos+1][numOpen-1])%mod;
				}
				dp[b][numOpen]=res;
				// Error3(b,numOpen,res);
				visited[b][numOpen]=true;
				return ;
			}
		}
	}

	int count(string s){
		tryAll(0,0,s);
		ll answer1=((dp[0][0]-1)%mod+mod)%mod;
		return answer1;
	}
};

// int main(){
// 	BracketSequenceDiv2 *bra=new BracketSequenceDiv2();
// 	string s;
// 	cin>>s;
// 	error((*bra).count(s));
// }