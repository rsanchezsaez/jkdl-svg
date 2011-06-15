#include "network.h"
#include "vertex.h"

using namespace jkdl;

Network::Network() :
    _grid(0),
    _gridWidth(0),
    _gridHeight(0) {
}

Network::~Network() {
    if(_grid != 0)
        delete[] _grid;
}

void Network::setupGrid(int width, int height) {
    _grid = new Vertex*[width * height];
    for(int i=0; i<width * height; i++)
        _grid[i] = 0;

    _gridWidth = width;
    _gridHeight = height;
}

Vertex *Network::gridAt(int x, int y) {
    return _grid[x + _gridWidth * y];
}

int Network::gridWidth() {
    return _gridWidth;
}

int Network::gridHeight() {
    return _gridHeight;
}

std::vector<Vertex*> *Network::vertexes() {
    return &_vertexes;
}

std::vector<Edge*> *Network::edges() {
    return &_edges;
}

void Network::addVertex(Vertex *vertex) {
    vertex->setNetwork(this);
    registerVertex(vertex);
}

void Network::addVertex(Vertex *v, int x, int y) {
    addVertex(v);
    _grid[x + _gridWidth * y] = v;
}

void Network::registerVertex(Vertex *v) {
    _vertexes.push_back(v);
}

void Network::registerEdge(Edge *e) {
    _edges.push_back(e);
}

void Network::unregisterVertex(Vertex *v) {
    for(int i=0; i<_vertexes.size(); i++)
        if(v == _vertexes[i])
            _vertexes.erase(_vertexes.begin() + i);

    if(_grid == 0) return;
    for(int i=0; i<_gridWidth * _gridHeight; i++)
        if(_grid[i] == v)
            _grid[i] = 0;
}

void Network::unregisterEdge(Edge *e) {
    for(int i=0; i<_edges.size(); i++)
        if(e == _edges[i])
            _edges.erase(_edges.begin() + i);
}

