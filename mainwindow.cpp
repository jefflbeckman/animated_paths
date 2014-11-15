#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animated_points.h"
#include "generated_ellipse.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // menubar incantation
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);
    QAction *quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));




    //probably a better way to place the widget, but i'm using a layout for now
    QGridLayout *layout = new QGridLayout;
    QTimer *timer = new QTimer(this);
    //build the animated eclipse object
    Animated_Points eclipse(0,(new Generated_Ellipse(0,100,0,100,500))->get_points(), 500, 5);

    layout->addWidget(&eclipse, 0,0);
    connect(timer,SIGNAL(timeout()),&eclipse,SLOT(nextAnimationFrame()));

    QAction *updateAction = fileMenu->addAction(tr("&Update"));
    connect(updateAction, SIGNAL(triggered()), &eclipse, SLOT(nextAnimationFrame()));

    timer->start(100);
    setLayout(layout);
    setWindowTitle(tr("AnimatedEllipses"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
