#ifndef DASHBOARD_H
#define DASHBOARD_H
#pragma once

#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QMainWindow>
#include <QToolBar>
#include <QTreeView>
#include <QWidget>

class DashBoard : public QMainWindow {
    Q_OBJECT
   public:
    DashBoard(QWidget* pID);
    void CreateControls();
    void SizeControls();

   private:  // Controls
    QToolBar* mToolBar = nullptr;
    QTreeView* mExplorer = nullptr;

   private:  // Events
    void OnResize(QResizeEvent& event);
};

#endif