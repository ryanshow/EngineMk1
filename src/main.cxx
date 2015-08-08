#include <iostream>
#include "format.h"
#include "config.h"

int main(int argc, char *argv[]) {
	fmt::print("EngineMk1 Version {}.{}\n", EngineMk1_VERSION_MAJOR, EngineMk1_VERSION_MINOR);
	std::cin.get();
	return 0;
}