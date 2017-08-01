#include "List.h"
#include <iostream>

int main() {
	List<int> list;
	
	list.add(2);
	list.add(3);
	list.add(4);

	std::cout << list.size() << std::endl;
	std::cout << list.get(0) << std::endl;
	std::cout << list.get(1) << std::endl;
	std::cout << list.get(2) << std::endl;

	std::cin.get();
}