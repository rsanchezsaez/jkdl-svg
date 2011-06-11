#include "unimplemented.h"

using namespace jkdl;

unimplemented::unimplemented() :
    _spec("Unimplemented method(unknown spec)")
{   }

unimplemented::unimplemented(const char* spec) :
    _spec(spec)
{   }

const char *unimplemented::what() const throw() {
    return _spec;
}

