#include "dialogeditbreakpoint.h"
#include "ui_dialogeditbreakpoint.h"

DialogEditBreakpoint::DialogEditBreakpoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditBreakpoint)
{
    ui->setupUi(this);
}

DialogEditBreakpoint::~DialogEditBreakpoint()
{
    delete ui;
}
