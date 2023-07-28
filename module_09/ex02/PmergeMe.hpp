#ifndef	P_MERGE_ME_HPP
#define	P_MERGE_ME_HPP

#include "Defs.hpp"
#include "GroupIterator.hpp"
#include <vector>

class	PmergeMe
{
    public:
        PmergeMe(std::vector<int> &vec);
        PmergeMe(const PmergeMe &copy);
        PmergeMe&   operator=(const PmergeMe &copy);
        ~PmergeMe();
        void    sort();
        //static void (std::vector<int> &vec);

    private:
        std::vector<int>    &cont;
};

#endif // ! P_MERGE_ME_HPP