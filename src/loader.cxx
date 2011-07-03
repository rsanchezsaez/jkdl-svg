#include "loader.h"
#include "unimplemented.h"

#include <FreeImagePlus.h>
#include "network.h"
#include "vertex.h"

using namespace jkdl;

static int getRGB(RGBQUAD value) {
  return value.rgbRed << 16 | value.rgbGreen << 8 | value.rgbBlue;
}

void jkdl::loadImageFromFile(Network &network, const std::string &filename) {
  fipImage img;
  
  img.load(filename.c_str());
  img.convertTo24Bits();
  
  int width = img.getWidth();
  int height = img.getHeight();
  
  network.setupGrid(width, height);
  
  /* Origin is top-left in jkdl, bottom-left in the image, so we have
   * to turn the image upside-down. */
  for(int x = 0; x < width; x++)
    for(int y = 0; y < height; y++) {
      Vertex* v = new Vertex(x, height - 1 - y);
      
      RGBQUAD color;
      img.getPixelColor(x, y, &color);
      v->setColor(getRGB(color));
      
      network.addVertex(v, x, height - 1 - y);
    }
}

