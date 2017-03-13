#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

class Permatchd2 {
public:
	int fix(vector <string>);
};

const int N = 55;

vi g[N];
int n;
int vis[N];
int allEdges[N];
int component = 0;

void dfs(int x) {
	vis[x] = 1;
	for(int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		allEdges[component]++;
		if(vis[y]) continue;
		dfs(y);
	}
}

int Permatchd2::fix(vector <string> graph) {
	n = graph.size();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(graph[i][j] == 'Y') g[i].pb(j);
		}
	}
	
	int tot = 0;
	for(int i = 0; i < n; ++i) {
		if(vis[i] == 0) {
			allEdges[component] = 0;
			dfs(i);
			component++;
			tot += allEdges[component];
		}
	}
	tot /= 2;
	printf("-> %d\n", tot);
	
	if((tot + component) % 2 == 0) return component - 1;
	else return component;
	
}


double test0() {
	string t0[] = {"NYN",
 "YNN",
 "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"NYY",
 "YNN",
 "YNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"NYY",
 "YNY",
 "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"NYNNNN",
 "YNNNNN",
 "NNNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Permatchd2 * obj = new Permatchd2();
	clock_t start = clock();
	int my_answer = obj->fix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
