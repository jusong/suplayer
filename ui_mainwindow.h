/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionAsdfasfas;
    QAction *actionAdadffdasf;
    QAction *actionAsdfasd;
    QAction *url;
    QAction *files;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QWidget *subwin;
    QGridLayout *gridLayout;
    QPushButton *open_btn;
    QHBoxLayout *horizontalLayout_4;
    QSlider *progress_sld;
    QHBoxLayout *horizontalLayout;
    QLabel *timepos_lb;
    QLabel *time_lb_2;
    QLabel *timelen_lb;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *prev_btn;
    QPushButton *backward_btn;
    QPushButton *begin_btn;
    QPushButton *stop_btn;
    QPushButton *forwrad_btn;
    QPushButton *next_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *clt_ply;
    QPushButton *fullscreen;
    QPushButton *vlm_btn;
    QSlider *vlm_sld;
    QMenuBar *menuBar;
    QMenu *menuSuplayer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *plylistwin;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *plylist_view;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add_btn;
    QPushButton *del_btn;
    QPushButton *mode_btn;
    QPushButton *save_ply;
    QPushButton *load_ply;
    QPushButton *delall_btn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->resize(785, 518);
        actionAsdfasfas = new QAction(mainwindow);
        actionAsdfasfas->setObjectName(QStringLiteral("actionAsdfasfas"));
        actionAdadffdasf = new QAction(mainwindow);
        actionAdadffdasf->setObjectName(QStringLiteral("actionAdadffdasf"));
        actionAsdfasd = new QAction(mainwindow);
        actionAsdfasd->setObjectName(QStringLiteral("actionAsdfasd"));
        url = new QAction(mainwindow);
        url->setObjectName(QStringLiteral("url"));
        files = new QAction(mainwindow);
        files->setObjectName(QStringLiteral("files"));
        centralWidget = new QWidget(mainwindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        subwin = new QWidget(centralWidget);
        subwin->setObjectName(QStringLiteral("subwin"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subwin->sizePolicy().hasHeightForWidth());
        subwin->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(subwin);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        open_btn = new QPushButton(subwin);
        open_btn->setObjectName(QStringLiteral("open_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(open_btn->sizePolicy().hasHeightForWidth());
        open_btn->setSizePolicy(sizePolicy1);
        open_btn->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(open_btn, 0, 0, 1, 1);


        verticalLayout_2->addWidget(subwin);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        progress_sld = new QSlider(centralWidget);
        progress_sld->setObjectName(QStringLiteral("progress_sld"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progress_sld->sizePolicy().hasHeightForWidth());
        progress_sld->setSizePolicy(sizePolicy2);
        progress_sld->setMinimumSize(QSize(250, 0));
        progress_sld->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(progress_sld);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timepos_lb = new QLabel(centralWidget);
        timepos_lb->setObjectName(QStringLiteral("timepos_lb"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(timepos_lb->sizePolicy().hasHeightForWidth());
        timepos_lb->setSizePolicy(sizePolicy3);
        timepos_lb->setMinimumSize(QSize(0, 0));
        timepos_lb->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(timepos_lb);

        time_lb_2 = new QLabel(centralWidget);
        time_lb_2->setObjectName(QStringLiteral("time_lb_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(time_lb_2->sizePolicy().hasHeightForWidth());
        time_lb_2->setSizePolicy(sizePolicy4);
        time_lb_2->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(time_lb_2);

        timelen_lb = new QLabel(centralWidget);
        timelen_lb->setObjectName(QStringLiteral("timelen_lb"));
        sizePolicy3.setHeightForWidth(timelen_lb->sizePolicy().hasHeightForWidth());
        timelen_lb->setSizePolicy(sizePolicy3);
        timelen_lb->setMinimumSize(QSize(20, 0));
        timelen_lb->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(timelen_lb);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        prev_btn = new QPushButton(centralWidget);
        prev_btn->setObjectName(QStringLiteral("prev_btn"));
        sizePolicy1.setHeightForWidth(prev_btn->sizePolicy().hasHeightForWidth());
        prev_btn->setSizePolicy(sizePolicy1);
        prev_btn->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(prev_btn);

        backward_btn = new QPushButton(centralWidget);
        backward_btn->setObjectName(QStringLiteral("backward_btn"));
        sizePolicy1.setHeightForWidth(backward_btn->sizePolicy().hasHeightForWidth());
        backward_btn->setSizePolicy(sizePolicy1);
        backward_btn->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(backward_btn);

        begin_btn = new QPushButton(centralWidget);
        begin_btn->setObjectName(QStringLiteral("begin_btn"));
        sizePolicy1.setHeightForWidth(begin_btn->sizePolicy().hasHeightForWidth());
        begin_btn->setSizePolicy(sizePolicy1);
        begin_btn->setMinimumSize(QSize(0, 0));
        begin_btn->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(begin_btn);

        stop_btn = new QPushButton(centralWidget);
        stop_btn->setObjectName(QStringLiteral("stop_btn"));
        sizePolicy1.setHeightForWidth(stop_btn->sizePolicy().hasHeightForWidth());
        stop_btn->setSizePolicy(sizePolicy1);
        stop_btn->setMinimumSize(QSize(0, 0));
        stop_btn->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(stop_btn);

        forwrad_btn = new QPushButton(centralWidget);
        forwrad_btn->setObjectName(QStringLiteral("forwrad_btn"));
        sizePolicy1.setHeightForWidth(forwrad_btn->sizePolicy().hasHeightForWidth());
        forwrad_btn->setSizePolicy(sizePolicy1);
        forwrad_btn->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(forwrad_btn);

        next_btn = new QPushButton(centralWidget);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        sizePolicy1.setHeightForWidth(next_btn->sizePolicy().hasHeightForWidth());
        next_btn->setSizePolicy(sizePolicy1);
        next_btn->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(next_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        clt_ply = new QPushButton(centralWidget);
        clt_ply->setObjectName(QStringLiteral("clt_ply"));
        sizePolicy1.setHeightForWidth(clt_ply->sizePolicy().hasHeightForWidth());
        clt_ply->setSizePolicy(sizePolicy1);
        clt_ply->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(clt_ply);

        fullscreen = new QPushButton(centralWidget);
        fullscreen->setObjectName(QStringLiteral("fullscreen"));
        sizePolicy1.setHeightForWidth(fullscreen->sizePolicy().hasHeightForWidth());
        fullscreen->setSizePolicy(sizePolicy1);
        fullscreen->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(fullscreen);

        vlm_btn = new QPushButton(centralWidget);
        vlm_btn->setObjectName(QStringLiteral("vlm_btn"));
        sizePolicy1.setHeightForWidth(vlm_btn->sizePolicy().hasHeightForWidth());
        vlm_btn->setSizePolicy(sizePolicy1);
        vlm_btn->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(vlm_btn);

        vlm_sld = new QSlider(centralWidget);
        vlm_sld->setObjectName(QStringLiteral("vlm_sld"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(vlm_sld->sizePolicy().hasHeightForWidth());
        vlm_sld->setSizePolicy(sizePolicy5);
        vlm_sld->setMaximumSize(QSize(150, 16777215));
        vlm_sld->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(vlm_sld);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        mainwindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 785, 28));
        menuSuplayer = new QMenu(menuBar);
        menuSuplayer->setObjectName(QStringLiteral("menuSuplayer"));
        mainwindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainwindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainwindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainwindow->setStatusBar(statusBar);
        plylistwin = new QDockWidget(mainwindow);
        plylistwin->setObjectName(QStringLiteral("plylistwin"));
        plylistwin->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plylist_view = new QTableWidget(dockWidgetContents_2);
        plylist_view->setObjectName(QStringLiteral("plylist_view"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(plylist_view->sizePolicy().hasHeightForWidth());
        plylist_view->setSizePolicy(sizePolicy6);
        plylist_view->setMinimumSize(QSize(60, 0));
        plylist_view->setMaximumSize(QSize(300, 16777215));

        verticalLayout->addWidget(plylist_view);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        add_btn = new QPushButton(dockWidgetContents_2);
        add_btn->setObjectName(QStringLiteral("add_btn"));
        sizePolicy1.setHeightForWidth(add_btn->sizePolicy().hasHeightForWidth());
        add_btn->setSizePolicy(sizePolicy1);
        add_btn->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(add_btn);

        del_btn = new QPushButton(dockWidgetContents_2);
        del_btn->setObjectName(QStringLiteral("del_btn"));
        sizePolicy1.setHeightForWidth(del_btn->sizePolicy().hasHeightForWidth());
        del_btn->setSizePolicy(sizePolicy1);
        del_btn->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(del_btn);

        mode_btn = new QPushButton(dockWidgetContents_2);
        mode_btn->setObjectName(QStringLiteral("mode_btn"));
        sizePolicy1.setHeightForWidth(mode_btn->sizePolicy().hasHeightForWidth());
        mode_btn->setSizePolicy(sizePolicy1);
        mode_btn->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mode_btn);

        save_ply = new QPushButton(dockWidgetContents_2);
        save_ply->setObjectName(QStringLiteral("save_ply"));
        sizePolicy1.setHeightForWidth(save_ply->sizePolicy().hasHeightForWidth());
        save_ply->setSizePolicy(sizePolicy1);
        save_ply->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(save_ply);

        load_ply = new QPushButton(dockWidgetContents_2);
        load_ply->setObjectName(QStringLiteral("load_ply"));
        sizePolicy1.setHeightForWidth(load_ply->sizePolicy().hasHeightForWidth());
        load_ply->setSizePolicy(sizePolicy1);
        load_ply->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(load_ply);

        delall_btn = new QPushButton(dockWidgetContents_2);
        delall_btn->setObjectName(QStringLiteral("delall_btn"));
        sizePolicy1.setHeightForWidth(delall_btn->sizePolicy().hasHeightForWidth());
        delall_btn->setSizePolicy(sizePolicy1);
        delall_btn->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(delall_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        plylistwin->setWidget(dockWidgetContents_2);
        mainwindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), plylistwin);

        menuBar->addAction(menuSuplayer->menuAction());
        menuSuplayer->addAction(url);
        menuSuplayer->addAction(files);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "mainwindow", 0));
        actionAsdfasfas->setText(QApplication::translate("mainwindow", "asdfasfas", 0));
        actionAdadffdasf->setText(QApplication::translate("mainwindow", "adadffdasf", 0));
        actionAsdfasd->setText(QApplication::translate("mainwindow", "asdfasd", 0));
        url->setText(QApplication::translate("mainwindow", "URL", 0));
        files->setText(QApplication::translate("mainwindow", "Files", 0));
        open_btn->setText(QApplication::translate("mainwindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        timepos_lb->setText(QApplication::translate("mainwindow", "00:00:00", 0));
        time_lb_2->setText(QApplication::translate("mainwindow", "|", 0));
        timelen_lb->setText(QApplication::translate("mainwindow", "00:00:00", 0));
        prev_btn->setText(QString());
        backward_btn->setText(QString());
        begin_btn->setText(QString());
        stop_btn->setText(QString());
        forwrad_btn->setText(QString());
        next_btn->setText(QString());
        clt_ply->setText(QString());
        fullscreen->setText(QString());
        vlm_btn->setText(QString());
        menuSuplayer->setTitle(QApplication::translate("mainwindow", "\351\200\211\351\241\271", 0));
        add_btn->setText(QString());
        del_btn->setText(QString());
        mode_btn->setText(QString());
        save_ply->setText(QString());
        load_ply->setText(QString());
        delall_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
