// ������ʵ������ҵ.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

#ifdef _APPLE_
#include <OpenCL/OpenCL.h>
#else
#include "CL/cl.h"
#endif

#define MATRIXMULLTIPLY

#define N  100
#define K  100
#define L  100
using namespace std;
inline void checkErr(cl_int err, const char *name)
{
	if (err != CL_SUCCESS)
	{
		std::cerr << "����: " << name << "(" << err << ")" << std::endl;
		exit(EXIT_FAILURE);
	}
}
cl_context CreateContext()
{
	cl_int errNum;
	cl_uint numPlatforms;
	cl_platform_id PlatformIds[2];
	cl_context context = NULL;
	errNum = clGetPlatformIDs(2, PlatformIds, &numPlatforms);
	if (errNum != CL_SUCCESS || numPlatforms <= 0)
	{
		std::cerr << "û�з���Platform��" << std::endl;
		return NULL;
	}
	cl_context_properties contextProperties[] = { CL_CONTEXT_PLATFORM, (cl_context_properties)PlatformIds[1], 0 };
	context = clCreateContextFromType(contextProperties, CL_DEVICE_TYPE_GPU, NULL, NULL, &errNum);
	if (errNum != CL_SUCCESS)
	{
		context = clCreateContextFromType(contextProperties, CL_DEVICE_TYPE_CPU, NULL, NULL, &errNum);
		std::cerr << "�޷�����GPU Context�����Դ���CPU Context" << std::endl;
		if (errNum != CL_SUCCESS)
		{
			std::cerr << "�޷�����Context��" << std::endl;
			return NULL;
		}
	}
	return context;
}
void usecpu(const float *a, const float *b, float *c ,cl_int aw, cl_int ah, cl_int bh)
{
	for (int i = 0; i < aw; i++)
		for (int j = 0; j < bh; j++)
		{
			c[i*bh + j] = 0;
			for (int k = 0; k < ah; k++)
			{
				c[i*bh + j] += a[i*ah + k] * b[k*bh + j];
			}
		}
}
int main(int argc, char * argv[])
{
	ofstream out("out.txt");
	cl_int errNum;
	cl_platform_id platformID[2];
	cl_context context = NULL;
	cl_device_id  device;
	errNum = clGetPlatformIDs(2, platformID, NULL);
	checkErr(errNum, "clGetPlatformIDS");
	out << "Platform ID: " << platformID[1] << std::endl;
	context = CreateContext();
	if (context == NULL)
	{
		std::cerr << "����Contextʧ��" << std::endl;
		return NULL;
	}
	errNum = clGetDeviceIDs(platformID[1], CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (errNum != CL_SUCCESS)
	{
		std::cerr << "���ܴ�GPU����Device�����Դ�CPU����Device" << std::endl;
		errNum = clGetDeviceIDs(platformID[1], CL_DEVICE_TYPE_CPU, 1, &device, NULL);
		out << "Device: " << device << std::endl;
		if (errNum != CL_SUCCESS)
		{
			checkErr(errNum, "clGetDeviceIDs(..CL_DEVICE_TYPE_ALL..)");
		}
	}
	cl_command_queue commandQueue = clCreateCommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &errNum);
	checkErr(errNum, "clCreateCommandQueue( )");

	cl_int Mat_A_width = N;
	cl_int Mat_A_height = K;
	cl_int Mat_B_width = K;
	cl_int Mat_B_height = L;

	float *MatA = (float*)malloc(sizeof(float)*Mat_A_width*Mat_A_height);

	if (MatA == NULL)
	{
		std::cerr << "�ڴ����ʧ�ܡ�" << std::endl;
	}
	float *MatB = (float*)malloc(sizeof(float)*Mat_B_width*Mat_B_height);
	float *MatC = (float*)malloc(sizeof(float)*Mat_A_width*Mat_B_height);
	out << "=====MatA: " << Mat_A_width << "X" << Mat_A_height;//<< std::endl;
	for (int i = 0; i< Mat_A_width*Mat_A_height; i++)
	{
		MatA[i] = std::rand()*0.25;
		//MatA[i] = 4.5;

		if ((i%Mat_A_height == 0) || (i == 0))
		{
			out << std::endl;
		}
		out << MatA[i] << "\t";
	}
	out << std::endl;
	cl_mem bufferA = clCreateBuffer(context,
		CL_MEM_READ_ONLY,//|CL_MEM_COPY_HOST_PTR,
		Mat_A_width*Mat_A_height*sizeof(float),
		NULL,
		&errNum);
	checkErr(errNum, "clCreateBuffer(...bufferA..)");
	errNum = clEnqueueWriteBuffer(commandQueue, bufferA, CL_TRUE, 0, Mat_A_width*Mat_A_height*sizeof(float), (void*)MatA, 0, NULL, NULL);
	out << "MatB: " << Mat_B_width << "X" << Mat_B_height << std::endl;
	for (int i = 0; i< Mat_B_width*Mat_B_height; i++)
	{
		MatB[i] = std::rand()*0.25;
		//MatB[i] = 2.0;
		if ((i%Mat_B_height == 0) || (i == 0))
		{
			out << std::endl;
		}
		out << MatA[i] << " ";
	}
	out << std::endl;
	cl_mem bufferB = clCreateBuffer(context,
		CL_MEM_READ_ONLY,//|CL_MEM_COPY_HOST_PTR,
		Mat_B_width*Mat_B_height*sizeof(float),
		NULL,
		&errNum);
	checkErr(errNum, "clCreateBuffer(...bufferB..)");
	errNum = clEnqueueWriteBuffer(commandQueue, bufferB, CL_TRUE, 0, Mat_B_width*Mat_B_height*sizeof(float), (void*)MatB, 0, NULL, NULL);
	cl_mem bufferC = clCreateBuffer(context,
		CL_MEM_READ_ONLY,//|CL_MEM_COPY_HOST_PTR,
		Mat_A_width*Mat_B_height*sizeof(float),
		NULL,
		&errNum);
	checkErr(errNum, "clCreateBuffer(...bufferC..)");
	cl_program program;
	const char* fileName = "mykernal.cl";
	std::ifstream kernelFile(fileName, std::ios::in);

	if (!kernelFile.is_open())
	{
		std::cerr << "��ȡ�ļ�ʧ�ܣ�" << fileName << std::endl;
		return NULL;
	}

	std::ostringstream oss;
	oss << kernelFile.rdbuf();

	std::string srcStdStr = oss.str();
	const char *srcStr = srcStdStr.c_str();
	program = clCreateProgramWithSource(context, 1, (const char**)&srcStr, NULL, NULL);
	if (program == NULL)
	{
		std::cerr << "����Programʧ�ܡ�" << std::endl;
		return NULL;
	}

	errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (errNum != CL_SUCCESS)
	{
		char buildLog[16384];
		clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, sizeof(buildLog), buildLog, NULL);

		std::cerr << "����kernal�����з������� " << std::endl;
		std::cerr << buildLog;
		clReleaseProgram(program);
		return NULL;
	}
	cl_kernel kernel = clCreateKernel(program, "multiply", NULL);
	if (kernel == NULL)
	{
		std::cerr << "����kernalʧ�ܡ�" << std::endl;
		return NULL;
	}
	clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&bufferC);
	clSetKernelArg(kernel, 1, sizeof(cl_int), (void*)&Mat_A_width);
	clSetKernelArg(kernel, 2, sizeof(cl_int), (void*)&Mat_A_height);
	clSetKernelArg(kernel, 3, sizeof(cl_int), (void*)&Mat_B_width);
	clSetKernelArg(kernel, 4, sizeof(cl_int), (void*)&Mat_B_height);
	clSetKernelArg(kernel, 5, sizeof(cl_mem), (void*)&bufferA);
	clSetKernelArg(kernel, 6, sizeof(cl_mem), (void*)&bufferB);
	size_t globalws[2] = { Mat_A_width, Mat_B_height };
	size_t localws[2] = { Mat_A_width, Mat_B_height };
	cl_event  ev;
	errNum = clEnqueueNDRangeKernel(commandQueue, kernel, 2, NULL, globalws, NULL, 0, NULL, &ev);
	if (errNum != CL_SUCCESS)
	{
		std::cerr << "ִ��kernalʧ�ܡ�" << std::endl;
		return NULL;
	}
	clFinish(commandQueue);
	errNum = clWaitForEvents(1, &ev);
	if (errNum != CL_SUCCESS) {
		perror("�ȴ�ִ�й����з�������\n");
		exit(1);
	}
	errNum = clEnqueueReadBuffer(commandQueue, bufferC, CL_TRUE, 0, Mat_B_height*Mat_A_width*sizeof(float), (void*)MatC, 0, NULL, NULL);
	cl_ulong startTime, endTime;
	clGetEventProfilingInfo(ev, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
	clGetEventProfilingInfo(ev, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
	cl_ulong time = endTime - startTime;
	out << std::endl;
	printf("ʹ��GPUִ��ʱ�䣺%8.6f ms\n", time*1e-6);
	clock_t s, t;
	s=clock();
	usecpu(MatA, MatB, MatC, Mat_A_width, Mat_A_height, Mat_B_height);
	t = clock();
	cout << "ʹ��CPUִ��ʱ�䣺" <<  t - s << "ms" << endl;
	out << "MatrixC:" << Mat_A_width << "X" << Mat_B_height << std::endl;
	for (int i = 0; i< Mat_A_width*Mat_B_height; i++)
	{
		if ((i != 0) && (i%Mat_B_height == 0))
		{
			out << std::endl;
		}

		out << MatC[i] << "\t";
	}
	clReleaseKernel(kernel);
	clReleaseProgram(program);
	clReleaseCommandQueue(commandQueue);
	clReleaseContext(context);

	delete[] MatA;
	delete[] MatB;
	delete[] MatC;
	out.close();
	getchar();
	return 0;
}
