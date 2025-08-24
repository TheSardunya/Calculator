#include "mainwindow.h"
#include "oreno.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <cmath>
#include <sstream>
#include <QBoxLayout>
#include "MouseCache.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QPointF>
QPointF dragPos;
bool opnPwrBr = false, isDraggin = false;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isDraggin = true;
        dragPos = event->globalPosition() - frameGeometry().topLeft();
        event->accept();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isDraggin)
    {
        MainWindow::move(event->globalPosition().toPoint() - dragPos.toPoint());
        event->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isDraggin = false;
}
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFocus();
    setFocusPolicy(Qt::StrongFocus);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QWidget *titleBar = new QWidget(this);
    titleBar->setStyleSheet("background-color: #2F2F38;");
    titleBar->setGeometry(0, 0, 350, 32);
    minBtn = new MouseCache(this);
    minBtn->setText("—");
    minBtn->setGeometry(350 - 64, 0, 28, 28);
    minBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    connect(minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);

    closeBtn = new MouseCache(this);
    closeBtn->setText("✕");
    closeBtn->setGeometry(350 - 32, 0, 28, 28);
    closeBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);
    isPower = false;
    INPUT = "";
    ResultLab = new QLabel(this);
    ResultLab->setGeometry(15, 50, 320, 54);
    ResultLab->setStyleSheet("color: #DFDFDF; font-size: 32px; background-color: #30303F; border-radius: 8px;");
    btnDel = new MouseCache(this);
    btn1 = new MouseCache(this);
    btn2 = new MouseCache(this);
    btn3 = new MouseCache(this);
    btn4 = new MouseCache(this);
    btn5 = new MouseCache(this);
    btn6 = new MouseCache(this);
    btn7 = new MouseCache(this);
    btn8 = new MouseCache(this);
    btn9 = new MouseCache(this);
    btn0 = new MouseCache(this);
    btnSqrt = new MouseCache(this);
    btnFact = new MouseCache(this);
    btnRes = new MouseCache(this);
    btnAC = new MouseCache(this);
    btnPlus = new MouseCache(this);
    btnCon = new MouseCache(this);
    btnDiv = new MouseCache(this);
    btnMult = new MouseCache(this);
    btnOpnBrck = new MouseCache(this);
    btnClsBrck = new MouseCache(this);
    btnPwr = new MouseCache(this);
    btnDel->setText("DEL");
    btn1->setText("1");
    btn2->setText("2");
    btn3->setText("3");
    btn4->setText("4");
    btn5->setText("5");
    btn6->setText("6");
    btn7->setText("7");
    btn8->setText("8");
    btn9->setText("9");
    btn0->setText("0");
    btnPlus->setText("+");
    btnCon->setText("-");
    btnDiv->setText("÷");
    btnMult->setText("×");
    btnRes->setText("=");
    btnOpnBrck->setText("(");
    btnClsBrck->setText(")");
    btnPwr->setText("xʸ");
    btnSqrt->setText("√");
    btnFact->setText("!");
    btnAC->setText("AC");
    btnOpnBrck->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnDel->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnClsBrck->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn1->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnDel->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnDel->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn1->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn1->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn1->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn2->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn3->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn4->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn5->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn6->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn7->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn8->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn9->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn0->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnPlus->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnDiv->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnAC->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnMult->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnCon->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnRes->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 32px;";
    btnPwr->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnOpnBrck->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnClsBrck->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnSqrt->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnDel->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btnFact->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn1->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn1->cssClick = "background-color: #4A4A51; color: #DADADA; border-radius: 35px; font-size: 24px;";
    btn2->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn2->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn3->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn3->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn4->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn4->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn5->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn5->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn6->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn6->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn7->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn7->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn8->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn8->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn9->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn9->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn0->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn0->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnPlus->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnPlus->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnDiv->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnDiv->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnMult->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnMult->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnCon->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnCon->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnSqrt->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnSqrt->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnFact->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnFact->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnOpnBrck->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnOpnBrck->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnClsBrck->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnClsBrck->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnRes->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 32px;";
    btnRes->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 32px;";
    btnPwr->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnPwr->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnAC->cssUnHvr = "background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btnAC->cssHvr = "background-color: #333341; color: #DADADA; border-radius: 35px;font-size: 24px;";
    btn2->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn3->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn4->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn5->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn6->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn7->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn8->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn9->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btn0->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnSqrt->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnFact->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnCon->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnPlus->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnDiv->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnMult->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnRes->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 32px;");
    btnAC->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnPwr->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 35px;font-size: 24px;");
    btnPwr->setGeometry(180, 480, 70, 70);
    btnDel->setGeometry(260, 480, 70, 70);
    btnOpnBrck->setGeometry(180, 560, 70, 70);
    btnClsBrck->setGeometry(260, 560, 70, 70);
    btn0->setGeometry(20, 480, 150, 70);
    btnSqrt->setGeometry(20, 560, 70, 70);
    btnFact->setGeometry(100, 560, 70, 70);
    btnPlus->setGeometry(20, 160, 70, 70);
    btnCon->setGeometry(100, 160, 70, 70);
    btnDiv->setGeometry(180, 160, 70, 70);
    btnMult->setGeometry(260, 160, 70, 70);
    btn1->setGeometry(20, 400, 70, 70);
    btn2->setGeometry(100, 400, 70, 70);
    btn3->setGeometry(180, 400, 70, 70);
    btnAC->setGeometry(260, 400, 70, 70);
    btnRes->setGeometry(260, 240, 70, 150);
    btn4->setGeometry(20, 320, 70, 70);
    btn5->setGeometry(100, 320, 70, 70);
    btn6->setGeometry(180, 320, 70, 70);
    btn7->setGeometry(20, 240, 70, 70);
    btn8->setGeometry(100, 240, 70, 70);
    btn9->setGeometry(180, 240, 70, 70);
    this->setWindowTitle("Calculator");
    this->resize(350, 680);
    this->setStyleSheet("background-color: #101018");
    this->setWindowIcon(QIcon(":/icons/calculator.ico"));
    connect(btn0, SIGNAL(clicked()), this, SLOT(addStr0()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(addStr1()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(addStr2()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(addStr3()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(addStr4()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(addStr5()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(addStr6()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(addStr7()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(addStr8()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(addStr9()));
    connect(btnSqrt, SIGNAL(clicked()), this, SLOT(addStrSqrt()));
    connect(btnFact, SIGNAL(clicked()), this, SLOT(addStrFact()));
    connect(btnRes, SIGNAL(clicked()), this, SLOT(addStrRes()));
    connect(btnAC, SIGNAL(clicked()), this, SLOT(addStrAC()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(addStrPlus()));
    connect(btnCon, SIGNAL(clicked()), this, SLOT(addStrCon()));
    connect(btnDiv, SIGNAL(clicked()), this, SLOT(addStrDiv()));
    connect(btnMult, SIGNAL(clicked()), this, SLOT(addStrMult()));
    connect(btnOpnBrck, SIGNAL(clicked()), this, SLOT(addStrOpnBrck()));
    connect(btnClsBrck, SIGNAL(clicked()), this, SLOT(addStrClsBrck()));
    connect(btnPwr, SIGNAL(clicked()), this, SLOT(addStrPwr()));
    connect(btnDel, SIGNAL(clicked()), this, SLOT(delStr()));
}
QString MainWindow::Calculate(QString RawInput)
{
    QMessageBox warnParse;
    warnParse.setText("Syntax error");
    warnParse.setWindowTitle("Error");
    int functopnum = 0, firstopnum = 0, veryfirstopnum = 0, lastopnum = 0, opin = -1, startop = 0, endop = 0, next = 0, parannum = 0, innerparannum = 0, paranin = -1;
    QString AraInput = "";
    bool startBabo = false, abesod = true;
    for (int i = 0; i < RawInput.length(); i++)
    {
        if(RawInput[i] == '(' && innerparannum == 0){parannum++; innerparannum++;}
        else if(RawInput[i] == ')' && innerparannum > 0)
        {
            innerparannum--;
        }
        else if(RawInput[i] == '(' && innerparannum > 0){innerparannum++;}
    }
    if(innerparannum != 0){warnParse.exec();RawInput = "";}
    for (int i = parannum; i > 0; i--)
    {
        QString IRawInput = "";
        bool inParan = false, isSingle = true;
        int startparan = -1, endparan = -1;
        innerparannum = 0;
        for (int x = 0; x < RawInput.length(); x++)
        {
            if(RawInput[x] == '(' && innerparannum == 0){startBabo = true; innerparannum++; startparan = x;}
            else if(RawInput[x] == ')' && innerparannum > 0)
            {
                innerparannum--;
                if(RawInput[x] == ')' && innerparannum == 0)
                {
                    innerparannum--;
                    endparan = x;
                    startBabo = false;
                    break;
                }
            }
            else if(RawInput[x] == '(' && innerparannum > 0){innerparannum++;}
            if(startBabo && startparan != x){IRawInput += RawInput[x];}
        }
        innerparannum = 0;
        for (int x = 0; x < IRawInput.length(); x++)
        {
            if (IRawInput[x] == '+' || IRawInput[x] == '/' || IRawInput[x] == '*' || IRawInput[x] == '^' || (IRawInput[x] == '-' && x != 0))
            {
                isSingle = false;
            }
        }
        if (isSingle)
        {
            if (IRawInput.length() > 0 && IRawInput[0] == '-')
            {
                IRawInput[0] = '0';
            }
            if (AraInput.length() > 0 && AraInput[AraInput.length() - 1] == '!')
            {
                QString zap = "";
                for (int i = 0; i < IRawInput.length() - 1; i++)
                {
                    zap += IRawInput[i];
                }
                if (TryParse(zap))
                {
                    int ap = zap.toInt();
                    for (int x = ap - 1; x > 1; x--)
                    {
                        ap *= x;
                    }
                    IRawInput = QString::number(ap);
                }
                else{warnParse.exec(); RawInput = ""; AraInput = "";}
            }
            for (int x = 0; x < RawInput.length(); x++)
            {
                if (x < startparan || x > endparan)
                {
                    AraInput += RawInput[x];
                }
                else if (x == startparan)
                {
                    AraInput += IRawInput;
                }
            }
            RawInput = AraInput;
            AraInput = "";
        }
        else
        {
            for(int x = 0; x < RawInput.length(); x++)
            {
                if(x < startparan || x > endparan)
                {
                    AraInput += RawInput[x];
                }
                else if(x == startparan)
                {
                    AraInput += Calculate(IRawInput);
                }
            }
            RawInput = AraInput;
            AraInput = "";
        }
    }
    for (int i = 0; i < RawInput.length(); i++)
    {
        if (RawInput[i] == '*' || RawInput[i] == '/')
        {
            opin = i;
            firstopnum++;
        }
        else if (RawInput[i] == '+' || (RawInput[i] == '-' && i != 0 && i != opin + 1))
        {
            opin = i;
            lastopnum++;
        }
        else if (RawInput[i] == '^' || RawInput[i] == 'v')
        {
            opin = i;
            veryfirstopnum++;
        }
        else if(RawInput[i] == '!')
        {
            functopnum++;
            opin = i;
        }
    }
    for(int i = functopnum; i > 0; i--)
    {
        bool facto = false;
        QString sum = "";
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '!')
            {
                opin = x;
                facto = true;
                break;
            }
        }
        if (facto)
        {
            endop = opin;
        }
        for (int x = opin - 1; x >= 0; x--)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '^' || RawInput[x] == '*' || RawInput[x] == '-' && x > 0)
            {
                if(RawInput[x - 1] != '-')
                {
                    startop = x + 1;
                    break;
                }
            }
            else if(x == 0){startop = 0;}

        }
        for (int x = startop; x < endop; x++)
        {
            sum += RawInput[x];
        }

        for (int x = 0; x < RawInput.length(); x++)
        {
            if (x < startop || x > endop)
            {
                AraInput += RawInput[x];
            }
            else if (x == startop)
            {
                double a, b;
                QString rawx = "", rawy = "";
                QChar op;
                bool xturn = true;
                rawx = sum;
                if (TryParse(rawx) && facto)
                {
                    int sumFact = rawx.toInt();
                    if (sumFact < 0) sumFact = 0;
                    int res = 1;
                    for (int v = sumFact; v > 1; v--)
                    {
                        res *= v;
                    }
                    AraInput += QString::number(res);
                }
                else{warnParse.exec(); RawInput = ""; AraInput = "";}
            }
        }
        RawInput = AraInput;
        AraInput = "";
        sum = "";
        endop = 0;
        startop = 0;
        opin = 0;
    }
    opin = 0;
    AraInput = "";
    for (int i = veryfirstopnum; i > 0; i--)
    {
        QString sum = "";
        bool squareroot = false;
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '^' || RawInput[x] == 'v')
            {
                if(RawInput[x] == 'v'){squareroot = true;}
                opin = x;
                break;
            }
        }
        for (int x = opin + 1; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '^' || (RawInput[x] == '-' && x != opin + 1))
            {
                endop = x - 1;
                break;
            }
            else if (x == RawInput.length() - 1)
            {
                endop = x;
                break;
            }
        }
        for (int x = opin - 1; x >= 0 && !squareroot; x--)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || (RawInput[x] == '-' && x > 0 && RawInput[x - 1] != '-' && x != 0))
            {
                startop = x + 1;
                break;
            }
            else if (x == 0)
            {
                startop = x;
                break;
            }
        }
        if(squareroot){startop = opin;}
        for (int x = startop; x <= endop && !squareroot; x++)
        {
            sum += RawInput[x];
        }
        for(int x = startop + 1; x <= endop && squareroot; x++)
        {
            sum += RawInput[x];
        }
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (x < startop || x > endop)
            {
                AraInput += RawInput[x];
            }
            else if (x == startop && !squareroot)
            {
                double a, b;
                QString rawx, rawy;
                QChar op;
                bool xturn = true;
                for (int q = 0; q < sum.length(); q++)
                {
                    if (sum[q] == '^')
                    {
                        op = sum[q];
                        xturn = false;
                    }
                    else if (xturn)
                    {
                        rawx += sum[q];
                    }
                    else
                    {
                        rawy += sum[q];
                    }
                }
                if (TryParse(rawx) && TryParse(rawy))
                {
                    bool xparanted = false, yparanted = false;
                    if (rawx.length() > 1 && rawx[0] == '0' && rawx != "0" && rawx[1] != '.' && rawx[1] != ',')
                    {
                        rawx[0] = '-';
                    }
                    if (rawy.length() > 1 && rawy[0] == '0' && rawy != "0" && rawy[1] != '.' && rawy[1] != ',')
                    {
                        rawy[0] = '-';
                    }
                    a = rawx.toDouble();
                    b = rawy.toDouble();
                    if (b < 0)
                    {
                        double sumch = a;
                        for (int z = abs(b) - 1; z > 0; z--)
                        {
                            sumch *= a;
                        }
                        AraInput += QString::number(1 / sumch);
                    }
                    else if (b > 0)
                    {
                        double sumch = a;
                        for (int z = b - 1; z > 0; z--)
                        {
                            sumch *= a;
                        }
                        AraInput += QString::number(sumch);
                    }
                    else
                    {
                        AraInput += "1";
                    }
                }
                else{warnParse.exec(); RawInput = ""; AraInput = "";}
            }
            else if(x == startop && squareroot)
            {
                if(TryParse(sum)){AraInput += QString::number(sqrt(sum.toDouble()));}
                else{warnParse.exec(); RawInput = ""; AraInput = "";}
            }
        }
        RawInput = AraInput;
        AraInput = "";
        sum = "";
        next = 0;
        endop = 0;
        startop = 0;
        opin = 0;
    }
    next = 0;
    opin = 0;
    AraInput = "";
    for (int i = firstopnum; i > 0; i--)
    {
        QString sum = "";
        for (int x = next; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '*' || RawInput[x] == '/')
            {
                opin = x;
                break;
            }
        }
        for (int x = opin + 1; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || (RawInput[x] == '-' && x != opin + 1))
            {
                endop = x - 1;
                break;
            }
            else if (x == RawInput.length() - 1)
            {
                endop = x;
                break;
            }
        }
        for (int x = opin - 1; x >= 0; x--)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || RawInput[x] == '-' && x > 0)
            {
                if(RawInput[x - 1] != '-')
                {
                    startop = x + 1;
                    break;
                }
            }
            else if(x == 0){startop = 0;}
        }
        for (int x = startop; x <= endop; x++)
        {
            sum += RawInput[x];
        }
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (x < startop || x > endop)
            {
                AraInput += RawInput[x];
            }
            else if (x == startop)
            {
                double a, b;
                QString rawx = "", rawy = "";
                QChar op;
                bool xturn = true;
                for (int q = 0; q < sum.length(); q++)
                {
                    if (sum[q] == '*' || sum[q] == '/')
                    {
                        op = sum[q];
                        xturn = false;
                    }
                    else if (xturn)
                    {
                        rawx += sum[q];
                    }
                    else
                    {
                        rawy += sum[q];
                    }
                }

                if (TryParse(rawx) && TryParse(rawy))
                {
                    if (rawx.length() > 1 && rawx[0] == '0' && rawx != "0" && rawx[1] != '.' && rawx[1] != ',')
                    {
                        rawx[0] = '-';
                    }
                    if (rawy.length() > 1 && rawy[0] == '0' && rawy != "0" && rawy[1] != '.' && rawy[1] != ',')
                    {
                        rawy[0] = '-';
                    }
                    a = rawx.toDouble();
                    b = rawy.toDouble();
                    if (op == '*')
                    {
                        double resultD = a * b;
                        std::stringstream ss;
                        ss << resultD;
                        AraInput += QString::fromStdString(ss.str());
                        int absfg = 0;
                    }
                    else
                    {
                        double resultD = a / b;
                        std::stringstream ss;
                        ss << resultD;
                        AraInput += QString::fromStdString(ss.str());
                        int absfg = 0;
                    }
                }
                else{warnParse.exec(); RawInput = ""; AraInput = "";}
            }
        }
        RawInput = AraInput;
        AraInput = "";
        sum = "";
        next = 0;
        endop = 0;
        startop = 0;
        opin = 0;
    }
    next = 0;
    opin = 0;
    for (int i = lastopnum; i > 0; i--)
    {
        QString sum = "";
        for (int x = next; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '+' || (RawInput[x] == '-' && x != next))
            {
                opin = x;
                break;
            }
        }
        for (int x = opin + 1; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || (RawInput[x] == '-' && x != opin + 1))
            {
                endop = x - 1;
                break;
            }
            else if (x == RawInput.length() - 1)
            {
                endop = x;
                break;
            }
        }
        for (int x = opin - 1; x >= 0; x--)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '*' || (RawInput[x] == '-' && x > 0 && RawInput[x - 1] != '-' && x != 0))
            {
                startop = x + 1;
                break;
            }
        }
        for (int x = startop; x <= endop; x++)
        {
            sum += RawInput[x];
        }
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (x < startop || x > endop)
            {
                AraInput += RawInput[x];
            }
            else if (x == startop)
            {
                double a, b;
                QString rawx, rawy;
                QChar op;
                bool xturn = true;
                for (int q = 0; q < sum.length(); q++)
                {
                    if (sum[q] == '+' || (sum[q] == '-' && q != 0 && (q > 0 ? sum[q - 1] != '-' : true)))
                    {
                        op = sum[q];
                        xturn = false;
                    }
                    else if (xturn)
                    {
                        rawx += sum[q];
                    }
                    else
                    {
                        rawy += sum[q];
                    }
                }
                if (TryParse(rawx) && TryParse(rawy))
                {
                    if (rawx.length() > 1 && rawx[0] == '0' && rawx != "0" && rawx[1] != '.' && rawx[1] != ',')
                    {
                        rawx[0] = '-';
                    }
                    if (rawy.length() > 1 && rawy[0] == '0' && rawy != "0" && rawy[1] != '.' && rawy[1] != ',')
                    {
                        rawy[0] = '-';
                    }
                    a = rawx.toDouble();
                    b = rawy.toDouble();
                    if (op == '+')
                    {
                        AraInput += QString::number(a + b);
                    }
                    else
                    {
                        AraInput += QString::number(a - b);
                    }
                }
                else{warnParse.exec();}
            }
        }
        RawInput = AraInput;
        AraInput = "";
        sum = "";
        next = 0;
        endop = 0;
        startop = 0;
        opin = 0;
    }
    return RawInput;
}

void MainWindow::StringSet()
{

}
void MainWindow::addStr1()
{
    INPUT += "1";
    QString summary = ResultLab->text();
    summary += isPower ? "¹" : "1";
    ResultLab->setText(summary);
}
void MainWindow::addStr2()
{
    INPUT += "2";
    QString summary = ResultLab->text();
    summary += isPower ? "²" : "2";
    ResultLab->setText(summary);
}
void MainWindow::addStr3()
{
    INPUT += "3";
    QString summary = ResultLab->text();
    summary += isPower ? "³" : "3";
    ResultLab->setText(summary);
}
void MainWindow::addStr4()
{
    INPUT += "4";
    QString summary = ResultLab->text();
    summary += isPower ? "⁴" : "4";
    ResultLab->setText(summary);
}
void MainWindow::addStr5()
{
    INPUT += "5";
    QString summary = ResultLab->text();
    summary += isPower ? "⁵" : "5";
    ResultLab->setText(summary);
}
void MainWindow::addStr6()
{
    INPUT += "6";
    QString summary = ResultLab->text();
    summary += isPower ? "⁶" : "6";
    ResultLab->setText(summary);
}
void MainWindow::addStr7()
{
    INPUT += "7";
    QString summary = ResultLab->text();
    summary += isPower ? "⁷" : "7";
    ResultLab->setText(summary);
}
void MainWindow::addStr8()
{
    INPUT += "8";
    QString summary = ResultLab->text();
    summary += isPower ? "⁸" : "8";
    ResultLab->setText(summary);
}
void MainWindow::addStr9()
{
    INPUT += "9";
    QString summary = ResultLab->text();
    summary += isPower ? "⁹" : "9";
    ResultLab->setText(summary);
}
void MainWindow::addStr0()
{
    INPUT += "0";
    QString summary = ResultLab->text();
    summary += isPower ? "⁰" : "0";
    ResultLab->setText(summary);
}
void MainWindow::addStrRes()
{
    QString summary = Calculate(INPUT);
    ResultLab->setText(summary);
    INPUT = summary;
    isPower = false;
}
void MainWindow::addStrAC()
{
    INPUT = "";
    QString summary = "";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrPlus()
{
    INPUT += "+";
    QString summary = ResultLab->text();
    summary += opnPwrBr ? "<sup>+</sup>" : "+";
    ResultLab->setText(summary);
    isPower = opnPwrBr ? true : false;
}
void MainWindow::addStrCon()
{
    INPUT += "-";
    QString summary = ResultLab->text();
    summary += isPower ? "⁻" : "-";
    if(INPUT[INPUT.length() - 2] != '^' && !opnPwrBr){isPower = false; summary[summary.length() - 1] = '-';}
    ResultLab->setText(summary);
}
void MainWindow::addStrDiv()
{
    INPUT += "/";
    QString summary = ResultLab->text();
    summary += opnPwrBr ? "<sup>÷</sup>" : "÷";
    ResultLab->setText(summary);
    isPower = opnPwrBr ? true : false;
}
void MainWindow::addStrMult()
{
    INPUT += "*";
    QString summary = ResultLab->text();
    summary += opnPwrBr ? "<sup>×</sup>" : "×";
    ResultLab->setText(summary);
    isPower = opnPwrBr ? true : false;
}
void MainWindow::addStrOpnBrck()
{
    INPUT += "(";
    QString summary = ResultLab->text();
    summary += isPower ? "⁽" : "(";
    opnPwrBr = isPower ? true : false;
    ResultLab->setText(summary);
    isPower = opnPwrBr ? true : false;
}
void MainWindow::addStrClsBrck()
{
    INPUT += ")";
    QString summary = ResultLab->text();
    summary += opnPwrBr ? "⁾" : ")";
    opnPwrBr = false;
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrSqrt()
{
    INPUT += "v";
    QString summary = ResultLab->text();
    summary += "√";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrFact()
{
    INPUT += "!";
    QString summary = ResultLab->text();
    summary += isPower ? "<sup>!</sup>" : "!";
    ResultLab->setText(summary);
    isPower = opnPwrBr ? true : false;
}
void MainWindow::addStrPwr()
{
    INPUT += "^";
    isPower = true;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->text().isEmpty())
    {
        if(event->text() == "^"){addStrPwr();}
        else if(event->text() == "1"){addStr1();}
        else if(event->text() == "2"){addStr2();}
        else if(event->text() == "3"){addStr3();}
        else if(event->text() == "4"){addStr4();}
        else if(event->text() == "5"){addStr5();}
        else if(event->text() == "6"){addStr6();}
        else if(event->text() == "7"){addStr7();}
        else if(event->text() == "8"){addStr8();}
        else if(event->text() == "9"){addStr9();}
        else if(event->text() == "0"){addStr0();}
        else if(event->text() == "("){addStrOpnBrck();}
        else if(event->text() == ")"){addStrClsBrck();}
        else if(event->text() == "/"){addStrDiv();}
        else if(event->text() == "+"){addStrPlus();}
        else if(event->text() == "-"){addStrCon();}
        else if(event->text() == "*"){addStrMult();}
        else if(event->text() == "!"){addStrFact();}
        else if(event->text() == "√"){addStrSqrt();}
    }
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        addStrRes();
    }
    if(event->key() == Qt::Key_Backspace){addStrAC();}
}
void MainWindow::delStr()
{
    if(INPUT != "")
    {
        QString sum = "";
        for(int i = 0; i < INPUT.length() - 1; i++)
        {
            sum += INPUT[i];
        }
        INPUT = sum;
        sum = "";
        if(INPUT[INPUT.length() - 1] == '^')
        {
            for(int i = 0; i < INPUT.length() - 1; i++)
            {
                sum += INPUT[i];
            }
            INPUT = sum;
        }
        sum = "";
        for(int i = 0; i < ResultLab->text().length() - 1; i++)
        {
            sum += ResultLab->text()[i];
        }
        ResultLab->setText(sum);
    }
}
