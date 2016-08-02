#ifndef A_MY_SCALE_H_
#define A_MY_SCALE_H_

#include <aImage.h>

/*
 * The base class for both: maximal intensity and nearest neighbor scalings.
 * The factory class will give the pointer to the instance of aMyScale class.
 */

template<class T>
class aMyScale {
protected:

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
	
	/*
	 * A function that will decide the color of the corresponding pixel.
	 * The implemenation depends on the method of the scaling.
	 */

	virtual T decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) = 0;

public:

	/*
	 * The main function for the scaling.
	 */

	void make (aImage<T>& inputImage, aImage<T>& outputImage) ;
		
};

#endif
