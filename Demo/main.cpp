#include "aMyScaleFactory.h"
#include <aImage.h>
#include <aInputOutput.h>

/*
 * Routine for displaying error message with a short reference.
 * Called when the input format isn't valid.
 */

void displayErrorMessage (const char* executableName) {
	std::cout << "Usage: " << executableName << " [input filename] [output filename] [depth] [old size x] [old size y] [old size z] ";
	std::cout << "[new size x] [new size y] [new size z] [method]" << std::endl;
	std::cout << "For depth, unsigned 8-bit and unsigned 16-bit images are supported in this demo." << std::endl;
	std::cout << "So it can either be 8 or 16." << std::endl;
	std::cout << "[method] can either be 0 for Nearest Neighbor or 1 for Maximal Intensity" << std::endl;
	exit(0);
}

/*
 * Separate convert routine for unsigned 8-bit images.
 */

void convert8bit (char* inputFileName, 
                  char* outputFileName,
                  const size_t oldSizeX,
                  const size_t oldSizeY,
                  const size_t oldSizeZ, 
                  const size_t newSizeX, 
                  const size_t newSizeY, 
                  const size_t newSizeZ, 
                  const int method) {
					  
	aInputOutput<unsigned char> inputOutput;
	aImage<unsigned char> inputImage;
	aImage<unsigned char> outputImage;
	
	/*
	 * Giving the sought sizes for the input and output images.
	 */	
	
	inputImage.resize(oldSizeX, oldSizeY, oldSizeZ);
	outputImage.resize(newSizeX, newSizeY, newSizeZ);

	/*
	 * Reading input image.
	 */ 
	
	inputOutput.readRaw(inputFileName, inputImage);

	/*
	 * Getting a resizer accoring to the format.
	 */

	aMyScale<unsigned char>* resizer;
	if (method == 0)
		resizer = aMyScaleFactory<unsigned char>::getScaler(A_MY_SCALE_NN);
	else if (method == 1)
		resizer = aMyScaleFactory<unsigned char>::getScaler(A_MY_SCALE_MAX);

	/*
	 * Scaling and output.
	 */

	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw(outputFileName, outputImage);
	
	/*
	 * Freeing the memory from the resizer.
	 */
	
	delete resizer;
}

/*
 * Separate convert routine for unsigned 16-bit images.
 */

void convert16bit (char* inputFileName, 
                   char* outputFileName,
                   const size_t oldSizeX,
                   const size_t oldSizeY,
                   const size_t oldSizeZ, 
                   const size_t newSizeX, 
                   const size_t newSizeY, 
                   const size_t newSizeZ, 
                   const int method) {
	
	aInputOutput<unsigned short> inputOutput;
	aImage<unsigned short> inputImage;
	aImage<unsigned short> outputImage;
	
	/*
	 * Giving the sought sizes for the input and output images.
	 */
	
	inputImage.resize(oldSizeX, oldSizeY, oldSizeZ);
	outputImage.resize(newSizeX, newSizeY, newSizeZ);
	
	/*
	 * Reading input image.
	 */ 
	
	inputOutput.readRaw(inputFileName, inputImage);

	/*
	 * Getting a resizer accoring to the format.
	 */

	aMyScale<unsigned short>* resizer;
	if (method == 0)
		resizer = aMyScaleFactory<unsigned short>::getScaler(A_MY_SCALE_NN);
	else if (method == 1)
		resizer = aMyScaleFactory<unsigned short>::getScaler(A_MY_SCALE_MAX);

	/*
	 * Scaling and output.
	 */

	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw(outputFileName, outputImage);
	
	/*
	 * Freeing the memory from the resizer.
	 */
	
	delete resizer;
}

int main (int argc, char ** argv) {	
	
	/*
	 * Checking the command line format.
	 */
	
	if (argc != 11) {
		
		displayErrorMessage(argv[0]);
		
	} else {
		
		char* inputFileName = argv[1];
		char* outputFileName = argv[2];
		
		int depth = atoi(argv[3]);		
		if (depth != 8 && depth != 16)
			displayErrorMessage(argv[0]);
			
		size_t oldSizeX = atoi(argv[4]);
		size_t oldSizeY = atoi(argv[5]);
		size_t oldSizeZ = atoi(argv[6]);

		size_t newSizeX = atoi(argv[7]);
		size_t newSizeY = atoi(argv[8]);
		size_t newSizeZ = atoi(argv[9]);
		
		int method = atoi(argv[10]);
		if (method != 0 && method != 1)
			displayErrorMessage(argv[0]);
		
		if (depth == 8)
			convert8bit(inputFileName, outputFileName, oldSizeX, oldSizeY, oldSizeZ, newSizeX, newSizeY, newSizeZ, method);
		else
			convert16bit(inputFileName, outputFileName, oldSizeX, oldSizeY, oldSizeZ, newSizeX, newSizeY, newSizeZ, method);
	}		
    return 0;
}
