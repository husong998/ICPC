#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#define filla 1
#define fillb 2
#define dropa 3
#define dropb 4
#define pourab 5
#define pourba 6

using namespace std;

pair<int, int> fa[110][110];
int vis[110][110], d[110][110], op[110][110];
int a, b, C;

void printpath(int r, int c) {
	if(r == 0 && c == 0) return;
	int far = fa[r][c].first, fac = fa[r][c].second;
	printpath(far, fac);
	//cout << r << ',' << c << ' ' << 
		//far << ',' << fac << endl;
	if(far + fac == r + c) {
		if(far < r) cout << "POUR(2,1)\n";
		else cout << "POUR(1,2)\n";	
	} else if(r == a && far != a) cout << "FILL(1)\n";
  else if(c == b && fac != b) cout << "FILL(2)\n";
  else if(r == 0 && far) cout << "DROP(1)\n";
	else cout << "DROP(2)\n";
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
	cin >> a >> b >> C;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	vis[0][0] = 1;
	int ok = 0;
	while(!q.empty()) {
		int cura = q.front().first, curb = q.front().second;
		q.pop();
		if(cura == C || curb == C) { 
			cout << d[cura][curb] << endl;
			printpath(cura, curb); 
			ok = 1; 
			break; 
		}
		if(!vis[a][curb]) {
			fa[a][curb] = make_pair(cura, curb);
			d[a][curb] = d[cura][curb] + 1;
			op[a][curb] = filla;
			q.push(make_pair(a, curb));
			vis[a][curb] = 1;
		}
		if(!vis[cura][b]) {
			fa[cura][b] = make_pair(cura, curb);
			d[cura][b] = d[cura][curb] + 1;
			op[cura][b] = fillb;
			q.push(make_pair(cura, b));
			vis[cura][b] = 1;
		}
		int diff = min(cura, b - curb);
		if(!vis[cura - diff][curb + diff]) {
			fa[cura - diff][curb + diff] = make_pair(cura, curb);
			d[cura - diff][curb + diff] = d[cura][curb] + 1;
			op[cura - diff][curb + diff] = pourab;
			q.push(make_pair(cura - diff, curb + diff));
			vis[cura - diff][curb + diff] = 1;
		}
		diff = min(curb, a - cura);
		if(!vis[cura + diff][curb - diff]) {
			fa[cura + diff][curb - diff] = make_pair(cura, curb);
			d[cura + diff][curb - diff] = d[cura][curb] + 1;
			op[cura + diff][curb - diff] = pourba;
			q.push(make_pair(cura + diff, curb - diff));
			vis[cura + diff][curb - diff] = 1;
		}
		if(!vis[0][curb]) {
			fa[0][curb] = make_pair(cura, curb);
			d[0][curb] = d[cura][curb] + 1;
			op[0][curb] = dropa;
			q.push(make_pair(0, curb));
			vis[0][curb] = 1;
		}
		if(!vis[cura][0]) {
			fa[cura][0] = make_pair(cura, curb);
			d[cura][0] = d[cura][curb] + 1;
			op[cura][0] = dropb;
			q.push(make_pair(cura, 0));
			vis[cura][0] = 1;
		}
	}
	if(!ok) cout << "impossible\n";
  return 0;
}
