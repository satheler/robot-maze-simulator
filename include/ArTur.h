#ifndef ARTUR_H
#define ARTUR_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class ArTur
{
public:
    ArTur(const Point&, Maze*, int);
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex;
};

#endif // ARTUR_H
