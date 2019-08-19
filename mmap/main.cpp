#include "mmap.hpp"

int main(int argc, char** argv)
{
	if (argc != 3) {
		std::cout << "[!] Incorrect usage. ( mmap.exe {process.exe} {path.dll} )" << std::endl;
		return 0;
	}

	mmap mapper(INJECTION_TYPE::KERNEL);

	if (!mapper.attach_to_process(argv[1]))
		return 1;

	if (!mapper.load_dll(argv[2]))
		return 1;

	if (!mapper.inject())
		return 1;

	return 0;
}