#include "aMyScaleMax.h"

template<class T>
T aMyScaleMax<T>::decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) {
	T maximalIntensity = 0;
	
	/*
	 * Getting the top-upper-left most corner of the unit cube.
	 * I.e. the minimal (x, y, z) among its' corners.
	 */
	
	size_t cornerX = (size_t)(this->m_ratioX * x);
	size_t cornerY = (size_t)(this->m_ratioY * y);
	size_t cornerZ = (size_t)(this->m_ratioZ * z);
	
	/*
	 * Scaning cube's nodes.
	 */
	
	for(size_t dx = 0; dx < 2; ++dx)
		for(size_t dy = 0; dy < 2; ++dy)
			for(size_t dz = 0; dz < 2; ++dz) {
				
				size_t nodeX = cornerX + dx;
				size_t nodeY = cornerY + dy;
				size_t nodeZ = cornerZ + dz;
				
				if (nodeX >= this->m_oldSizeX || nodeY >= this->m_oldSizeY || nodeZ >= this->m_oldSizeZ)
					continue;
				
				T value = inputImage.elem(nodeX, nodeY, nodeZ);
				if (value > maximalIntensity)
					maximalIntensity = value;
					
			}
			
	return maximalIntensity;
	
}

template class aMyScaleMax<unsigned char>;
template class aMyScaleMax<char>;
