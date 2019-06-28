#include<bits/stdc++.h>
using namespace std;

int main() {
  char tmp[4][20] = {"asfa", "sdafd", "weqt", "oiup"};
  sort(tmp, tmp + 4, [](char* a, char* b) -> bool { return strcmp(a, b) < 0; });
  for (int i = 0; i < 4; ++i) cout << tmp[i] << endl;
  return 0;
}