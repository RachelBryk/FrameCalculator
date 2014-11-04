#include <tchar.h>
#include <iostream>
#include <fstream>

int main(int argc, TCHAR* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " movie.dtm \n" << argc;
		return 0;
	}

	std::ifstream movie;
	movie.open(argv[1], std::ios::out | std::ios::binary);
	if (!movie.is_open())
	{
		std::cout << "Couldn't open movie file.";
		return 0;
	}

	unsigned int frame;

	std::cout << "Enter input number to find: ";
	std:: cin >> frame;

	movie.seekg(0x100);
	unsigned int offset = 0x100;
	while (frame != 1)
	{
		char size;
		movie.read(&size, 1);
		offset += size + 1;
		movie.seekg(size, std::ios_base::cur);
		frame--;
	}
	std::cout << "Offset is 0x" << std::hex << offset;


	std::cout << "\nPress enter to exit.";
	std::cin.ignore(INT_MAX, '\n');
	std::cin.ignore(INT_MAX, '\n');

	return 0;
}
