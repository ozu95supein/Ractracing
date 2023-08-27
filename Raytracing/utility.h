#ifndef UTILITY
#define UTILITY

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double pi = 3.1415926535897932385;

//Ulity functions. Made inline so that it replaces the function call with the code 
// below at compile time
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}
inline double random_double() {
    //returns a random real in [0,1)
    return rand() / (RAND_MAX + 1.0);
}
inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}

// common headers
#include "ray.h"
#include "vec3.h"
#include "Interval.h"
#include "color.h"
#endif // !UTILITY
