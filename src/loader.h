#include <string>

namespace jkdl {

class Network;

class Loader {
public:
    static void loadPng(Network *network, const std::string &filename);
};

} // jkdl

