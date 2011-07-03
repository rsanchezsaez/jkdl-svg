#define BOOST_TEST_MODULE Loader
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "loader.h"
#include "network.h"
#include "vertex.h"

#include <string>

using namespace jkdl;

/**
 * The 5 colors used in the megaman image.
 * BLUE and CYAN are not the ones generally known
 * under these names; I just measured them.
 * Also, I don't know if BEIGE is really a color
 * name.
 */
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xffffff
#define COLOR_BLUE  0x0070ec
#define COLOR_CYAN  0x00e8d8
#define COLOR_BEIGE 0xfce4a0

#define CHECK_COLOR(network, x, y, clr) \
    BOOST_CHECK_EQUAL(network.gridAt(x, y)->color(), clr)

#define IS_CONNECTED(network, x1, y1, x2, y2) \
    (network.gridAt(x1, y1)->isConnected(*(network.gridAt(x2, y2))))

BOOST_AUTO_TEST_CASE(load_png_megaman) {
    Network network;
    loadImageFromFile(network, std::string("img/megaman.png"));
    
    CHECK_COLOR(network, 0, 0, COLOR_WHITE);
    CHECK_COLOR(network, 8, 11, COLOR_BLACK);
    CHECK_COLOR(network, 13, 10, COLOR_BEIGE);
    CHECK_COLOR(network, 20, 23, COLOR_BLUE);
    CHECK_COLOR(network, 15, 8, COLOR_CYAN);
    
    network.buildConnections();
    BOOST_CHECK(IS_CONNECTED(network, 12, 8, 12, 9));
    BOOST_CHECK(IS_CONNECTED(network, 13, 21, 14, 20));
    BOOST_CHECK(IS_CONNECTED(network, 22, 23, 22, 24));
    BOOST_CHECK(IS_CONNECTED(network, 9, 5, 9, 4));
    
    BOOST_CHECK(!IS_CONNECTED(network, 16, 19, 16, 18));
    BOOST_CHECK(!IS_CONNECTED(network, 13, 7, 12, 7));
    BOOST_CHECK(!IS_CONNECTED(network, 17, 12, 18, 12));
    BOOST_CHECK(!IS_CONNECTED(network, 8, 10, 8, 11));
}

