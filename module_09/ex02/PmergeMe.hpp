#ifndef	P_MERGE_ME_HPP
#define	P_MERGE_ME_HPP

#include "Defs.hpp"
#include "GroupIterator.hpp"
#include <vector>

template<class T>
class	PmergeMe
{
    public:

        typedef T container_type;
        PmergeMe(container_type &c) : cont(c){};
        PmergeMe(const PmergeMe &copy) : cont(copy.cont){};
        ~PmergeMe() {};
        void    sort(){
             mergeInsertSort(makeGroupIterator(cont.begin(), 1),
                             makeGroupIterator(cont.end(), 1));
        };

    private:
        PmergeMe&   operator=(const PmergeMe &copy){
            (void) copy;
            return(*this);
        };
        container_type    &cont;
};

#endif // ! P_MERGE_ME_HPP