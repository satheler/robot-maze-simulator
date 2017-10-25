#ifndef ARTUR_H
#define ARTUR_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class ArTur: public Robot
{
public:
    ArTur(const Point&, Maze*, int);
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:

    int x;
    int y;
    int contStep;

    enum Direction {Right, Left, Up,Down};

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    TEX* roboTex;
};

#endif // ARTUR_H
