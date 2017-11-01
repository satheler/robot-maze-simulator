#include "T800.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

T800::T800(const Point& iniPos, Maze*l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("ironMan.jpg", false);
    qntPassos = 0;
}

void T800::generateSteps()
{
    int x = iniPos.getX();
    int y = iniPos.getY();

    T800::resolver(x, y);

    // Caminho perfeito
    for(int i = caminho.size() - 1; i >= 0 ; i--){
        steps.push_back(caminho[i]);
    }

    // Caminho total
    //for(int i = 0; i < percorrido.size(); i++){
    //    steps.push_back(percorrido[i]);
    //}
}

bool T800::resolver(int x, int y)
{
    qntPassos += 1;

    if(T800::saiuLabirinto(x, y) || qntPassos >= maxSteps)
    {
        return true;
    }

    if(T800::getPercorrido(Point(x, y)))
    {
        return false;
    }

    percorrido.push_back(Point(x, y));

    if (x > 0 && maze->isEmpty(Point(x - 1, y)) && T800::resolver(x - 1, y))
    {
        caminho.push_back(Point(x, y));
        return true;
    }

    if (x < maze->getWidth() && maze->isEmpty(Point(x + 1, y)) && T800::resolver(x + 1, y))
    {
        caminho.push_back(Point(x, y));
        return true;
    }

    if (y > 0 && maze->isEmpty(Point(x, y - 1)) && T800::resolver(x, y - 1))
    {
        caminho.push_back(Point(x, y));
        return true;
    }

    if (y < maze->getHeight() && maze->isEmpty(Point(x, y + 1)) && T800::resolver(x, y + 1))
    {
        caminho.push_back(Point(x, y));
        return true;
    }

    return false;
}

bool T800::saiuLabirinto(int x, int y)
{
    return (x >= maze->getWidth() || x < 0 || y >= maze->getHeight() || y < 0);
}

bool T800::getPercorrido(const Point& ponto) const
{
    for(int i = 0; i < percorrido.size(); i++)
    {
        if(ponto.getX() == percorrido[i].getX() && ponto.getY() == percorrido[i].getY())
        {
            return true;
        }
    }
    return false;
}


void T800::draw()
{
    float rx,ry;
    float deltax = GL::getDeltaX();
    float deltay = GL::getDeltaY();
    rx = pos.getX() * deltax;
    ry = pos.getY() * deltay;
    GL::enableTexture(roboTex->texid);
    GL::setColor(255,255,255);
    GL::drawRect(rx, ry, rx+deltax, ry+deltay);
    GL::disableTexture();
}
