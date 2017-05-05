// Now thre equation 'dx/dt = x' is solving by Euler method.

#include <iostream>
#include <fstream>

using namespace std;

double f_next(double dx, double f_prev) {
  return (1 + dx) * f_prev;
}

int main() {
  double a, b;   // Segment [a, b] where we search solution.
  int n;         // Number of small segments of [a, b].
  double f_0;    // Start condition.

  cin >> a >> b >> n >> f_0;

  cout << "input data:\n\t[a, b] = [" << a << ", " << b << "]\n\tn = " << n << "\n\tf(0) = " << f_0 << endl; 
  double dx = (b - a) / n;
  double *f;
  f = new double[n];
  f[0] = f_0;

  cout << "calculating...\n";
  
  for (int i = 1; i < n; ++i) {
    f[i] = f_next(dx, f[i - 1]);
  }

  ofstream fout;
  fout.open("output.txt");
  for (int i = 0; i < n; ++i) {
    fout << i * dx << "\t" << f[i] << endl;
  }
  fout.clear();
  fout.close();

  delete[] f;
  return 0;
}
