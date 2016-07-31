#include <iostream>
#include "aMyScaleNN.h"

template<class T>
double aMyScaleNN<T>::getDistanceSquare (const double x1, 
	                                     const double y1, 
	                                     const double z1, 
	                                     const double x2, 
	                                     const double y2, 
	                                     const double z2) {
								  
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
	
	}

template<class T>
T aMyScaleNN<T>::decidePixelColor (aImage<T>& inputImage, const size_t x, const size_t y, const size_t z) {
		
	T nearestNeighborValue = 0;
	double nearestNeighborDistance = 1e50;
	
	/*
	 * Getting the real coordinates of the scaled point.
	 */
		 
	double pointX = this->m_ratioX * x;
	double pointY = this->m_ratioY * y;
	double pointZ = this->m_ratioZ * z; 
		
	/*
	 * Getting the top-upper-left most corner of the unit cube.
	 * I.e. the minimal (x, y, z) among its' corners.
	 */
		
	size_t cornerX = (size_t)(pointX);
	size_t cornerY = (size_t)(pointY);
	size_t cornerZ = (size_t)(pointZ);
			
	/*
	 * Scaning cube's nodes.
	 */
	 
	std::cout << x << " " << y << " " << cornerX << " " << cornerY << std::endl;
		
	for(size_t dx = 0; dx < 2; ++dx)
		for(size_t dy = 0; dy < 2; ++dy)
			for(size_t dz = 0; dz < 2; ++dz) {
				
				size_t nodeX = cornerX + dx;
				size_t nodeY = cornerY + dy;
				size_t nodeZ = cornerZ + dz;
				
				if (nodeX >= this->m_oldSizeX || nodeY >= this->m_oldSizeY || nodeZ >= this->m_oldSizeZ)
					continue;
						
				/*
				 * Getting the distance to the cube's node.
				 */
					
				double distance = getDistanceSquare(pointX, pointY, pointZ, nodeX, nodeY, nodeZ);
					
				if (distance < nearestNeighborDistance) {
					distance = nearestNeighborDistance;
					nearestNeighborValue = inputImage.elem(nodeX, nodeY, nodeZ);
				}
						
			}
				
		return nearestNeighborValue;
	}


template class aMyScaleNN<unsigned char>;
template class aMyScaleNN<char>;
