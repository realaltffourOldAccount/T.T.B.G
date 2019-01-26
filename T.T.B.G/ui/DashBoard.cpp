#include "DashBoard.h"

DashBoard::DashBoard(QWidget* pID) : QMainWindow(pID) {
    setMinimumSize(QSize(750, 500));
    CreateControls();
    SizeControls();
}

void DashBoard::CreateControls() {
    mToolBar = addToolBar("Tool Bar");
    mToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);

    QPixmap openpix("open_db.png");
    QPixmap newpix("new_db.png");
    QPixmap deletepix("delete_db.png");
    QPixmap exitpix("exit.png");

    mToolBar->addAction(QIcon(openpix), "Open");
    mToolBar->addAction(QIcon(newpix), "New");
    mToolBar->addAction(QIcon(deletepix), "Delete");
    mToolBar->addSeparator();
    mToolBar->addAction(QIcon(exitpix), "Exit");

    mExplorer = new QTreeView(this);
}
void DashBoard::SizeControls() {
    mToolBar->setBaseSize(this->size().width(), 25);
}

void DashBoard::OnResize(QResizeEvent& event) { SizeControls(); }