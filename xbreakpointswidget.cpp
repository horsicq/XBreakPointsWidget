/* Copyright (c) 2022 hors<horsicq@gmail.com>
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
#include "xbreakpointswidget.h"
#include "ui_xbreakpointswidget.h"

XBreakPointsWidget::XBreakPointsWidget(QWidget *pParent) :
    XShortcutsWidget(pParent),
    ui(new Ui::XBreakPointsWidget)
{
    ui->setupUi(this);

    g_pXInfoDB=nullptr;
    g_pModel=nullptr;
    g_pOldModel=nullptr;
}

XBreakPointsWidget::~XBreakPointsWidget()
{
    delete ui;
}

void XBreakPointsWidget::setXInfoDB(XInfoDB *pXInfoDB,bool bReload)
{
    g_pXInfoDB=pXInfoDB;

    if(bReload)
    {
        reload();
    }
}

void XBreakPointsWidget::reload()
{
    if(g_pXInfoDB)
    {
        g_pOldModel=g_pModel;

        QList<XInfoDB::BREAKPOINT> *pListBreakpoints=g_pXInfoDB->getBreakpoints();

        qint32 nNumberOfRecords=pListBreakpoints->count();

        g_pModel=new QStandardItemModel(nNumberOfRecords,__HEADER_COLUMN_size);

        g_pModel->setHeaderData(HEADER_COLUMN_ADDRESS,Qt::Horizontal,tr("Address"));
        g_pModel->setHeaderData(HEADER_COLUMN_TYPE,Qt::Horizontal,tr("Type"));

        for(qint32 i=0;i<nNumberOfRecords;i++)
        {
            QStandardItem *pItemAddress=new QStandardItem;
            pItemAddress->setText(XBinary::valueToHexOS(pListBreakpoints->at(i).nAddress));
//            pItemAddress->setData(pListModules->at(i).nAddress,Qt::UserRole+USERROLE_ADDRESS);
//            pItemAddress->setData(pListModules->at(i).nSize,Qt::UserRole+USERROLE_SIZE);
            pItemAddress->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
            g_pModel->setItem(i,HEADER_COLUMN_ADDRESS,pItemAddress);

            QStandardItem *pItemType=new QStandardItem;
//            pItemType->setText("TODO");
            pItemType->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
            g_pModel->setItem(i,HEADER_COLUMN_TYPE,pItemType);
        }

        ui->tableViewBreakPoints->setModel(g_pModel);

        deleteOldStandardModel(&g_pOldModel);
    }
}
