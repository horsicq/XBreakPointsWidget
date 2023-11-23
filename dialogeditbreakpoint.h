#ifndef DIALOGEDITBREAKPOINT_H
#define DIALOGEDITBREAKPOINT_H

#include <QDialog>

namespace Ui {
class DialogEditBreakpoint;
}

class DialogEditBreakpoint : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditBreakpoint(QWidget *parent = nullptr);
    ~DialogEditBreakpoint();

private:
    Ui::DialogEditBreakpoint *ui;
};

#endif // DIALOGEDITBREAKPOINT_H
