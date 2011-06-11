#include <exception>

#define UNIMPLEMENTED(func_spec) \
func_spec { \
    throw unimplemented(#func_spec); \
}

namespace jkdl {

class unimplemented : public std::exception {
public:
    unimplemented();
    unimplemented(const char* spec);
    const char *what() const throw();

private:
    const char* _spec;
};

} // jkdl

