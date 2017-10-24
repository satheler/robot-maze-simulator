#include "Robby.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Robby::Robby(const Point& iniPos, Maze*l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("R2d2.jpg", false);
}

void Robby::generateSteps()
{
    int x = iniPos.getX();
    int y = iniPos.getY();

    steps.push_back(Point(x, y));
    bool saiu = false;
    int qntPassos = 1;

    while(!saiu && qntPassos < maxSteps){

        // INICIANDO PARA A DIREITA
        while(maze->isEmpty(Point(x + 1, y))){
            x += 1;
            steps.push_back(Point(x, y));
            qntPassos++;

            if(qntPassos == maxSteps){
                saiu = true;
                break;
            }
        }

        // QUANDO NÃO DER MAIS PARA IR A DIREITA, ELE VIRA A DIREITA (OU SEJA PARA BAIXO)
        while(maze->isEmpty(Point(x, y + 1))){ X
            y += 1;
            steps.push_back(Point(x, y));
            qntPassos++;

            if(qntPassos == maxSteps){
                saiu = true;
                break;
            }
        }

        // QUANDO NÃO DER MAIS PARA A 'NOVA DIREITA' OU CASO ELE NÃO POSSA IR PARA A DIREITA ELE VIRA A ESQUERDA
        while(maze->isEmpty(Point(x, y - 1))){
            y -= 1;
            steps.push_back(Point(x, y));
            qntPassos++;

            if(qntPassos == maxSteps){
                saiu = true;
                break;
            }
        }

        // QUANDO NÃO DER PARA IR MAIS PARA A ESQUERDA, ELE RETORNA PARA A DIREITA
        while(maze->isEmpty(Point(x - 1, y))){
            x -= 1;
            steps.push_back(Point(x, y));
            qntPassos++;

            if(qntPassos == maxSteps){
                saiu = true;
                break;
            }
        }

        if(x >= maze->getWidth() || x < 0 || y >= maze->getHeight() || y < 0){
            saiu = true;
        }
    }
}

void Robby::draw()
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
