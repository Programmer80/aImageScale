#ifndef A_MY_SCALE_NN_H_
#define A_MY_SCALE_NN_H_

#include "aMyScale.h"

template<class T>
class aMyScaleNN : public aMyScale<T> {
private:

	/*
	 * Distance function for finding the nearest neighbor.
	 */

	double getDistanceSquare (const double x1, 
	                          const double y1, 
	                          const double z1, 
	                          const double x2, 
	                          const double y2, 
	                          const double z2) ;

public:
    
	T decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) ;
    
};

#endif
