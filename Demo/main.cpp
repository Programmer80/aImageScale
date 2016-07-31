#include "aMyScaleFactory.h"
#include <aImage.h>
#include <aInputOutput.h>

int main () {
	aInputOutput<unsigned char> inputOutput;
	aImage<unsigned char> inputImage;
	aImage<unsigned char> outputImage;
	
	inputImage.resize(400, 600, 1);
	inputOutput.readRaw("/Mannheim/atk/atk/bin/test.raw", inputImage);

	aMyScale<unsigned char>* resizer = aMyScaleFactory<unsigned char>::getScaler(A_MY_SCALE_NN);
	
/*	outputImage.resize(800, 1200, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_2_times_larger_nn.raw", outputImage);*/
	
	outputImage.resize(200, 300, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_2_times_smaller_nn.raw", outputImage);
	
/*	outputImage.resize(400, 800, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_wider_nn.raw", outputImage);
	
	outputImage.resize(800, 600, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_taller_nn.raw", outputImage);
	
	resizer = aMyScaleFactory<unsigned char>::getScaler(A_MY_SCALE_MAX);
	
	outputImage.resize(800, 1200, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_2_times_larger_max.raw", outputImage);
	
	outputImage.resize(200, 300, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_2_times_smaller_max.raw", outputImage);
	
	outputImage.resize(400, 800, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_wider_max.raw", outputImage);
	
	outputImage.resize(800, 600, 1);
	resizer->doScale(inputImage, outputImage);
	inputOutput.writeRaw("/Mannheim/atk/atk/bin/test_taller_max.raw", outputImage); */


	
    return 0;
}
