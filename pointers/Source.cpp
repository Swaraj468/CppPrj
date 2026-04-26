#include<iostream>
#include<vector>
#include<algorithm>
//#include "Header.h"
#include <memory>

void printInt(int val) {
	//unique ptr the usage is very similar to raw pointer.
	std::unique_ptr<int> intUniquePtr = std::make_unique<int>(5);

	//it doesnot allow to copy but it allows to move. the std::move transfers the ownership of the raw pointer internally to the other one.
	std::unique_ptr<int> anotherPtr = std::move(intUniquePtr);
	std::cout << intUniquePtr << std::endl;
	if (intUniquePtr) {
		std::cout << *intUniquePtr << std::endl;
	}
	anotherPtr.reset();
	//it is used when the pointer is supose to be shared. Use unique whenever possible
	//in real practice though, shared_pointer is used a lot.
	//a texture, any assets that is suppose to be shared between different objects, shared is a good choice.
	//unique pointer is more suited for single private ownership.
	//shared ptr are thread safe.
	std::shared_ptr<int> anotherShared = std::make_shared<int>(5); //ref count = 1
	std::shared_ptr<int> intShared = anotherShared; //ref count = 2


	// weak ptr? used in conjunction with the shared pointer.
	std::weak_ptr<int> intWeakPtr = anotherShared; //ref count doesnot increment, ref count = 2
	std::weak_ptr<int> emptyWeak;
	emptyWeak = intWeakPtr;

	// copy is fine in weak pointer
	std::weak_ptr<int> copyWeakPtr = intShared;

	//reset only reset the weak ptr itself, make it expired, do not affect ref count, do not make other weak pointer expired.
	intWeakPtr.reset();


	//lock generates another shared pointer. multi threading
	std::shared_ptr<int> anotherSShared = intWeakPtr.lock(); //ref = 2 now cause 
	std::cout << anotherSShared << std::endl;
	//std::cout << intWeakPtr.lock() << std::endl;




	anotherShared.reset(); //ref count = 1

	if (intWeakPtr.expired()) {
		std::cout << "The weak pointer is expired" << std::endl;
	}
	else {
		std::cout << "The weak pointer is alive" << std::endl;
	}
	intShared.reset();
	if (intWeakPtr.expired()) {
		std::cout << "The weak pointer is expired" << std::endl;
	}
	else {
		std::cout << "The weak pointer is alive" << std::endl;
	}
	//	int* rawInt = new int{ 5 };
	//	int* anotherPtr = rawInt;
	//
	//	delete  rawInt;
	//	rawInt = nullptr;
	//	std::cout << anotherPtr << std::endl;
	//}
}

int main() {
	while (true) {
		printInt(5);
	}
	int* array = new int[5]; //making a pointer that points to an array created on the heap.
	delete[] array; //remember to delete with the [] if you are free the entire array.

}



//int x = 5;
//int* xPtr = &x;
//int* xPtr3 = &x;
//int** PtrToxPtr = &xPtr;
//void* xPtr2 = &x;

//float floatVar = 12.5;
//float* myFloat = &floatVar;

//std::cout << xPtr << std::endl;
//std::cout << xPtr2 << std::endl;
//std::cout << myFloat << std::endl;
//std::cout << *myFloat << std::endl;
////std::cout << *(int*)xPtr2 << std::endl; this is called raw style casting but in this type casting we don't check if the type is not compatible
//std::cout << *static_cast<int*>(xPtr2) << std::endl;
//int intArray[5] = { 1, 2, 3, 4, 5 };

//for (int i = 0; i < sizeof(intArray) / sizeof(int); i++) {
//	std::cout << *(intArray + i) << std::endl;
//}