#ifndef LOADER_H_   /* Include guard */
#define LOADER_H_

#include <iterator>
#include <algorithm>
#include <vector>
#include "main.h"

class Loader {
public:
    Loader();
    bool LoadFile(std::string fileName, std::vector<std::string> & vecOfStrs);
};

#endif 
