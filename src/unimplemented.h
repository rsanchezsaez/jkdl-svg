#include <exception>

namespace jkdl {

class unimplemented : public std::exception {
public:
    const char *what() const throw();
};

} // jkdl

