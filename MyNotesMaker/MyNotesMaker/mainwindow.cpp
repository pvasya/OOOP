#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

// ---------------------------

#include "QSidePanel/PanelRightSide.hpp"

#include "QSidePanel/PanelBottomSide.hpp"

// ---------------------------

#include <QTextEdit>
#include <QLabel>

// ---------------------------


#include <QScroller>

#include "style.h"

#include "searchwidget.h"
#include "settingswidget.h"

MainWindow::MainWindow(Style* st, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , style(st)
{
    ui->setupUi(this);

    // Right panel
    auto* panel_right = new PanelRightSide(ui->main_2);
    {
        panel_right->setOpenEasingCurve (QEasingCurve::Type::OutExpo);
        panel_right->setCloseEasingCurve(QEasingCurve::Type::InExpo);
        panel_right->setPanelSize(200);
        panel_right->init();



        SettingsWidget *st = new SettingsWidget();

        panel_right->setWidgetResizable(true);
        panel_right->setWidget(st);
    }

    // Bottom panel
    {
        auto* panel_bottom = new PanelBottomSide(ui->tab);
        panel_bottom->setPanelSize(180);
        panel_bottom->init();

        SearchWidget *sr = new SearchWidget();

        panel_bottom->setWidgetResizable(true);
        panel_bottom->setWidget(sr);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_backBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_closebtn_clicked()
{
    close();
}



void MainWindow::on_hidebtn_clicked()
{
    showMinimized();
}


void MainWindow::on_topbtn_clicked()
{
    if (windowFlags() & Qt::WindowStaysOnTopHint) {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        ui->topbtn->setIcon(QIcon(":/img/img/location_on_FILL0_wght400_GRAD0_opsz24.svg"));
    }
    else {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        ui->topbtn->setIcon(QIcon(":/img/img/pin_drop_FILL0_wght400_GRAD0_opsz24.svg"));
    }
    show();
}


void MainWindow::on_fullbtn_clicked()
{
    if (windowState() & Qt::WindowMaximized) {
        ui->topbtn->setDisabled(false);
        showNormal();
        ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
    } else {
        showMaximized();
        ui->topbtn->setDisabled(true);
        ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_exit_FILL0_wght400_GRAD0_opsz24.svg"));
    }

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
}


