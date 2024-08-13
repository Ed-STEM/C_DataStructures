#include <stdio.h>
#include <math.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>

const double G = 6.67430e-11; // Gravitational constant

int func(double t, const double y[], double f[], void *params) {
    (void)(t); // avoid unused parameter warning
    double masses[] = {((double *)params)[0], ((double *)params)[1]};

    // Unpack the input array
    double x1 = y[0], y1 = y[1], z1 = y[2], vx1 = y[3], vy1 = y[4], vz1 = y[5];
    double x2 = y[6], y2 = y[7], z2 = y[8], vx2 = y[9], vy2 = y[10], vz2 = y[11];

    // Calculate distances
    double dx = x2 - x1, dy = y2 - y1, dz = z2 - z1;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double r3 = r * r * r;

    // Gravitational forces
    double Fx = G * masses[0] * masses[1] * dx / r3;
    double Fy = G * masses[0] * masses[1] * dy / r3;
    double Fz = G * masses[0] * masses[1] * dz / r3;

    // Output array
    f[0] = vx1; f[1] = vy1; f[2] = vz1;
    f[3] = Fx / masses[0]; f[4] = Fy / masses[0]; f[5] = Fz / masses[0];
    f[6] = vx2; f[7] = vy2; f[8] = vz2;
    f[9] = -Fx / masses[1]; f[10] = -Fy / masses[1]; f[11] = -Fz / masses[1];

    return GSL_SUCCESS;
}

int main(void) {
    gsl_odeiv2_system sys = {func, NULL, 12, NULL};

    double masses[2] = {1.0, 1.0}; // Example masses
    sys.params = masses;

    gsl_odeiv2_driver *d = gsl_odeiv2_driver_alloc_y_new
