// -O2 命令行：/arch:AVX 
#include "math_function.h"
#include <random>
#include <time.h>

//单线程、SSE、AVX运行效率对比——最大值 / 最小值运算

using std::default_random_engine;
using std::uniform_real_distribution;
 
int main(int argc, char* argv[])
{
	int size = 58;
	float *input = (float *)malloc(sizeof(float) * size);
 
	default_random_engine e;
	uniform_real_distribution<float> u(0, 3); //随机数分布对象 
	for (int i = 0; i < size; i++)
	{
		input[i] = u(e);
		printf("%f ", input[i]);
		if ((i + 1) % 8 == 0)
			printf("\n");
	}
	printf("\n");
 
	int cntLoop = 100000000;
	float org;
	clock_t start_t = clock(); 
	for (int i = 0; i < cntLoop; i++)
		org = MathMax(input, size);
	clock_t end_t = clock();
	printf("org = %f\t", org);
	printf("cost time: %d(ms)\n", end_t - start_t);
 
	float sse;
	start_t = clock();
	for (int i = 0; i < cntLoop; i++)
		sse = SSEMax(input, size);
	end_t = clock();
	printf("sse = %f\t", sse);
	printf("cost time: %d(ms)\n", end_t - start_t);
 
	float avx;
	start_t = clock();
	for (int i = 0; i < cntLoop; i++)
		avx  = AVXMax(input, size);
	end_t = clock();
	printf("avx = %f\t", avx);
	printf("cost time: %d(ms)\n", end_t - start_t);

	free(input);
	getchar();

	return 0;
}