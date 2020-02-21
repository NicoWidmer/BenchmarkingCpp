#pragma once
#include <cstdlib>
#include <immintrin.h>
#include "Object.h"
#include <vector>

class Workloads
{

public:
	volatile bool running = true;

	Workloads()
	{
		for (int i = 0; i < ArraySize; i++)
		{
			intSourceArray[i] = (rand() % INT_MAX) - 1;
			if (rand() % 2)
				intSourceArray[i] = intSourceArray[i] * (-1);

			floatSourceArray[i] = rand();
			if (rand() % 2)
				floatSourceArray[i] = floatSourceArray[i] * (-1);

			shortSourceArray[i] = (short)(rand() % SHRT_MAX) - 1;
			if (rand() % 2)
				shortSourceArray[i] = shortSourceArray[i] * (-1);
		}

		for (int i = 0; i < ArraySizeVector; i++)
		{
			float float0 = rand();
			if (rand() % 2)
				float0 = float0 * (-1);
			float float1 = rand();
			if (rand() % 2)
				float1 = float1 * (-1);
			float float2 = rand();
			if (rand() % 2)
				float2 = float2 * (-1);
			float float3 = rand();
			if (rand() % 2)
				float3 = float3 * (-1);
			float float4 = rand();
			if (rand() % 2)
				float4 = float4 * (-1);
			float float5 = rand();
			if (rand() % 2)
				float5 = float5 * (-1);
			float float6 = rand();
			if (rand() % 2)
				float6 = float6 * (-1);
			float float7 = rand();
			if (rand() % 2)
				float7 = float7 * (-1);
			vectorSourceArray[i] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		}
	}

	void StartIntegerAdd()
    {
        loopCount = 0;

        while (running)
        {
            IntegerAdd();
            loopCount++;
        }
    };

    void StartIntegerMultiply()
    {
        loopCount = 0;

        while (running)
        {
            IntegerMultiply();
            loopCount++;
        }
    }

    void StartIntegerDivide()
    {
        loopCount = 0;

        while (running)
        {
            IntegerDivide();
            loopCount++;
        }
    }

    void StartBranchyIntegerAdd()
    {
        loopCount = 0;

        while (running)
        {
            BranchyIntegerAdd();
            loopCount++;
        }
    }

    void StartFloatAdd()
    {
        loopCount = 0;

        while (running)
        {
            FloatAdd();
            loopCount++;
        }
    }

    void StartFloatMultiply()
    {
        loopCount = 0;

        while (running)
        {
            FloatMultiply();
            loopCount++;
        }
    }

    void StartFloatDivide()
    {
        loopCount = 0;

        while (running)
        {
            FloatDivide();
            loopCount++;
        }
    }

    void StartVectorMultiply()
    {
        loopCount = 0;

        while (running)
        {
            VectorMultiply();
            loopCount++;
        }
    }

	void StartShortAdd()
    {
        loopCount = 0;
		
        while (running)
        {
            ShortAdd();
            loopCount++;
        }
    }

	void StartBranchyShortAdd()
    {
        loopCount = 0;

        while (running)
        {
            BranchyShortAdd();
            loopCount++;
        }
    }

	void StartCreatingObjectsPointers()
    {
        loopCount = 0;
		
        while (running)
        {
            CreateObjectPointer();
            loopCount++;
        }
    }
	
	void StartCreatingObjects()
    {
        loopCount = 0;

        while (running)
        {
            CreateObject();
            loopCount++;
        }
    }

	void StartAccessingObjectsPointers()
    {
        loopCount = 0;
		
        while (running)
        {
            AccessPointerObject();
            loopCount++;
        }
    }
	
	void StartAccessingObjects()
    {
        loopCount = 0;

        while (running)
        {
            AccessObject();
            loopCount++;
        }
    }

    long long GetExecutedOperations()
    {
        return loopCount * ArraySize;
    }


private:
	static const int ArraySize = 10000;
    static const int ArraySizeVector = ArraySize / 8;
    int intSourceArray [ArraySize];
    int intResultArray [ArraySize];
    float floatSourceArray [ArraySize];
    float floatResultArray [ArraySize];
	short shortSourceArray [ArraySize];
    short shortResultArray [ArraySize];
	std::vector<Object*> pointerObjectsVector;
	std::vector<Object> objectsVector;
    __m256 vectorSourceArray [ArraySizeVector];
    __m256 vectorResultArray [ArraySizeVector];
	__m256 vectorMultiplier = _mm256_set1_ps(2.0f);

	long long loopCount;


    void IntegerAdd()
    {
        for (int i = 0; i < ArraySize; i++)
            intResultArray[i] = intSourceArray[i] + 1;
    }

    void IntegerMultiply()
    {
        for (int i = 0; i < ArraySize; i++)
            intResultArray[i] = intSourceArray[i] * 5;
    }

    void IntegerDivide()
    {
        for (int i = 0; i < ArraySize; i++)
            intResultArray[i] = intSourceArray[i] / 5;
    }

    void BranchyIntegerAdd()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            if (intResultArray[i] > 0)
                intResultArray[i] = intSourceArray[i] - 1;
            else
                intResultArray[i] = intSourceArray[i] + 1;
        }
    }

    void FloatAdd()
    {
        for (int i = 0; i < ArraySize; i++)
            floatResultArray[i] = floatSourceArray[i] + 1.0f;
    }

    void FloatMultiply()
    {
        for (int i = 0; i < ArraySize; i++)
            floatResultArray[i] = floatSourceArray[i] * 0.3f;
    }

    void FloatDivide()
    {
        for (int i = 0; i < ArraySize; i++)
            floatResultArray[i] = floatSourceArray[i] / 5.0f;
    }

	void VectorMultiply()
    {
	    for (int i = 0; i < ArraySizeVector; i++)
		    vectorResultArray[i] = _mm256_mul_ps(vectorSourceArray[i], vectorMultiplier);
    }

	void ShortAdd()
    {
	    for (int i = 0; i < ArraySize; i++)
		    shortResultArray[i] = shortSourceArray[i] / 2.0f;
    }

	void BranchyShortAdd()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            if (shortSourceArray[i] > 0)
                shortResultArray[i] = shortSourceArray[i] - 1;
            else
                shortResultArray[i] = shortSourceArray[i] + 1;
        }
    }

	void CreateObjectPointer()
    {
	    for (int i = 0; i < ArraySize; i++)
        {
            Object* foo = new Object();
			pointerObjectsVector.push_back(foo);
        }
    }

	void CreateObject()
    {
	    for (int i = 0; i < ArraySize; i++)
        {
            Object foo = Object();
			objectsVector.push_back(foo);
        }
    }

	void AccessObject()
    {
	    for (int i = 0; i < ArraySize; i++)
			objectsVector.at(i).value3 = objectsVector.at(i).value1 - objectsVector.at(i).value2;
    }

	void AccessPointerObject()
    {
	    for (int i = 0; i < ArraySize; i++)
			pointerObjectsVector.at(i)->value3 = pointerObjectsVector.at(i)->value1 - pointerObjectsVector.at(i)->value2;
    }
};
