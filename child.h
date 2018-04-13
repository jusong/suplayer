#ifndef CHILD_H
#define CHILD_H
#include <QDialog>


class QPushButton;
class QLineEdit;
class QLabel;

class child: public QDialog
{
    Q_OBJECT
public:
    child(QWidget *parent = 0);
    QLineEdit *url;

public slots:
    void enableOkButton(QString nm);

private:
    QLabel *label;
    QPushButton *ok;
};

#endif // CHILD_H
