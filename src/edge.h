namespace jkdl {

class Edge {
    friend class Network;
    friend class Vertex;

public:
    Vertex *start();
    Vertex *end();

    Network *network();

    void remove();

protected:
    Edge();
    ~Edge();

    void setNetwork(Network *network);

private:
    Vertex *_start;
    Vertex *_end;
    Network *_network;
};

} // jkdl

