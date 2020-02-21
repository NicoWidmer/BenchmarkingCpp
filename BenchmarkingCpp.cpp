#include <iostream>
#include <thread>
#include "Workloads.h"

int main()
{
    const int durationMilliseconds = 2000;

	Workloads* workloads = new Workloads();

	std::cout << "Benchmarking creating objects with pointers and new..." << std::endl;
    std::thread t0(&Workloads::StartCreatingObjectsPointers, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Objects with pointers created per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
    std::cout <<'\n';
	t0.join();

	workloads->running = true;
	std::cout << "Benchmarking creating objects without pointers..." << std::endl;
    std::thread t10(&Workloads::StartCreatingObjects, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Objects without pointers created per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
    std::cout <<'\n';
	t10.join();

	workloads->running = true;
	std::cout << "Benchmarking accessing objects with pointers..." << std::endl;
    std::thread t11(&Workloads::StartAccessingObjectsPointers, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Objects with pointers accessed per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
    std::cout <<'\n';
	t11.join();

	workloads->running = true;
	std::cout << "Benchmarking accessing objects without pointers..." << std::endl;
    std::thread t12(&Workloads::StartAccessingObjects, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
    std::cout << "Objects without pointers accessed per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
    std::cout <<'\n';
	t12.join();

	/*workloads->running = true;
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


	workloads->running = true;
	std::cout << "Benchmarking vector multiply operations..." << std::endl;
	std::thread t8(&Workloads::StartVectorMultiply, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
	std::cout << "Multiply per ms using vectors: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t8.join();


	workloads->running = true;
	std::cout << "Benchmarking short add operations..." << std::endl;
	std::thread t9(&Workloads::StartShortAdd, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
	std::cout << "Short add operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t9.join();


	workloads->running = true;
	std::cout << "Benchmarking branchy short add operations..." << std::endl;
	std::thread t10(&Workloads::StartBranchyShortAdd, workloads);
	std::this_thread::sleep_for(std::chrono::milliseconds(durationMilliseconds));
	workloads->running = false;
	std::cout << "Branchy short add operations per ms: " << (workloads->GetExecutedOperations() / durationMilliseconds) << std::endl;
	std::cout <<'\n';
	t10.join();*/
	
}
