#include "network.h"

#include "unimplemented.h"

using namespace jkdl;

Network::Network() {
}

Network::~Network() {
}

void Network::setupGrid(int width, int height) {
    throw unimplemented();
}

Vertex *Network::gridAt(int x, int y) {
    throw unimplemented();
}

int Network::gridWidth() {
    throw unimplemented();
}

int Network::gridHeight() {
    throw unimplemented();
}

std::vector<Vertex*> Network::vertexes() {
    throw unimplemented();
}

std::vector<Edge*> Network::edges() {
    throw unimplemented();
}

void Network::addVertex(Vertex *v) {
    throw unimplemented();
}

void Network::addVertex(Vertex *v, int x, int y) {
    throw unimplemented();
}

void Network::registerVertex(Vertex *v) {
    throw unimplemented();
}

void Network::registerEdge(Edge *e) {
    throw unimplemented();
}

void Network::unregisterVertex(Vertex *v) {
    throw unimplemented();
}

void Network::unregisterEdge(Edge *e) {
    throw unimplemented();
}

