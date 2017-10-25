#include "MakeMaze.h"
#include <iostream>

MakeMaze :: MakeMaze(int x, int y)
{
    dimx = x;
    dimy = y;
}

MakeMaze :: MakeMaze()
{
}

void MakeMaze :: loadMaze(string arquivo){
    ifstream meuArquivo;
    meuArquivo.open(arquivo.c_str());

    if (meuArquivo.is_open()){
        string configs;

        meuArquivo >> configs >> dimx >> dimy;
        meuArquivo >> configs >> robot;
        meuArquivo.close();
    } else {
        cout << "Não foi possivel abrir este arquivo" << endl;
        meuArquivo.close();
    }



}

bool MakeMaze :: isEmpty(const Point& pos) const {
    if(pos.getX() < 0 || pos.getX() >= dimx || pos.getY() < 0 || pos.getY() >= dimy) return true;
    return (lab[pos.getY()][pos.getX()] == ' ');
}

int MakeMaze :: getWidth() {
    return dimx;
}
int MakeMaze :: getHeight() {
    return dimy;
}

int MakeMaze::getRobot() {
    return robot;
}

Point MakeMaze::getIniPos() {
    return posIni;
}
