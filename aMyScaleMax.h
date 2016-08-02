#ifndef A_MY_SCALE_MAX_H_
#define A_MY_SCALE_MAX_H_

#include "aMyScale.h"

template<class T>
class aMyScaleMax : public aMyScale<T> {
protected:
    
	virtual T decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) ;
    
public:

	~aMyScaleMax () ;
    
};

#endif
