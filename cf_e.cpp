#include<stdio.h>
#include<math.h>
#define M_PI acos(-1.0)
const double eps = 1e-6;
int m;
double r;
double rs[1009];
double xs[1009];
double ys[1009];
double cutt(double origin, int ind) {
  double d = sqrt(xs[ind]*xs[ind] + ys[ind]*ys[ind]);
  //printf("d: %.2f\n", d);
  //printf("r: %.2f\n", r);
  //printf("r0: %.2f\n", rs[ind]);
  if (d + rs[ind] < r - eps || d > r + rs[ind] - eps) {
    //printf("bad ind %d\n", ind);
    return origin;
  }
  if (fabs(r - d - rs[ind]) < eps) {
    return origin += 2 * M_PI * rs[ind];
  }
  double r0 = rs[ind];
  double firstcos = (r*r+d*d-r0*r0)/(2*r*d);
  double secondcos = (r0*r0+d*d-r*r)/(2*r0*d);
  double firstdb = 2*firstcos*firstcos - 1;
  double seconddb = 2*secondcos*secondcos - 1;
  
  double firstang = acos(firstdb);
  double secondang = acos(seconddb);
  if (r*r + d*d < r0 * r0) {
    firstang = 2 * M_PI - firstang;
  }
  if (r0*r0 + d*d < r*r) {
    secondang = 2 * M_PI - secondang;
  }
  //printf("cos: %.2f, %.2f db: %.2f, %.2f ang: %.2f %.2f\n", firstcos, secondcos, firstdb, seconddb, firstang, secondang);
  origin -= r*firstang;
  origin += r0*secondang;
  //printf("now: %lf", origin);

  return origin;
}

int main () {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    scanf("%d%lf", &m,&r);
    //printf("r is %.6f\n", r);
    double origin = 2*M_PI*r;
    for (int j = 0; j < m; j++) {
      scanf("%lf%lf%lf", &xs[j], &ys[j], &rs[j]);
    }
    for (int j = 0; j < m; j++) {
      origin = cutt(origin, j);
    }
    printf("%.6lf\n", origin);
  }
  return 0;

}
