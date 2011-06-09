namespace jkdl {

class Network {
    friend class Vertex;
    friend class Edge;

public:
    Network();
    ~Network();

    void setupGrid(int width, int height);
    Vertex *gridAt(int x, int y);
    int gridWidth();
    int gridHeight();

    std::vector<Vertex*> vertexes();
    std::vector<Edge*> edges();

    void addVertex(Vertex *v);
    void addVertex(Vertex *v, int x, int y);

protected:
    void registerVertex(Vertex *v);
    void registerEdge(Edge *e);

    void unregisterVertex(Vertex *v);
    void unregisterEdge(Edge *e);

private:
    std::vector<Vertex*> _vertexes;
    std::vector<Edge*> _edges;
    Vertex ***_grid;
};

} // jkdl

