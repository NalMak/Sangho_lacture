// CharPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <time.h>
#include <vector>
#include <chrono>
#include <string>

#include <process.h>
#include <Windows.h>

using namespace std;

UINT WINAPI threadTest(void* _argu);
SRWLOCK lock;


int __cdecl main()
{
	int testNum = 0;
	InitializeSRWLock(&lock);
	for (int i = 0; i < 20; ++i)
	{
		HANDLE hThread1 = (HANDLE)_beginthreadex(nullptr, 2, threadTest, &testNum, 0, NULL);
	}
	
	auto startTime = chrono::high_resolution_clock().now();
	while (true)
	{
		if (testNum == 100000)
		{
			break;
		}
		
	}
	auto endTime = chrono::high_resolution_clock().now();

	cout << (endTime - startTime).count() << endl;
	int c = 0;

	startTime = chrono::high_resolution_clock().now();
	for (int i = 0; i < 100000; ++i)
	{
		for (int j = 0; j < 10000; ++j)
		{
			float b = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float c = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float d = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float e = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float f = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float g = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
		}
		//InterlockedIncrement((unsigned long long*)a);
		c++;
	}
	endTime = chrono::high_resolution_clock().now();

	cout << (endTime - startTime).count() << endl;
}

// 1번 쓰레드 a 100000 -> 4문제 빈칸채우기 매개변수채우고 함수위치결정해주고 lock unlock
// 2번 center right left  
// 3번 dx ->이미지 애니메이션 회전 이동 카메라 이동
// 4번 shader -> 모자이크 만들기 

UINT __stdcall threadTest(void * _argu)
{
	int* a = (int*)(_argu);
	
	for (int i = 0; i < 10000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			float b = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float c = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float d = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float e = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float f = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
			float g = 3 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9;
		}
		//InterlockedIncrement((unsigned long long*)a);

		AcquireSRWLockExclusive(&lock);
		(*a)++;
		ReleaseSRWLockExclusive(&lock);
	}

	return 0;
}
