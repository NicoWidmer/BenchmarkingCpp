#include <iostream>
#include <thread>
#include "Workloads.h"

int main()
{
    const int durationMilliseconds = 2000;

	Workloads* workloads = new Workloads();


	std::cout << "Benchmarking int add operations..." << std::endl;
    std::thread t1(&Workloads::StartIntegerAdd, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Int add operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
    std::cout <<'\n';
	t1.join();


	workloads->running = true;
	std::cout << "Benchmarking int multiply operations..." << std::endl;
    std::thread t2(&Workloads::StartIntegerMultiply, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Int multiply operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t2.join();


	workloads->running = true;
	std::cout << "Benchmarking int divide operations..." << std::endl;
    std::thread t3(&Workloads::StartIntegerDivide, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Int divide operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t3.join();


	workloads->running = true;
	std::cout << "Benchmarking int branchy add operations..." << std::endl;
    std::thread t4(&Workloads::StartBranchyIntegerAdd, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Int branchy operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t4.join();


	workloads->running = true;
	std::cout << "Benchmarking float add operations..." << std::endl;
    std::thread t5(&Workloads::StartFloatAdd, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Float add operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t5.join();


	workloads->running = true;
	std::cout << "Benchmarking float multiply operations..." << std::endl;
    std::thread t6(&Workloads::StartFloatMultiply, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Float multiply operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t6.join();


	workloads->running = true;
	std::cout << "Benchmarking float divide operations..." << std::endl;
    std::thread t7(&Workloads::StartFloatDivide, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Float divide operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t7.join();


	//workloads->running = true;
	//std::cout << "Benchmarking float multiply operations..." << std::endl;
	//std::thread t8(&Workloads::StartIntegerAdd, workloads);
	//std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	//workloads->running = false;
	//std::cout << "Float multiply operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;

	getchar();
}
