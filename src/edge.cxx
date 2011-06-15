#include "edge.h"
#include "vertex.h"

#include "unimplemented.h"

#include <vector>
#include <iostream>

using namespace jkdl;

Edge::Edge() : 
    _start(0),
    _end(0)
{   }

Edge::~Edge() {
}

Vertex *Edge::start() {
    return _start;
}

Vertex *Edge::end() {
    return _end;
}

Network *Edge::network() {
    return _network;
}

void Edge::setNetwork(Network *network) {
    _network = network;
}

static void removethis(Edge* thisp, Vertex* vertex) {
    std::vector<Edge*>::iterator iter;
    std::vector<Edge*> *edges = vertex->connectedEdges();
    
    for(iter = edges->begin(); iter != edges->end(); iter++) {
        if(*iter == thisp) {
            edges->erase(iter);
	    return;
	}
    }
}

void Edge::remove() {
    removethis(this, _start);
    removethis(this, _end);    
}

