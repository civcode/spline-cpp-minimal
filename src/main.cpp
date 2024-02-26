#include <cmath>
#include <vector>
#include <iostream>

#include <matplot/matplot.h>
#include "spline.h"

namespace mp = matplot;

int main() {

  // Create a set of data points
  std::vector<double> x_vals = {0, 0.5, 1, 2, 3, 4, 5};
  std::vector<double> y_vals = {0, 0.2, 0.8, 0.9, 0.1, -0.8, -1};

  // Create a spline object
  tk::spline s(x_vals, y_vals);

  // Interpolate the spline at a new point
  double vx = 2.5;
  double vy = s(vx);
  std::cout << "Interpolated value at vx = " << vx << " is " << vy << std::endl;

  // Plot the data and the spline
  std::vector<double> x = mp::linspace(0, 5, 100);
  std::vector<double> y = mp::transform(x, [&](auto x) {return s(x);});

  mp::plot(x_vals, y_vals, "o");
  mp::hold(true);
  mp::plot(x, y)->line_width(2).color("blue");
  
  // Plot the first derivative
  std::vector<double> y_prime = mp::transform(x, [&](auto x) {return s.deriv(1, x);});
  mp::plot(x, y_prime)->line_width(2).color("red");

  // Plot the second derivative
  std::vector<double> y_double_prime = mp::transform(x, [&](auto x) {return s.deriv(2, x);});
  mp::plot(x, y_double_prime)->line_width(2).color("green");

  // Plot the derivative of the arc length
  std::vector<double> s_prime = mp::transform(x, 
    [&](auto x) {return std::sqrt(1+(s.deriv(1, x)*s.deriv(1, x)));
  });
  mp::plot(x, s_prime)->line_width(2).color("black");

  // std::vector<double> y_prime_abs = mp::transform(x, [&](auto x) {return std::abs(s.deriv(1, x));});
  // mp::plot(x, y_prime_abs)->line_width(2).color("black");

  mp::xlabel("x");
  mp::ylabel("y");
  // mp::legend({"Data", "Spline", "First Derivative", "Second Derivative", "s'"});
  mp::legend({"Data", "Spline f(x)", "f'(x)", "f''(x)", "s'"});
  mp::grid(true);
  mp::show();


  return 0;
}

