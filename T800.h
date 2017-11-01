#ifndef T800_H
#define T800_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class T800: public Robot
{
public:
    T800(const Point&, Maze*, int);	// Constructor
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex; // robot texture id

    int qntPassos;
    bool resolver(int, int);
    vector<Point> percorrido;
    bool getPercorrido(const Point& ponto) const;
    vector<Point> caminho;
    bool saiuLabirinto(int, int);
};

#endif
