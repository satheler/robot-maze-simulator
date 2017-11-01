#include "Labirinto.h"
#include <iostream>

Labirinto :: Labirinto()
{
}

void Labirinto :: loadMaze(string arquivo){
    ifstream meuArquivo;
    meuArquivo.open(arquivo.c_str());

    if (meuArquivo.is_open()){
        string configs;
        int posx, posy;

        char caminho = ' ';
        string linha;

        meuArquivo >> configs >> dimx >> dimy;

        meuArquivo >> configs >> posx >> posy;
        posIni = Point(posx, posy);

        meuArquivo >> configs >> robot;

        meuArquivo >> noskipws >> caminho;
        for (int i = 0; i < dimx; i++){
            getline(meuArquivo, linha);
            cout << linha << endl;
            for (int j = 0; j < dimy; j++){
                lab[i][j] = linha[j];
            }
        }

        meuArquivo.close();

    } else {
        cout << "Não foi possivel abrir este arquivo" << endl;
        meuArquivo.close();
    }
}

bool Labirinto :: isEmpty(const Point& pos) const {
    if(pos.getX() < 0 || pos.getX() >= dimx || pos.getY() < 0 || pos.getY() >= dimy) return true;
    return (lab[pos.getY()][pos.getX()] == ' ');
}

int Labirinto :: getWidth() {
    return dimx;
}
int Labirinto :: getHeight() {
    return dimy;
}

int Labirinto::getRobot() {
    return robot;
}

Point Labirinto::getIniPos() {
    return posIni;
}
