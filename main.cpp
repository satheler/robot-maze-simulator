#include "Labirinto.h"

#include "ArTur.h"
#include "Robby.h"
#include "T800.h"

#include "GL.h"
#include "FileChooser.h"

#include <gtk/gtk.h>

using namespace std;

int main()
{
    //Carregando o arquivo de texto.
    string arquivo = FileChooser::show();

    //executando a ação principal do openGL maze
    GL::init();
    Maze* lab = new Labirinto();
    lab->loadMaze(arquivo);

    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;
    int maxSteps = 1000;
    Robot* robo;

    switch(lab->getRobot())
    {
    case 1:
        robo = new Robby(posIni, lab, maxSteps);
        break;
    case 2:
        robo = new ArTur(posIni, lab, maxSteps);
        break;
    case 3:
        robo = new T800(posIni, lab, maxSteps);
        break;
    }

    GL::setMazeRobot(lab, robo);

    GL::loop();

    gtk_main();

    return 0;
}
