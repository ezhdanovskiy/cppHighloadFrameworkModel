#ifndef CPPSWIPE_LOGGER_H
#define CPPSWIPE_LOGGER_H

#include <iostream>

#define LOG(chain) std::cout << chain << " [" << __FILE__ << ":" << __LINE__ << "]" << std::endl;

#endif //CPPSWIPE_LOGGER_H
