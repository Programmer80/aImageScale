#include "aMyScaleMax.h"

/*
 * The routine for finding the color of the pixel of the scaled image via
 * taking the color of the maximal intensity from the neighbors.
 */

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
				
				/*
				 * Getting the coordinates of the node of the unit cube.
				 */				
				
				size_t nodeX = cornerX + dx;
				size_t nodeY = cornerY + dy;
				size_t nodeZ = cornerZ + dz;

				/*
				 * If the point denoted by the node doesn't belong to the image, it won't be
				 * counted. This way, we can treat 2D and 3D images equally.
				 */
				
				if (nodeX >= this->m_oldSizeX || nodeY >= this->m_oldSizeY || nodeZ >= this->m_oldSizeZ)
					continue;
				
				/*
				 * Checking if the node has the maximal intensity.
				 */				
				
				T value = inputImage.elem(nodeX, nodeY, nodeZ);
				if (value > maximalIntensity)
					maximalIntensity = value;
					
			}
			
	return maximalIntensity;
	
}

/*
 * We should have a virtual destructor in polymorph classes.
 * Although here it will be empty, since we have nothing to delete.
 */

template<class T>
aMyScaleMax<T>::~aMyScaleMax () {

}

template class aMyScaleMax<unsigned char>;
template class aMyScaleMax<char>;
template class aMyScaleMax<unsigned short>;
template class aMyScaleMax<short>;
template class aMyScaleMax<unsigned int>;
template class aMyScaleMax<int>;
