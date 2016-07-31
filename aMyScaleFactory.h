#ifndef A_MY_SCALE_FACTORY_H_
#define A_MY_SCALE_FACTORY_H_

#include <assert.h>
#include "aMyScaleMax.h"
#include "aMyScaleNN.h"

const int A_MY_SCALE_MAX = 0;
const int A_MY_SCALE_NN = 1;

/*
 * The factory class for getting the instances of base class aMyScale, 
 * which can either be aMyScaleNN classes or aMyScaleMax classes.
 */
 
template<class T>
class aMyScaleFactory {
public:	
	
	static aMyScale<T>* getScaler (const int scalerType) ;
	
};

#endif
