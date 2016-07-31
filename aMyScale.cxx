#include <assert.h>
#include "aMyScale.h"

/*
 * Since the implementation of the nearest neighbor scaling and
 * the maximal intensity scaling are very similar and differ only
 * in the method of picking the pixel's color, it is reasonable
 * to leave the main code in the base class and only make the
 * color decision function abstract.
 */

template<class T>
void aMyScale<T>::doScale (aImage<T>& inputImage, aImage<T>& outputImage) {
		
	/*
	 * Get the diminsions of the old image
	 */
		 
	m_oldSizeX = inputImage.getSizeX();
	m_oldSizeY = inputImage.getSizeY();
	m_oldSizeZ = inputImage.getSizeZ();
		
	/*
	 * Check, whether the image can be scaled.
	 */
		 
	assert(m_oldSizeX > 0 && m_oldSizeY > 0 && m_oldSizeZ > 0);
		
	/*
	 * Get the dimensions of the new image
	 */
		 
	m_newSizeX = outputImage.getSizeX();
	m_newSizeY = outputImage.getSizeY();
	m_newSizeZ = outputImage.getSizeZ();
		
	/*
	 * Get the scaling ratios by all the axes.
	 */
		
	m_ratioX = m_oldSizeX * 1.0 / m_newSizeX;
	m_ratioY = m_oldSizeY * 1.0 / m_newSizeY;
	m_ratioZ = m_oldSizeZ * 1.0 / m_newSizeZ;
		
	/*
	 * Doing the scaling.
	 */
		
	for(size_t x = 0; x < m_newSizeX; ++x)
		for(size_t y = 0; y < m_newSizeY; ++y)
			for(size_t z = 0; z < m_newSizeZ; ++z) {
		
				/*
				 * Put the decided color to the corresponding point of the result image.
				 */
		
				outputImage.elem(x, y, z) = decidePixelColor(inputImage, x, y, z);
			}	

}

template class aMyScale<unsigned char>;
template class aMyScale<char>;
