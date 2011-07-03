#include "vertex.h"
#include "network.h"
#include "edge.h"

#include "unimplemented.h"

#include <boost/foreach.hpp>
#include <boost/assert.hpp>

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

/* Used for assertions */
/* TODO: add constness later */
static bool isStartOrEnd(Vertex& vertex, Edge& edge) {
  return edge.start() == &vertex || edge.end() == &vertex;
}

void Vertex::connectWith(Vertex *other) {
    Edge *edge = new Edge();
    _network->registerEdge(edge);
    edge->_start = this;
    edge->_end = other;
    _edges.push_back(edge);
    other->_edges.push_back(edge);
    other->_network = _network;
}

UNIMPLEMENTED(void Vertex::disconnectWith(Vertex *other))

std::vector<Edge*> *Vertex::connectedEdges() {
    return &_edges;
}

Network *Vertex::network() {
    return _network;
}

void Vertex::remove() {
    if(_network == 0) return;
    BOOST_FOREACH(Edge* link, _edges) {
        link->remove();
    }
    _network->unregisterVertex(this);
    _network = 0;
}

void Vertex::setNetwork(Network *network) {
    _network = network;
}

UNIMPLEMENTED(void Vertex::addEdge(Edge *egde)) 

UNIMPLEMENTED(void Vertex::removeEdge(Edge *edge)) 

static Vertex& otherFromEdge(Vertex& that, Edge& edge) {
  if(edge.start() == &that)
    return *(edge.end());
  else
    return *(edge.start());
}

bool Vertex::isConnected(const jkdl::Vertex& other) {
  BOOST_FOREACH(Edge* link, _edges) {
    BOOST_ASSERT(isStartOrEnd(*this, *link));
    if(&(otherFromEdge(*this, *link)) == &other)
      return true;
  }
  
  return false;
}
