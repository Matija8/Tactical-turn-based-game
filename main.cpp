#include "mainwindow.h"
#include "grid.h"
#include "field.h"
#include "unit.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //logic
    Grid our_grid(2,3);
    std::cout << our_grid << "\n Uspeh!" << std::endl;

    Warrior w1(300,10,5,10,10);
    std::cout << w1 << "\n Uspeh!" << std::endl;

    Healer h1(300,10,5,10,10);
    std::cout << h1 << "\n Uspeh!" << std::endl;

    /*Field our_field(1,2);
    std::cout << our_field << "\n Uspeh!" << std::endl;*/


    w.show();
    return a.exec();
}
