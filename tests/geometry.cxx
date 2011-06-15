#define BOOST_TEST_MODULE Geometry
#include <boost/test/included/unit_test.hpp>

#include "vertex.h"
#include "network.h"
#include "edge.h"

using namespace jkdl;

BOOST_AUTO_TEST_CASE(vertex_newdelete_test) {
    Vertex *v;
    
    v = new Vertex;
    delete v;
    v = new Vertex(0, 0);
    delete v;
}

BOOST_AUTO_TEST_CASE(vertex_getset_test) {
    Vertex *vertex = new Vertex(10, 20);
    BOOST_CHECK_EQUAL(vertex->x(), 10);
    BOOST_CHECK_EQUAL(vertex->y(), 20);

    vertex->move(15, 25);
    BOOST_CHECK_EQUAL(vertex->x(), 15);
    BOOST_CHECK_EQUAL(vertex->y(), 25);

    vertex->setX(160);
    vertex->setY(250);
    vertex->setColor(0xff0000);
    BOOST_CHECK_EQUAL(vertex->x(), 160);
    BOOST_CHECK_EQUAL(vertex->y(), 250);
    BOOST_CHECK_EQUAL(vertex->color(), 0xff0000);

    delete vertex;
}

BOOST_AUTO_TEST_CASE(network_newdelete_test) {
    Network *network = new Network;
    delete network;
}

BOOST_AUTO_TEST_CASE(network_grid_test) {
    Network *network = new Network;
    network->setupGrid(20, 35);

    BOOST_CHECK_EQUAL(network->gridWidth(), 20);
    BOOST_CHECK_EQUAL(network->gridHeight(), 35);
    BOOST_CHECK_EQUAL(network->gridAt(0, 0), 0);
    BOOST_CHECK_EQUAL(network->gridAt(19, 34), 0);

    Vertex *v1, *v2, *v3;
    network->addVertex(v1 = new Vertex, 5, 10);
    network->addVertex(v2 = new Vertex, 14, 21);
    network->addVertex(v3 = new Vertex, 19, 34);

    BOOST_CHECK_EQUAL(network->gridAt(5, 10), v1);
    BOOST_CHECK_EQUAL(network->gridAt(14, 21), v2);
    BOOST_CHECK_EQUAL(network->gridAt(19, 34), v3);

    delete v1;
    v2->remove();
    network->gridAt(19, 34)->remove();

    BOOST_CHECK_EQUAL(network->gridAt(5, 10), 0);
    BOOST_CHECK_EQUAL(network->gridAt(14, 21), 0);
    BOOST_CHECK_EQUAL(network->gridAt(19, 34), 0);

    delete v2;
    delete v3;
    delete network;
}

BOOST_AUTO_TEST_CASE(network_addvertex_remove_test) {
    Network *network = new Network();

    Vertex *v1 = new Vertex(10, 20);
    Vertex *v2 = new Vertex(15, 5);
    
    network->addVertex(v1);
    v1->connectWith(v2);

    BOOST_CHECK_EQUAL(v1->network(), network);
    BOOST_CHECK_EQUAL(v2->network(), network);

    v1->remove();
    BOOST_CHECK_EQUAL(v1->network(), 0);
    BOOST_CHECK_EQUAL(v2->connectedEdges()->size(), 0);

    delete v2;
    BOOST_CHECK_EQUAL(network->vertexes()->size(), 0);

    delete v1;
    delete network;
}

