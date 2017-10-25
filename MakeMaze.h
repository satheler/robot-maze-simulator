#ifndef MAKEMAZE_H
#define MAKEMAZE_H

#include <fstream>
#include "Maze.h"

using namespace std;
class MakeMaze : public Maze
{
public:
    MakeMaze();
    MakeMaze(const int, int);
    bool isEmpty(const Point& ponto) const;
    int  getWidth();
    int  getHeight();
    void loadMaze(string arquivo);
    int  getRobot();
    Point getIniPos();
private:
    int dimx, dimy;
    char lab[100][100];
    int robot;
    Point posIni;
};

#endif
