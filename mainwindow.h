#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>

#include "child.h"

class QProcess;
class QTimer;
class QFile;
class QPalette;

namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();
    bool eventFilter(QObject *, QEvent *);


private slots:
    void on_begin_btn_clicked();

    void on_prev_btn_clicked();

    void on_backward_btn_clicked();

    void on_next_btn_clicked();

    void on_forwrad_btn_clicked();

    void on_open_btn_clicked();

    void processMpAns();

    void startplay(int row = 0);

    void enablebtn();

    void enableDelbtn();

    bool on_add_btn_clicked();

    void on_del_btn_clicked();

    void setprogress(int);

    void setvlm(int);

    void timerEvent(QTimerEvent *);

    void on_fullscreen_clicked();

    void keyPressEvent(QKeyEvent *);

    void on_stop_btn_clicked();

    void on_clt_ply_clicked();

    void do_finished();

    void on_mode_btn_clicked();

    void newwin();

    void seturl();

    void on_save_ply_clicked();

    void on_load_ply_clicked();

    void dclicke_lst();

    void closeEvent(QCloseEvent *);

    void on_delall_btn_clicked();

    //void scshot();

    //void do_error();

    void on_vlm_btn_clicked();

    void processurl();

private:
    Ui::mainwindow *ui;
    QProcess *moveplayer;
    QProcess *rurl;
    bool Working;
    int now_row;
    bool new_begin;
    //QTimer *tm;
    int tm_id;
    int mouse_tm_id;
    int mouse_move_tm_id;
    bool isfull;
    bool ply_show;
    int ply_mode;
    bool dclicked;
    bool muted;
    bool sound_clk;
    int vlm_s;
    child *urldialog;
    QString fulltime;
    QFile *ply_lst;
    //QPalette *plt;
    QRect mainrect;
    QRect cenrect;
    QRect subrect;
};

#endif // MAINWINDOW_H
