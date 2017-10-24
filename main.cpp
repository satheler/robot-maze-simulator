#include "Labirinto.h"
#include "RobotB9.h"
#include "Robby.h"
#include "GL.h"

using namespace std;

int main()
{
    GL::init();
    // Load the test maze
    Maze* lab = new Labirinto();
    lab->loadMaze("maze1.txt");

    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;

    Robot* robo;

    switch(lab->getRobot())
    {
    case 1:
        robo = new Robby(posIni, lab, 200);
        break;
    case 2:
        robo = new RobotB9(posIni, lab, 200); //robo de teste
        break;
    case 3:
        cout << "Robo 3" << endl;
        //robo = new T8000();
        break;
    }

    GL::setMazeRobot(lab, robo);

    GL::loop();
}
