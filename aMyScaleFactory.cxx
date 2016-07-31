#include "aMyScaleFactory.h"

template<class T>
aMyScale<T>* aMyScaleFactory<T>::getScaler (const int scalerType) {
		
	assert(scalerType == A_MY_SCALE_NN || scalerType == A_MY_SCALE_MAX);
	
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
