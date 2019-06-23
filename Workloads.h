#pragma once
#include <cstdlib>

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

    //void StartVectorMultiply()
    //{
    //    loopCount = 0;

    //    while (running)
    //    {
    //        VectorMultiply();
    //        loopCount++;
    //    }
    //}

    long long GetExecutedOperations()
    {
        return loopCount * ArraySize;
    }


private:
	static const int ArraySize = 1024;
    //static const int ArraySizeVector = ArraySize / 4;
    int intSourceArray [ArraySize];
    int intResultArray [ArraySize];
    float floatSourceArray [ArraySize];
    float floatResultArray [ArraySize];
    //Vector4[] vectorSourceArray = new Vector4[ArraySizeVector];
    //Vector4[] vectorResultArray = new Vector4[ArraySizeVector];

	long long loopCount;


    void IntegerAdd()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            intResultArray[i] = intSourceArray[i] + 1;
        }
    }

    void IntegerMultiply()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            intResultArray[i] = intSourceArray[i] * 2;
        }
    }

    void IntegerDivide()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            intResultArray[i] = intSourceArray[i] / 2;
        }
    }

    void BranchyIntegerAdd()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            if (intResultArray[i] > 0)
            {
                intResultArray[i] = intSourceArray[i] - 1;
            }
            else
            {
                intResultArray[i] = intSourceArray[i] + 1;
            }
        }
    }

    void FloatAdd()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            floatResultArray[i] = floatSourceArray[i] + 1.0f;
        }
    }

    void FloatMultiply()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            floatResultArray[i] = floatSourceArray[i] * 0.5f;
        }
    }

    void FloatDivide()
    {
        for (int i = 0; i < ArraySize; i++)
        {
            floatResultArray[i] = floatSourceArray[i] / 2.0f;
        }
    }
};
