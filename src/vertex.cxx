#include "vertex.h"
#include "network.h"

#include "unimplemented.h"

using namespace jkdl;

Vertex::Vertex() :
    _network(0) {
}

Vertex::Vertex(double x, double y) :
    _network(0) {
    setX(x);
    setY(y);
}

Vertex::~Vertex() {
    remove();
}

double Vertex::x() const {
    return _x;
}

void Vertex::setX(double x) {
    _x = x;
}

double Vertex::y() const {
    return _y;
}

void Vertex::setY(double y) {
    _y = y;
}

int Vertex::color() const {
    return _color;
}

void Vertex::setColor(int color) {
    _color = color;
}

void Vertex::move(double x, double y) {
    setX(x);
    setY(y);
}

UNIMPLEMENTED(void Vertex::connectWith(Vertex *other))

UNIMPLEMENTED(void Vertex::disconnectWith(Vertex *other))

UNIMPLEMENTED(std::vector<Edge*> *Vertex::connectedEdges())

Network *Vertex::network() {
    return _network;
}

void Vertex::remove() {
    if(_network == 0) return;
    _network->unregisterVertex(this);
}

void Vertex::setNetwork(Network *network) {
    _network = network;
}

UNIMPLEMENTED(void Vertex::addEdge(Edge *egde)) 

UNIMPLEMENTED(void Vertex::removeEdge(Edge *edge)) 


