#include "ui/DashBoard.h"

int main(int argc, char *argv[]) {
    QApplication *app = new QApplication(argc, argv);
    DashBoard *dash = new DashBoard(nullptr);
    dash->show();
    return app->exec();
}
