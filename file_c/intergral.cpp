#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
double fun(double x, double y, double z) {
    return 1;  // f(x,y,z)
}

double triple_integral(int n) {
    double ans = 0;
    double highBound_x = 0;	// Can tren cua x
	double lowBound_x = -162.868; // Can duoi cua x 
	double dx = (highBound_x -lowBound_x)/n;
    for (int i = 0; i < n; i++) {
        double V = 0;
        double xi = lowBound_x + i*dx;
        double highBound_y = xi+162.868;  // Can tren cua y : y = x+169.23;
        double lowBound_y = 0;		// Can duoi cua y : y=0;
        double dy = (highBound_y - lowBound_y) / n;
        
        for (int j = 0; j < n; j++) {
            double yi = lowBound_y + j*dy;
            double S = 0;
            double highBound_z = 139/162.868*xi-139/162.868*yi+139;  // Can tren cua z : z = 139/196.23*x-139/196.23*y+139;
            double lowBound_z = 0;				// Can duoi cua z : z = 0;
            double dz = (highBound_z - lowBound_z) / n;
            for (int k = 0; k < n; k++) {
                double zi = lowBound_z + k* dz;
                S += fun(xi, yi, zi) * dz;
            }
            V += S * dy;
        }
        
        ans += V * dx;
    }
    return ans;
}
int main(){
	int n = 1000;
	cout<<fixed<<setprecision(4) <<triple_integral(n);
	}
