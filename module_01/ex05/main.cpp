#include "Defs.hpp"

int main(void)
{
    Harl comp;

    comp.complain("DEBUG");
    comp.complain("INFO");
    comp.complain("WARNING");
    comp.complain("ERROR");
    comp.complain("DEBUG");
    return (0);
}