#include "child.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

child::child(QWidget *parent):QDialog(parent)
{
    label = new QLabel(tr("URL: "));
    url = new QLineEdit;
    ok = new QPushButton(tr("&Ok"));

    label->setBuddy(url);

    ok->setDefault(true);
    ok->setEnabled(false);

    connect(url, SIGNAL(textChanged(QString)), this, SLOT(enableOkButton(QString)));
    connect(ok, SIGNAL(clicked()), parent, SLOT(seturl()));

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(label);
    layout->addWidget(url);
    layout->addWidget(ok);

    setLayout(layout);

    setWindowTitle(tr("URL"));
    setFixedHeight(sizeHint().height());
}

void child::enableOkButton(QString nm)
{
    ok->setEnabled(!nm.isEmpty());
}
