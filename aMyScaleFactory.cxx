#include "aMyScaleFactory.h"

/*
 * The function for getting the class of one of two types:
 *  - either NN-scaling class
 *  - either max-intensity scaling class
 */

template<class T>
aMyScale<T>* aMyScaleFactory<T>::getScaler (const int scalerType) {
	
	/*
	 * Checking the the passed parameter indeed correspons to the type
	 * of some of the classes.
	 */
		
	assert(scalerType == A_MY_SCALE_NN || scalerType == A_MY_SCALE_MAX);
	
	/*
	 * Getting the object of the class of the requested type.
	 */
	
	switch (scalerType) {
		case A_MY_SCALE_MAX:
			return new aMyScaleMax<T>;
		case A_MY_SCALE_NN:
			return new aMyScaleNN<T>;
		default:
			return nullptr;
	}
			
}

template class aMyScaleFactory<unsigned char>;
template class aMyScaleFactory<char>;
template class aMyScaleFactory<unsigned short>;
template class aMyScaleFactory<short>;
template class aMyScaleFactory<unsigned int>;
template class aMyScaleFactory<int>;
