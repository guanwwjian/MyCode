__kernel void multiply(			__global float* outputC,
						const int widthA, 
						const int heightA,
						const int widthB, 
						const int heightB, 
						__global float* inputA,
						__global float* inputB)
{
	int row = get_global_id(1);	// Get global position in Y direction 
	int col = get_global_id(0);	// Get global position in X direction

	float sum = 0.0f;

	//Calculat result of one element of Matrix C
	for( int i = 0; i< widthA; i++)
	{
		sum += inputA[row * widthA+i] * inputB[i * widthB + col];
	}

	outputC[row * widthB+col] = sum;
}
