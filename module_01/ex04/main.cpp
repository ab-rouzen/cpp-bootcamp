#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	std::ifstream	file(argv[1]);
	std::string		fileName = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	if (file.is_open() == false)
		return (1);
	file.seekg(0, std::ios::end);
	std::string buff;
	buff.reserve(file.tellg());
	file.seekg(0, std::ios::beg);
	buff.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	int lenS1 = s1.length();
	for (;;)
	{
		if (buff.find(s1) == std::string::npos)
			break ;
		int pos = buff.find(s1);
		buff.erase(pos, lenS1);
		buff.insert(pos, s2);
	}
	std::ofstream	newFile(fileName + ".replace");
	newFile << buff;
	return (0);
}