#include "ArTur.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

ArTur::ArTur(const Point& iniPos, Maze*l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("Mega.jpg", true);
}

void ArTur::generateSteps()
{
    bool hasExit = false;
    contStep = 0;
    Direction direction = Right;
    x = iniPos.getX();
    y = iniPos.getY();
    steps.push_back(Point(x,y));

    while(!hasExit && contStep < maxSteps)
    {

        switch (direction)
        {
        //Robo está olhando em direção a direita
        case Right:
            //verifica se existe parede acima (lado Esquerdo do robo)
            if(!maze->isEmpty(Point(x,y-1)))
            {
                //verifica se é possível mover em frente (direita)
                if(maze->isEmpty(Point(x+1,y)))
                {
                    moveRight();
                }
                //muda a direção que está olhando para baixo, pois como para cima é o lado esquerdo ele sabe que existe parede
                else
                {
                    direction = Down;
                }
            }
            //Como não existe parede ele sobe e muda a direção que está olhando para cima
            else
            {
                moveUp();
                direction = Up;
            }
            break;
        //Robo está olhando para a esquerda
        case Left:
            //verifica se existe parede abaixo (lado Esquerdo do robo)
            if(!maze->isEmpty(Point(x,y+1)))
            {
                //verifica se é possível mover em frente (esquerda)
                if(maze->isEmpty(Point(x-1,y)))
                {
                    moveLeft();

                }
                //muda a direção que está olhando para cima, pois para baixo como é o lado esquero ele já sabe que existe parede
                else
                {
                    direction = Up;
                }
            }
            //Como não existe parede ele desce e muda a direção que está olhando para baixo
            else
            {
                moveDown();
                direction = Down;
            }
            break;
        //Robo está olhando para cima
        case Up:
            //verifica se existe parede do lado esquerdo (lado Esquerdo do robo)
            if(!maze->isEmpty(Point(x-1,y)))
            {
                //verifica se é possível mover em frente (para cima)
                if(maze->isEmpty(Point(x,y-1)))
                {
                    moveUp();

                }
                //muda a direção que está olhando direita, pois para esquerda como é o lado esquero ele já sabe que existe parede
                else
                {
                    direction = Right;
                }
            }
            //Como não existe parede ele anda para esquerda e muda a direção que está olhando esquerda
            else
            {
                moveLeft();
                direction = Left;
            }
            break;
        //Robo está olhando para baixo
        case Down:
            //verifica se existe parede a direita (lado Esquerdo do robo)
            if(!maze->isEmpty(Point(x+1,y)))
            {
                //verifica se é possível mover em frente (para baixo)
                if(maze->isEmpty(Point(x,y+1)))
                {
                    moveDown();

                }
                //muda a direção que está olhando para esquerda, pois para direita como é o lado esquero ele já sabe que existe parede
                else
                {
                    direction = Left;
                }
            }
            //Como não existe parede ele anda para direita e muda a direção que está olhando para direita
            else
            {
                moveRight();
                direction = Right;
            }
            break;
        }
        //Verifica se o robo saiu do labirinto
        if(x >= maze->getWidth() || x < 0
                || y >= maze->getHeight() || y < 0)
            hasExit = true;

    }
}

void ArTur::moveRight()
{
    x+=1;
    steps.push_back(Point(x,y));
    contStep++;
}

void ArTur::moveLeft()
{
    x-=1;
    steps.push_back(Point(x,y));
    contStep++;
}

void ArTur::moveUp()
{
    y-=1;
    steps.push_back(Point(x,y));
    contStep++;
}

void ArTur::moveDown()
{
    y+=1;
    steps.push_back(Point(x,y));
    contStep++;
}

void ArTur::draw()
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
