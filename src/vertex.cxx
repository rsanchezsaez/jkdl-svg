#include "vertex.h"

#include "unimplemented.h"

using namespace jkdl;

Vertex::Vertex() {
}

Vertex::Vertex(double x, double y) {
}

Vertex::~Vertex() {
}

double Vertex::x() const {
    throw unimplemented();
}

void Vertex::setX(double x) {
    throw unimplemented();
}

double Vertex::y() const {
    throw unimplemented();
}

void Vertex::setY(double y) {
    throw unimplemented();
}

int Vertex::color() const {
    throw unimplemented();
}

void Vertex::setColor(int color) {
    throw unimplemented();
}

void Vertex::move(double x, double y) {
    throw unimplemented();
}

void Vertex::connectWith(Vertex *other) {
    throw unimplemented();
}

void Vertex::disconnectWith(Vertex *other) {
    throw unimplemented();
}

std::vector<Edge*> Vertex::connectedEdges() {
    throw unimplemented();
}

Network *Vertex::network() {
    throw unimplemented();
}

void Vertex::remove() {
    throw unimplemented();
}

void Vertex::setNetwork(Network *network) {
    throw unimplemented();
}

void Vertex::addEdge(Edge *egde) {
    throw unimplemented();
}

void Vertex::removeEdge(Edge *edge) {
    throw unimplemented();
}


