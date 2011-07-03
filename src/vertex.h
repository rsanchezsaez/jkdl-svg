#include <vector>

namespace jkdl {

class Network;
class Edge;

class Vertex {
    friend class Network;
    friend class Edge;

public:
    Vertex();
    Vertex(double x, double y);

    ~Vertex();

    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    int color() const;
    void setColor(int color);

    void move(double x, double y);
    
    void connectWith(Vertex *other);
    void disconnectWith(Vertex *other);

    std::vector<Edge*> *connectedEdges();
    bool isConnected(const Vertex& other);

    Network *network();

    void remove();

protected:
    void setNetwork(Network *network);
    void addEdge(Edge *edge);
    void removeEdge(Edge *edge);

private:
    double _x, _y;
    int _color;
    std::vector<Edge*> _edges;
    Network *_network;
};

} // jkdl

