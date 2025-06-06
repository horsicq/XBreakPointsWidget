/* Copyright (c) 2022-2025 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef XBREAKPOINTSWIDGET_H
#define XBREAKPOINTSWIDGET_H

#include <QStandardItemModel>

#include "xinfodb.h"
#include "xshortcutswidget.h"

namespace Ui {
class XBreakPointsWidget;
}

class XBreakPointsWidget : public XShortcutsWidget {
    Q_OBJECT

    enum HEADER_COLUMN {
        HEADER_COLUMN_ADDRESS = 0,
        HEADER_COLUMN_SIZE,
        HEADER_COLUMN_THREAD,
        HEADER_COLUMN_TYPE,
        HEADER_COLUMN_INFO,
        HEADER_COLUMN_ONESHOT,
        HEADER_COLUMN_NOTE,
        __HEADER_COLUMN_size
    };

public:
    explicit XBreakPointsWidget(QWidget *pParent = nullptr);
    ~XBreakPointsWidget();

    void setXInfoDB(XInfoDB *pXInfoDB, bool bReload = true);
    void reload();

    virtual void adjustView()
    {
    }

private slots:
    void on_tableViewBreakPoints_customContextMenuRequested(const QPoint &pos);

protected:
    virtual void registerShortcuts(bool bState)
    {
        Q_UNUSED(bState)
    }

private:
    Ui::XBreakPointsWidget *ui;
    XInfoDB *g_pXInfoDB;
    QStandardItemModel *g_pModel;
};

#endif  // XBREAKPOINTSWIDGET_H
