#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QProcess>
#include <QPushButton>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QTimerEvent>
#include <QTimer>
#include <QPalette>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QByteArray>
#include <QIcon>
#include <QSize>
#include <QLineEdit>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QMessageBox>
#include <QThread>

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    ui->open_btn->setHidden(false);
    ui->mainToolBar->setHidden(true);
    ui->statusBar->setHidden(true);
    //ui->open_btn->setDefault(true);

    ui->plylist_view->setColumnCount(3);
    ui->plylist_view->setRowCount(0);
    ui->plylist_view->setHorizontalHeaderLabels(QStringList()
                                                << tr("绝对路径")
                                                << tr("文件名")
                                                << tr("时长"));
    ui->plylist_view->setColumnHidden(0, true);
    ui->plylist_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->begin_btn->setIconSize(QSize(30, 30));
    ui->begin_btn->setIcon(QIcon(":ico/ico/start.png"));

    ui->stop_btn->setIconSize(QSize(30, 30));
    ui->stop_btn->setIcon(QIcon(":ico/ico/stop.png"));

    ui->prev_btn->setIconSize(QSize(30, 30));
    ui->prev_btn->setIcon(QIcon(":ico/ico/prev.png"));

    ui->backward_btn->setIconSize(QSize(30, 30));
    ui->backward_btn->setIcon(QIcon(":ico/ico/backward.png"));

    ui->next_btn->setIconSize(QSize(30, 30));
    ui->next_btn->setIcon(QIcon(":ico/ico/next.png"));

    ui->forwrad_btn->setIconSize(QSize(30, 30));
    ui->forwrad_btn->setIcon(QIcon(":ico/ico/forward.png"));

    ui->fullscreen->setIconSize(QSize(25, 25));
    ui->fullscreen->setIcon(QIcon(":ico/ico/full.png"));

    ui->open_btn->setIconSize(QSize(30, 30));
    ui->open_btn->setIcon(QIcon(":ico/ico/open.png"));

    ui->clt_ply->setIconSize(QSize(15, 15));
    ui->clt_ply->setIcon(QIcon(":ico/ico/ply.png"));

    ui->add_btn->setIconSize(QSize(23, 23));
    ui->add_btn->setIcon(QIcon(":ico/ico/add.png"));

    ui->del_btn->setIconSize(QSize(16, 16));
    ui->del_btn->setIcon(QIcon(":ico/ico/del.png"));

    ui->mode_btn->setIconSize(QSize(25, 25));
    ui->mode_btn->setIcon(QIcon(":ico/ico/onelist.png"));

    ui->save_ply->setIconSize(QSize(25, 25));
    ui->save_ply->setIcon(QIcon(":/ico/ico/savelst.png"));

    ui->load_ply->setIconSize(QSize(25, 25));
    ui->load_ply->setIcon(QIcon(":/ico/ico/lodelst.png"));

    ui->vlm_btn->setIconSize(QSize(15, 15));
    ui->vlm_btn->setIcon(QIcon(":ico/ico/speaker.png"));

    ui->delall_btn->setIconSize(QSize(15, 15));
    ui->delall_btn->setIcon(QIcon(":ico/ico/delete.png"));

    ui->plylistwin->setHidden(true);
    ui->plylistwin->setAllowedAreas(Qt::LeftDockWidgetArea
                                    |Qt::RightDockWidgetArea);

    //ui->plylistwin->setMinimumWidth(200);
    ui->plylistwin->setMaximumWidth(500);
    ui->plylist_view->setMaximumWidth(500);
    ui->plylist_view->setColumnWidth(1, 200);
    ui->plylist_view->setColumnWidth(2, 70);
    ply_show = false;
    ply_mode = 0;

    QString lst_name = QDir::homePath() + tr("/.cache/suplayer.lst");
    ply_lst = new QFile(lst_name);

    ui->vlm_sld->setRange(0, 99);
    ui->progress_sld->setRange(0, 99);
    Working = false;
    dclicked = false;
    muted = false;
    vlm_s = 30;
    sound_clk = false;
    now_row = -1;
    isfull = false;
    ui->del_btn->setEnabled(false);
    ui->subwin->installEventFilter(this);
    //ui->plylistwin->installEventFilter(this);

    // this
    //QPalette mpt = this->palette();
    //mpt.setColor(QPalette::Background, Qt::red);
    //this->setPalette(mpt);
    //this->setAutoFillBackground(true);

    // centralwidget
    //QPalette cpt = ui->centralWidget->palette();
    //cpt.setColor(QPalette::Background, Qt::green);
    //ui->centralWidget->setPalette(cpt);
    //ui->centralWidget->setAutoFillBackground(true);

    // subwin
    /*
    QPixmap pixmap(":/ico/ico/ground.jpg");
    plt = new QPalette;
    plt->setBrush(ui->subwin->backgroundRole(), QBrush(pixmap));
    ui->subwin->setPalette(*plt);
    ui->subwin->setMask(pixmap.mask());
    ui->subwin->setAutoFillBackground(true);*/

    QPalette plt = ui->subwin->palette();
    plt.setColor(QPalette::Background, Qt::black);
    ui->subwin->setPalette(plt);
    ui->subwin->setAutoFillBackground(true);
    ui->open_btn->setHidden(false);

    tm_id = startTimer(1000);
    mouse_tm_id = -1;
    mouse_move_tm_id = -1;

    moveplayer = new QProcess(this);
    rurl = new QProcess(this);
    enablebtn();

    qsrand(time(NULL));

    connect(moveplayer, SIGNAL(readyReadStandardOutput()),
            this, SLOT(processMpAns()));
    connect(rurl, SIGNAL(readyReadStandardOutput()), this, SLOT(processurl()));
    connect(moveplayer, SIGNAL(finished(int)),
            this, SLOT(do_finished()));
    connect(ui->plylist_view, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(dclicke_lst()));
    connect(ui->del_btn, SIGNAL(clicked()), this, SLOT(enableDelbtn()));
    connect(ui->progress_sld, SIGNAL(sliderMoved(int)), this, SLOT(setprogress(int)));
    connect(ui->vlm_sld, SIGNAL(valueChanged(int)), this, SLOT(setvlm(int)));
    connect(ui->url, SIGNAL(triggered()), this, SLOT(newwin()));
    //connect(moveplayer, SIGNAL(error(QProcess::ProcessError error)), this, SLOT(do_error()));
    this->setWindowTitle(tr("Suplayer"));
    connect(ui->files, SIGNAL(triggered()), this, SLOT(on_add_btn_clicked()));
}

mainwindow::~mainwindow()
{
    delete ui;
}

bool mainwindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->subwin) {
        if (event->type() == QEvent::MouseButtonPress) {
            mouse_tm_id = startTimer(300);
        } else if (event->type() == QEvent::MouseButtonDblClick) {
            killTimer(mouse_tm_id);
            on_fullscreen_clicked();
        } else {
            return false;
        }
        return true;
    } /*else if (obj == ui->plylistwin) {
    }*/ else {
        return QMainWindow::eventFilter(obj, event);
    }
}


void mainwindow::timerEvent(QTimerEvent *event)
{
    if (Working && event->timerId() == tm_id) {
        if (new_begin) {
            moveplayer->write("get_time_length\n");
            new_begin = false;
        }
        moveplayer->write("get_time_pos\n");
        moveplayer->write("get_percent_pos\n");
    } else if (event->timerId() == mouse_tm_id) {
        killTimer(mouse_tm_id);
        if (now_row > -1 || moveplayer->state() == QProcess::Running) {
            on_begin_btn_clicked();
        }
    }
}

void mainwindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        if (isfull) {
            on_fullscreen_clicked();
        } else {
            this->close();
        }
        break;
    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void mainwindow::newwin()
{
    urldialog = new child(this);
    urldialog->show();
}

void mainwindow::seturl()
{ 
    QStringList url(urldialog->url->text());
    urldialog->close();
    delete urldialog;

    qDebug()<<url;
    rurl->start("geturl.sh", url);
    qDebug()<<"rulr1"<<rurl->state();
    QThread::sleep(1);
    qDebug()<<"rulr2"<<rurl->state();
    QThread::sleep(4);
    qDebug()<<"rulr2"<<rurl->state();
}

void mainwindow::processurl()
{
    qDebug()<<"url ok";
    QString out = rurl->readAllStandardOutput();

    QStringList htp = out.split("\"");
    int row = ui->plylist_view->rowCount();
    int i;

    for (i = 0; i < htp.size(); i++, row++) {
        qDebug()<<htp[i];
        if ((htp[i].split(":"))[0] == tr("http")) {
            ui->plylist_view->insertRow(row);
            ui->plylist_view->setItem(row, 0, new QTableWidgetItem(htp[i]));
            ui->plylist_view->setItem(row, 1, new QTableWidgetItem(htp[i]));
            ui->plylist_view->setItem(row, 2, new QTableWidgetItem("00:00:00"));
        }
    }
    ui->del_btn->setEnabled(true);
    enablebtn();
    dclicked = true;
    moveplayer->close();
    startplay(row - i);
}

/*
void mainwindow::scshot()
{
    if (moveplayer->state() == QProcess::Running) {
        moveplayer->write("screenshot 0\n");
    }
}
*/

/*
void mainwindow::do_error()
{
    qDebug()<<"error: "<<moveplayer->error();
}
*/

void mainwindow::setprogress(int pgs)
{
    moveplayer->write("seek " + QByteArray::number(pgs, 10) + " 1\n");
}

void mainwindow::setvlm(int vlm)
{
    if (!sound_clk) {
     vlm_s = vlm;
    } else {
        sound_clk = false;
    }
    moveplayer->write("volume " + QByteArray::number(vlm, 10) + " 1\n");
    if (vlm == 0) {
        muted = true;
        ui->vlm_btn->setIcon(QIcon(":ico/ico/mute.png"));
    } else {
        muted = false;
        ui->vlm_btn->setIcon(QIcon(":ico/ico/speaker.png"));
    }
}

void mainwindow::on_begin_btn_clicked()
{
    if (moveplayer->state() == QProcess::Running) {
        moveplayer->write("pause\n");
        if (Working) {
            Working = false;
            ui->begin_btn->setIcon(QIcon(":ico/ico/start.png"));
        } else {
            Working = true;
            ui->begin_btn->setIcon(QIcon(":ico/ico/pause.png"));
        }
    } else {
        startplay();
    }
}

void mainwindow::on_prev_btn_clicked()
{
    dclicked = true;
    moveplayer->close();
    startplay(--now_row);
}

void mainwindow::on_backward_btn_clicked()
{
    moveplayer->write("seek -10\n");
}

void mainwindow::on_next_btn_clicked()
{
    dclicked = true;
    moveplayer->close();
    startplay(++now_row);
}

void mainwindow::on_forwrad_btn_clicked()
{
    moveplayer->write("seek +10\n");
}

void mainwindow::on_open_btn_clicked()
{
    if (on_add_btn_clicked()) {
        startplay();
    }
}

void mainwindow::enableDelbtn()
{
    ui->del_btn->setEnabled(ui->plylist_view->rowCount() > 0);
}

void mainwindow::enablebtn()
{
    ui->prev_btn->setEnabled(now_row > 0);
    ui->next_btn->setEnabled(now_row > -1 && now_row < ui->plylist_view->rowCount() - 1);
    ui->begin_btn->setEnabled(ui->plylist_view->rowCount() > 0 || moveplayer->state() == QProcess::Running);
    ui->backward_btn->setEnabled(ui->begin_btn->isEnabled() && now_row > -1);
    ui->forwrad_btn->setEnabled(ui->begin_btn->isEnabled() && now_row > -1);
    ui->stop_btn->setEnabled(now_row > -1 || moveplayer->state() == QProcess::Running);
    ui->vlm_sld->setEnabled(now_row > -1 || moveplayer->state() == QProcess::Running);
    ui->progress_sld->setEnabled(now_row > -1|| moveplayer->state() == QProcess::Running);
}

void mainwindow::processMpAns()
{
    QString out = moveplayer->readAllStandardOutput();

    QStringList time_length = out.split("ANS_LENGTH=");
    QStringList time_pos = out.split("ANS_TIME_POSITION=");
    QStringList percent = out.split("ANS_PERCENT_POSITION=");
    //QStringList scname = out.split("screenshow '");
//qDebug()<<"scname: "<<scname<<"      "<<scname.size();
    if (time_length.size() > 1) {
        QStringList tmp = time_length[1].split(".");
        int alltime = tmp[0].toInt();
        int hour = alltime / 3600;
        int min = alltime % 3600 / 60;
        int sec = alltime % 3600 % 60;
        QString tmlen;
        tmlen.sprintf("%02d:%02d:%02d", hour, min, sec);
        ui->timelen_lb->setText(tmlen);
        ui->plylist_view->setItem(now_row, 2, new QTableWidgetItem(tmlen));
    }

    if (time_pos.size() > 1) {
        QStringList tmp = time_pos[1].split(".");
        int alltime = tmp[0].toInt();
        int hour = alltime / 3600;
        int min = alltime % 3600 / 60;
        int sec = alltime % 3600 % 60;
        QString tmpos;
        tmpos.sprintf("%02d:%02d:%02d", hour, min, sec);
        ui->timepos_lb->setText(tmpos);
    }

    if (percent.size() > 1) {
        QString prcstr = percent[1].mid(0, percent[1].length() - 1);
        int poc = prcstr.toInt();
        ui->progress_sld->setValue(poc);
    }
/*
    if (scname.size() > 1) {
        QStringList tmp = scname[1].split("'");
        QFile scpct(tmp[0]);
        QString svname = QFileDialog::getSaveFileName(this,
                                                      tr("save picture"),
                                                      QDir::homePath(),
                                                      "All(*)");
        if (!svname.isEmpty()) {
            QFile svpct(svname);
            if (!scpct.open(QIODevice::ReadOnly)
                    || !svpct.open(QIODevice::WriteOnly
                                  | QIODevice::Truncate)) {
                QMessageBox::warning(this, tr("warning"),
                                  tr("无法打开文件"),
                                  QMessageBox::Ok);
            } else {
                while(!scpct.atEnd()) {
                    svpct.write(scpct.read(4096));
                }
                scpct.close();
                svpct.close();
                scpct.remove();
            }
        }
    }
    */
}

void mainwindow::startplay(int row)
{
    ui->open_btn->setHidden(true);
//qDebug()<<"start ";
    if (row > -1) {
        now_row = row;
        QString name = ui->plylist_view->item(row, 0)->text();
        //qDebug()<<"|"<<name<<"|";
        QStringList args;
        args //<< "-vf screenshot"
             << "-quiet" << "-slave"
            << "-wid" << QString::number(ui->subwin->winId())
            //<< "-x" << QString::number(ui->subwin->width())
            //<< "-y" << QString::number(ui->subwin->height())
            << "-zoom"
            << name;
        //qDebug()<<args;
        moveplayer->start("mplayer", args);
        //qDebug()<<"statue: "<<moveplayer->state();
        Working = true;
        new_begin = true;
        ui->vlm_sld->setValue(30);
        ui->begin_btn->setIcon(QIcon(":ico/ico/pause.png"));
        enablebtn();
        this->setWindowTitle(ui->plylist_view->item(row, 1)->text());
    }
}

bool mainwindow::on_add_btn_clicked()
{
    qDebug()<<"add ok";

    qDebug()<<"state "<<rurl->state();
    QStringList fname;
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Open file"),
                                                tr("/home/"),
                                                tr("Media(*.rmvb *.avi \
                                                   *.mp4 *.mp3 *.acc *.ogg)"));

    if (files.size() > 0) {
        int row = ui->plylist_view->rowCount();
        for (QStringList::iterator i = files.begin(); i != files.end(); ++i) {
            ui->plylist_view->insertRow(row);
            ui->plylist_view->setItem(row, 0, new QTableWidgetItem(*i));
            fname = (*i).split("/");
            ui->plylist_view->setItem(row, 1, new QTableWidgetItem(fname[fname.size() - 1]));
            ui->plylist_view->setItem(row, 2, new QTableWidgetItem("00:00:00"));
            row++;
        }
        ui->del_btn->setEnabled(true);
        enablebtn();
        return true;
    }

    return false;
}

void mainwindow::on_del_btn_clicked()
{
    int row = ui->plylist_view->currentRow();
    row = row == -1 ? ui->plylist_view->rowCount() - 1 : row;
    ui->plylist_view->removeRow(row);
    on_save_ply_clicked();

    if (now_row >= ui->plylist_view->rowCount()) {
        --now_row;
        enablebtn();
    }
}

void mainwindow::on_fullscreen_clicked()
{
    isfull = !isfull;
    ui->plylistwin->setHidden(isfull || !ply_show);
    ui->begin_btn->setHidden(isfull);
    ui->prev_btn->setHidden(isfull);
    ui->forwrad_btn->setHidden(isfull);
    ui->next_btn->setHidden(isfull);
    ui->backward_btn->setHidden(isfull);
    ui->progress_sld->setHidden(isfull);
    ui->vlm_sld->setHidden(isfull);
    ui->stop_btn->setHidden(isfull);
    ui->fullscreen->setHidden(isfull);
    ui->timelen_lb->setHidden(isfull);
    ui->timepos_lb->setHidden(isfull);
    ui->time_lb_2->setHidden(isfull);
    ui->clt_ply->setHidden(isfull);
    ui->vlm_btn->setHidden(isfull);
    //ui->mainToolBar->setHidden(isfull);
    //ui->statusBar->setHidden(isfull);
    ui->menuBar->setHidden(isfull);
    if (isfull) {
        mainrect = this->geometry();
        cenrect = ui->centralWidget->geometry();
        subrect = ui->subwin->geometry();

        this->showFullScreen();
        this->setGeometry(QApplication::desktop()->screenGeometry());

        ui->centralWidget->showFullScreen();
        ui->centralWidget->setGeometry(QApplication::desktop()->screenGeometry());

        ui->subwin->showFullScreen();
        ui->subwin->setGeometry(QApplication::desktop()->screenGeometry());

        moveplayer->write("vo_fullscreen 1");
    } else {
        this->showNormal();
        this->setGeometry(mainrect);

        ui->centralWidget->showNormal();
        ui->centralWidget->setGeometry(cenrect);

        ui->subwin->showNormal();
        ui->subwin->setGeometry(subrect);

        moveplayer->write("vo_fullscreen 0");
    }
}

void mainwindow::on_stop_btn_clicked()
{
    Working = false;
    now_row = -1;
    moveplayer->close();
    ui->begin_btn->setIcon(QIcon(":ico/ico/start.png"));
    ui->timepos_lb->setText("00:00:00");
    ui->timelen_lb->setText("00:00:00");
    QPalette plt = ui->subwin->palette();
    plt.setColor(QPalette::Background, Qt::black);
    ui->subwin->setPalette(plt);
    ui->subwin->setAutoFillBackground(true);
    ui->open_btn->setHidden(false);
    enablebtn();
    this->setWindowTitle(tr("Suplayer"));
}

void mainwindow::on_clt_ply_clicked()
{
    ui->plylistwin->setHidden(!ui->plylistwin->isHidden());
    ply_show = !ply_show;
}

void mainwindow::dclicke_lst()
{
    dclicked = true;
    moveplayer->close();
    startplay(ui->plylist_view->currentRow());
}

void mainwindow::do_finished()
{
    //qDebug()<<"-----------Finished";
    Working = false;
    if (now_row > -1 && !dclicked && ui->plylist_view->rowCount() > 0) {
        switch (ply_mode) {
        case 0:                // 顺序播放
            if (++now_row < ui->plylist_view->rowCount()) {
                startplay(now_row);
            } else {
                now_row =-1;
            }
            break;
        case 1:                // 循环列表
            now_row = (now_row + 1) % ui->plylist_view->rowCount();
            startplay(now_row);
            break;
        case 2:                // 单曲循环
            startplay(now_row);
            break;
        case 3:                  // 随机
            startplay(qrand() % ui->plylist_view->rowCount());
            break;
        default:               // 单曲播放
            break;
        }
        enablebtn();
    }
    dclicked = false;
}

void mainwindow::on_mode_btn_clicked()
{
    ply_mode = (ply_mode + 1) % 4;
    switch(ply_mode) {
    case 0:
        ui->mode_btn->setIcon(QIcon(":ico/ico/onelist.png"));
        break;
    case 1:
        ui->mode_btn->setIcon(QIcon(":ico/ico/looplst.png"));
        break;
    case 2:
        ui->mode_btn->setIcon(QIcon(":ico/ico/loop.png"));
        break;
    case 3:
        ui->mode_btn->setIcon(QIcon(":ico/ico/random.png"));
        break;
    default:
        ui->mode_btn->setIcon(QIcon(":ico/ico/signal.png"));
        break;
    }
}

void mainwindow::on_save_ply_clicked()
{

    ply_lst->open(QIODevice::WriteOnly);
    for (int i = 0; i < ui->plylist_view->rowCount(); i++) {
        ply_lst->write((ui->plylist_view->item(i, 0)->text() + "'"
                        + ui->plylist_view->item(i, 1)->text() + "'"
                        + ui->plylist_view->item(i, 2)->text() + "\n").toUtf8());
    }
    ply_lst->close();
}

void mainwindow::on_load_ply_clicked()
{
    char buf[1024];
    int row = ui->plylist_view->rowCount();

    if (ply_lst->exists()) {
        ply_lst->open(QIODevice::ReadOnly);
        while (ply_lst->readLine(buf, sizeof(buf)) > 0) {
            ui->plylist_view->insertRow(row);
            buf[strlen(buf) - 1] = '\0';
            QStringList tmp = tr(buf).split("'");
            ui->plylist_view->setItem(row, 0, new QTableWidgetItem(tmp[0]));
            ui->plylist_view->setItem(row, 1, new QTableWidgetItem(tmp[1]));
            ui->plylist_view->setItem(row, 2, new QTableWidgetItem(tmp[2]));
            row++;
        }
        ply_lst->close();
        ui->del_btn->setEnabled(true);
        enablebtn();
    }
}

void mainwindow::closeEvent(QCloseEvent *event)
{
    event = NULL;
}

void mainwindow::on_delall_btn_clicked()
{
    ui->plylist_view->setRowCount(0);
    ui->plylist_view->clearContents();
    now_row = -1;
    enablebtn();
    on_save_ply_clicked();
}

void mainwindow::on_vlm_btn_clicked()
{
    sound_clk = true;
    if (moveplayer->state() == QProcess::Running) {
        if (vlm_s != 0) {
            if (!muted) {                  // 有声，设为静音
                //qDebug()<<"有声，设为静音";
                vlm_s = ui->vlm_sld->value();
                moveplayer->write("volume 0 1\n");
                ui->vlm_sld->setValue(0);
                ui->vlm_btn->setIcon(QIcon(":ico/ico/mute.png"));
                muted = true;
            } else {                       // 无声， 设为有声
                //qDebug()<<"无声， 设为有声";
                moveplayer->write("volume " + QByteArray::number(vlm_s, 10)
                                     + "1\n");
                ui->vlm_sld->setValue(vlm_s);
                ui->vlm_btn->setIcon(QIcon(":ico/ico/speaker.png"));
                muted = false;
            }
        }
    }
}
