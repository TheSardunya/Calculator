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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    QWidget *titleBar = new QWidget(this);
    titleBar->setStyleSheet("background-color: #2F2F38;");
    titleBar->setGeometry(0, 0, 350, 32);
    minBtn = new MouseCache(this);
    minBtn->setText("—");
    minBtn->setGeometry(350 - 64, 0, 28, 28);
    minBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    connect(minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(minBtn, SIGNAL(hovered()), this, SLOT(catchHoverMin()));
    connect(minBtn, SIGNAL(unhovered()), this, SLOT(catchUnHoverMin()));

    closeBtn = new MouseCache(this);
    closeBtn->setText("✕");
    closeBtn->setGeometry(350 - 32, 0, 28, 28);
    closeBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);
    connect(closeBtn, SIGNAL(hovered()), this, SLOT(catchHoverCls()));
    connect(closeBtn, SIGNAL(unhovered()), this, SLOT(catchUnHoverCls()));
    isPower = false;
    INPUT = "";
    ResultLab = new QLabel(this);
    ResultLab->setGeometry(15, 50, 320, 54);
    ResultLab->setStyleSheet("color: #DFDFDF; font-size: 48px; background-color: #30303F; border-radius: 8px;");
    btn1 = new QPushButton("1", this);
    btn2 = new QPushButton("2", this);
    btn3 = new QPushButton("3", this);
    btn4 = new QPushButton("4", this);
    btn5 = new QPushButton("5", this);
    btn6 = new QPushButton("6", this);
    btn7 = new QPushButton("7", this);
    btn8 = new QPushButton("8", this);
    btn9 = new QPushButton("9", this);
    btn0 = new QPushButton("0", this);
    btnRes = new QPushButton("=", this);
    btnAC = new QPushButton("AC", this);
    btnPlus = new QPushButton("+", this);
    btnCon = new QPushButton("-", this);
    btnDiv = new QPushButton("÷", this);
    btnMult = new QPushButton("×", this);
    btnOpnBrck = new QPushButton("(", this);
    btnClsBrck = new QPushButton(")", this);
    btnPwr = new QPushButton("xʸ", this);
    btnOpnBrck->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnClsBrck->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn1->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn2->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn3->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn4->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn5->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn6->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn7->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn8->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn9->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btn0->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnCon->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnPlus->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnDiv->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnMult->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnRes->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnAC->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnPwr->setStyleSheet("background-color: #20202F; color: #DADADA; border-radius: 6px;font-size: 24px;");
    btnPwr->setGeometry(260, 480, 70, 70);
    btnOpnBrck->setGeometry(100, 480, 70, 70);
    btnClsBrck->setGeometry(180, 480, 70, 70);
    btn0->setGeometry(20, 480, 70, 70);
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
    this->resize(350, 600);
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
    connect(btnRes, SIGNAL(clicked()), this, SLOT(addStrRes()));
    connect(btnAC, SIGNAL(clicked()), this, SLOT(addStrAC()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(addStrPlus()));
    connect(btnCon, SIGNAL(clicked()), this, SLOT(addStrCon()));
    connect(btnDiv, SIGNAL(clicked()), this, SLOT(addStrDiv()));
    connect(btnMult, SIGNAL(clicked()), this, SLOT(addStrMult()));
    connect(btnOpnBrck, SIGNAL(clicked()), this, SLOT(addStrOpnBrck()));
    connect(btnClsBrck, SIGNAL(clicked()), this, SLOT(addStrClsBrck()));
    connect(btnPwr, SIGNAL(clicked()), this, SLOT(addStrPwr()));
}

QString MainWindow::Calculate(QString RawInput)
{
    int firstopnum = 0, veryfirstopnum = 0, lastopnum = 0, opin = -1, startop = 0, endop = 0, next = 0, parannum = 0, innerparannum = 0, paranin = -1;
    QString AraInput = "";
    bool isParanEnded = true, abesod = true;
    for (int i = 0; i < RawInput.length(); i++)
    {
        if (RawInput[i] == '(' && isParanEnded)
        {
            opin = i;
            parannum++;
            isParanEnded = false;
        }
        else if(RawInput[i] == '(' && !isParanEnded)
        {
            innerparannum++;
        }
        else if (RawInput[i] == ')' && !isParanEnded && ((i + 1 < RawInput.length()) ? RawInput[i + 1] != ')' : true) && innerparannum == 0)
        {
            isParanEnded = true;
            paranin = i;
        }
        else if(RawInput[i] == ')' && !isParanEnded && innerparannum != 0)
        {
            innerparannum--;
        }
    }
    innerparannum = 0;
    for (int i = parannum; i > 0; i--)
    {
        QString IRawInput = "";
        bool inParan = false, isSingle = true;
        int startparan = -1, endparan = -1;
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '(' && !inParan)
            {
                startparan = x;
                inParan = true;
            }
            else if (RawInput[x] == ')' && x == paranin && inParan)
            {
                inParan = false;
                endparan = x;
                break;
            }
            else if (inParan)
            {
                IRawInput += RawInput[x];
            }
        }
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
        if (RawInput[i] == '*' || RawInput[i] == '/' || RawInput[i] == '!')
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
    }
    for (int i = veryfirstopnum; i > 0; i--)
    {
        QString sum = "";
        bool squareroot = false;
        for (int x = next; x < RawInput.length(); x++)
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
            }
            else if(x == startop && squareroot)
            {
                if(TryParse(sum)){AraInput += QString::number(sqrt(sum.toDouble()));}
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
        bool facto = false;
        QString sum = "";
        for (int x = next; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '*' || RawInput[x] == '/')
            {
                opin = x;
                break;
            }
            else if (RawInput[x] == '!')
            {
                opin = x;
                facto = true;
                break;
            }
        }
        for (int x = opin + 1; x < RawInput.length() && !facto; x++)
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
        if (facto)
        {
            endop = opin;
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
                for (int q = 0; q < sum.length() && !facto; q++)
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
                for (int q = 0; q < sum.length() - 1 && facto; q++)
                {
                    rawx += sum[q];
                }
                if (TryParse(rawx) && TryParse(rawy) && !facto)
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
                else if (TryParse(rawx) && facto)
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
    summary += "+";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrCon()
{
    INPUT += "-";
    QString summary = ResultLab->text();
    summary += "-";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrDiv()
{
    INPUT += "/";
    QString summary = ResultLab->text();
    summary += "÷";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrMult()
{
    INPUT += "*";
    QString summary = ResultLab->text();
    summary += "×";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrOpnBrck()
{
    INPUT += "(";
    QString summary = ResultLab->text();
    summary += "(";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrClsBrck()
{
    INPUT += ")";
    QString summary = ResultLab->text();
    summary += ")";
    ResultLab->setText(summary);
    isPower = false;
}
void MainWindow::addStrPwr()
{
    INPUT += "^";
    isPower = true;
}
void MainWindow::catchHoverMin()
{
    minBtn->setStyleSheet("background-color: #CACAD3;color: #DFDFDF; font-size: 18px; border: none;");
}
void MainWindow::catchUnHoverMin()
{
    minBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
}
void MainWindow::catchHoverCls()
{
    closeBtn->setStyleSheet("background-color: #CACAD3;color: #DFDFDF; font-size: 18px; border: none;");
}
void MainWindow::catchUnHoverCls()
{
    closeBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
}
