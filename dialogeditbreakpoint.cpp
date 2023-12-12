/* Copyright (c) 2022-2023 hors<horsicq@gmail.com>
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
#include "dialogeditbreakpoint.h"
#include "ui_dialogeditbreakpoint.h"

DialogEditBreakpoint::DialogEditBreakpoint(QWidget *pParent) : QDialog(pParent), ui(new Ui::DialogEditBreakpoint)
{
    ui->setupUi(this);
}

DialogEditBreakpoint::~DialogEditBreakpoint()
{
    delete ui;
}

void DialogEditBreakpoint::setData(XInfoDB::BREAKPOINT breakPoint)
{
    // mb TODO executable/Memory
    g_breakPoint = breakPoint;

    ui->comboBoxType->blockSignals(true);

    if (breakPoint.bpMode == XInfoDB::BPM_EXECUTE) {
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INT1);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INT3);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_HLT);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_CLI);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_STI);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INSB);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INSD);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_OUTSB);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_OUTSD);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INT1LONG);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_INT3LONG);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_UD0);
        _addItem(XInfoDB::BPT_CODE_SOFTWARE_UD2);
    }

    ui->comboBoxType->blockSignals(false);
}

XInfoDB::BREAKPOINT DialogEditBreakpoint::getBreakpoint()
{
    return g_breakPoint;
}

void DialogEditBreakpoint::_addItem(XInfoDB::BPT breakpointType)
{
    ui->comboBoxType->addItem(XInfoDB::bptToString(breakpointType), breakpointType);
}

void DialogEditBreakpoint::on_pushButtonCancel_clicked()
{
    reject();
}

void DialogEditBreakpoint::on_pushButtonOK_clicked()
{
    g_breakPoint.bpType = (XInfoDB::BPT)(ui->comboBoxType->currentData().toULongLong());

    accept();
}

