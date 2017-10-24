#ifndef ROBBY_H
#define ROBBY_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class Robby: public Robot
{
public:
    Robby(const Point&, Maze*, int);	// Constructor
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex; // robot texture id
};

#endif
