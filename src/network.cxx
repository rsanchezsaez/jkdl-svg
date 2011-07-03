#include "network.h"
#include "vertex.h"

#include "unimplemented.h"

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

/* This method build the VFN (Visual Feature Network).
 * It scans the image pixel per pixel and adds edges on
 * same-colored pixels on the left, bottom, and bottom-left.
 * Other directions have already been connected by previously
 * scanned pixels.
 */
void Network::buildConnections() {
  for(int x = 0; x < _gridWidth; x++)
    for(int y = 0; y < _gridHeight; y++) {
      
      // If we're not on right border
      if(x < _gridWidth - 1) {
	
	// Check right
        if(gridAt(x, y)->color() == gridAt(x + 1, y)->color())
	  gridAt(x, y)->connectWith(gridAt(x + 1, y));
	
	// If we're not on top border
	if(y > 0)
	  
	  // Check top-right
	  if(gridAt(x, y)->color() == gridAt(x + 1, y - 1)->color())
	    gridAt(x, y)->connectWith(gridAt(x + 1, y - 1));
	
	// If we're not on bottom border
	if(y < _gridHeight - 1)
	  
	  // Check bottom-right
	  if(gridAt(x, y)->color() == gridAt(x + 1, y + 1)->color())
	    gridAt(x, y)->connectWith(gridAt(x + 1, y + 1));
      }
      
      // Check bottom if we're not on bottom border
      if(y < _gridHeight - 1)
	if(gridAt(x, y)->color() == gridAt(x, y + 1)->color())
	  gridAt(x, y)->connectWith(gridAt(x, y + 1));
    }
}


