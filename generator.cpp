#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int lef[6] = {4, 0, 2, 3, 5, 1}, up[6] = {2, 1, 5, 0, 4, 3};

void rot(int* t, int* p) {
  int pose[6];
  memcpy(pose, p, sizeof(int) * 6);
  _for(i, 0, 6) {
    p[i] = t[pose[i]];
  }
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
  int pose[6] = {0, 1, 2, 3, 4, 5};
  _for(i, 0, 6) {
    int p[6];
    memcpy(p, pose, sizeof(int) * 6);
    if (i == 0) {rot(up, p); }
    if (i == 1) {rot(lef, p); rot(up, p); }
    if (i == 3) {rot(up, p); rot(up, p); }
    if (i == 4) {rot(lef, p); rot(lef, p); rot(lef, p); rot(up, p); }
    if (i == 5) {rot(up, p); rot(up, p); rot(up, p); }
    _for(j, 0, 4) {
      rot(lef, p);
      for (int k = 0; k < 6; ++k) printf("%d, ", p[k]);
      cout << endl;
    }
  }
	return 0;
}