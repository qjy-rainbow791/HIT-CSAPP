#pragma once
 
#include <immintrin.h>
#include <stdio.h>
 
float MathMax(const float *input, int size);
float SSEMax(const float *input, int size);
float AVXMax(const float *input, int size);
