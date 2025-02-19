#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2010, M = 1e6 + 10;

int n, m;
int h[N], to[M], w[M], ne[M], idx = 0;
int q[N], du[N];
int dis[N];
bool book[N];
int ans = 0;

void add(int a, int b, int c){
	to[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
	du[b]++;
}

void toposort(){
	int hh = 0, tt = -1;
	for(int i = 1; i <= n + m; i++)
		if(!du[i]) q[++tt] = i;

	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t]; ~i; i = ne[i]){
			int j = to[i];
			if(--du[j] == 0) q[++tt] = j;
		}
	}
}

int main() {

	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; i++){
		int cnt, st = n, ed = 1;
		cin >> cnt;
      	memset(book, 0, sizeof book);
		while(cnt--){
			int x;
			cin >> x;
			st = min(st, x);
			ed = max(ed, x);
			book[x] = true;
		}

		for(int j = st; j <= ed; j++)
			if(book[j]) add(n + i, j, 1);
			else add(j, n + i, 0);
	}

	toposort();

	for(int i = 1; i <= n; i++) dis[i] = 1;

	for(int i = 0; i < n + m; i++){
		int v = q[i];
		for(int j = h[v]; ~j; j = ne[j])
			dis[to[j]] = max(dis[to[j]], dis[v] + w[j]);
	}

	for(int i = 1; i <= n; i++) ans = max(ans, dis[i]);

	cout << ans << endl;
	
	return 0;
}


