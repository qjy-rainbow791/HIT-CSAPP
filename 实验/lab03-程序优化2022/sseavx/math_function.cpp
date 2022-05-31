#include "math_function.h"
 
float MathMax(const float *input, int size)
{
	float maxVal = input[0];
	for (int i = 1; i < size; i++)
	{
		maxVal = maxVal > input[i] ? maxVal : input[i];
	}
 
	return maxVal;
}
 
float SSEMax(const float *input, int size)
{
	if (input == nullptr)
	{
		printf("input data is null\n");
		return -1;
	}
	int nBlockWidth = 4;
	int cntBlock = size / nBlockWidth;
	int cntRem = size % nBlockWidth;
 
	__declspec(align(16))	float output[4];
	__m128 loadData;
	const float *p = input;
 
	__m128 maxVal = _mm_load_ps(p);
	p += nBlockWidth;
 
	for (int i = 1; i < cntBlock; i++)
	{
		loadData = _mm_load_ps(p);
		maxVal = _mm_max_ps(maxVal, loadData);
 
		p += nBlockWidth;
	}
	_mm_store_ps(output, maxVal);
 
	float maxVal_ = output[0];
	for (int i = 1; i < 4; i++)
	{
		maxVal_ = maxVal_ > output[i] ? maxVal_ : output[i];
	}
	for (int i = 0; i < cntRem; i++)
	{
		maxVal_ = maxVal_ > p[i] ? maxVal_ : p[i];
	}
 
	return maxVal_;
}
 

 
float AVXMax(const float *input, int size)
{
	if (input == nullptr)
	{
		printf("input data is null\n");
		return -1;
	}
	int nBlockWidth = 8;
	int cntBlock = size / nBlockWidth;
	int cntRem = size % nBlockWidth;
 
	__declspec(align(32))	float output[8];
	__m256 loadData;
	const float *p = input;
 
	__m256 maxVal = _mm256_load_ps(p);
	p += nBlockWidth;
 
	for (int i = 1; i < cntBlock; i++)
	{
		loadData = _mm256_load_ps(p);
		maxVal = _mm256_max_ps(maxVal, loadData);
 
		p += nBlockWidth;
	}
	_mm256_store_ps(output, maxVal);
 
	float maxVal_ = output[0];
	for (int i = 1; i < 8; i++)
	{
		maxVal_ = maxVal_ > output[i] ? maxVal_ : output[i];
	}
	for (int i = 0; i < cntRem; i++)
	{
		maxVal_ = maxVal_ > p[i] ? maxVal_ : p[i];
	}
	
	return maxVal_;
}
