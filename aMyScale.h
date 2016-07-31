#ifndef A_MY_SCALE_H_
#define A_MY_SCALE_H_

#include <aImage.h>

/*
 * The base class for both: maximal intensity and nearest neighbor scalings.
 * The factory class will give the pointer to the instance of aMyScale class.
 */

template<class T>
class aMyScale {
public:

	/* 
	 * The dimensions of the old image.
	 */

	size_t m_oldSizeX;
	size_t m_oldSizeY;
	size_t m_oldSizeZ;
	
	/*
	 * The dimesions of the new image.
	 */
	
	size_t m_newSizeX;
	size_t m_newSizeY;
	size_t m_newSizeZ;
	
	/*
	 * The ratios of the scaling.
	 * Basically, oldSize divided by newSize.
	 */
	
	double m_ratioX;
	double m_ratioY;
	double m_ratioZ;

public:

	void doScale (aImage<T>& inputImage, aImage<T>& outputImage) ;
		
	virtual T decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) = 0;

};

#endif
