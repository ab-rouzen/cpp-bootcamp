#include "Defs.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
         std::cout << "[ Probably complaining about ingnificant problems ]\n";
         return 0;
    }
    std::string level = argv[1];
    Harl        comp;
    comp.complain(level);
    return (0);
}   