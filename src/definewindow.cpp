#include "definewindow.h"
#include "oreno.h"
#include "mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QCloseEvent>
#include "MouseCache.h"
#include <QPoint>
#include <fstream>
#include <QPointF>
#include <QMessageBox>
#include <sstream>
bool isdraggin = false;
QPointF dragpos;
QString Calculate(QString RawInput)
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
        else if (RawInput[i] == '^')
        {
            opin = i;
            veryfirstopnum++;
        }
        else if(RawInput[i] == '!' || RawInput[i] == 'v')
        {
            functopnum++;
            opin = i;
        }
    }
    for(int i = functopnum; i > 0; i--)
    {
        bool facto = false, square = false;
        QString sum = "";
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '!')
            {
                opin = x;
                facto = true;
                break;
            }
            else if (RawInput[x] == 'v'){opin = x; square = true; break;}
        }
        if (facto)
        {
            endop = opin;
        }
        else if(square){startop = opin;}
        for (int x = opin - 1; x >= 0 && facto; x--)
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
        for (int x = opin + 1; x < RawInput.length() && square; x++)
        {
            if (RawInput[x] == '+' || RawInput[x] == '/' || RawInput[x] == '^' || RawInput[x] == '*' || RawInput[x] == '-' && x > 0)
            {
                if(RawInput[x + 1] != '-')
                {
                    endop = x - 1;
                    break;
                }
            }
            else if(x == RawInput.length() - 1){endop = RawInput.length() - 1;}
        }

        for (int x = startop; x < endop && facto; x++)
        {
            sum += RawInput[x];
        }
        for (int x = startop + 1; x <= endop && square; x++){sum += RawInput[x];}
        for (int x = 0; x < RawInput.length() && facto; x++)
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
        for (int x = 0; x < RawInput.length() && square; x++)
        {
            if (x < startop || x > endop)
            {
                AraInput += RawInput[x];
            }
            else if (x == startop)
            {
                QString rawx = sum;
                QString output = QString::number(x);
                if(TryParse(rawx)){double x = rawx.toDouble();x = sqrt(x);AraInput += QString::number(x);}
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
        for (int x = 0; x < RawInput.length(); x++)
        {
            if (RawInput[x] == '^')
            {
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
        for (int x = opin - 1; x >= 0; x--)
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
                        xparanted = true;
                    }
                    if (rawy.length() > 1 && rawy[0] == '0' && rawy != "0" && rawy[1] != '.' && rawy[1] != ',')
                    {
                        rawy[0] = '-';
                    }
                    a = rawx.toDouble();
                    b = rawy.toDouble();
                    if(!xparanted && a < 0){double resultD = pow(a,b);if(resultD > 0){resultD = 0 - resultD;};AraInput += QString::number(resultD);}
                    else{AraInput += QString::number(pow(a, b));}
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


void DefineWindow::exitDef(){
    QMessageBox *dfWarn;
    dfWarn = new QMessageBox(this);
    dfWarn->setText("Error : cannot open or create defines.txt");
    dfWarn->setWindowTitle("Error");
    std::string newLine = "\n";
    std::string allDefs = Calculate(QString::fromStdString(clean_white_space(xLine->text().toStdString()))).toStdString() + newLine + Calculate(QString::fromStdString(clean_white_space(yLine->text().toStdString()))).toStdString()+ newLine + Calculate(QString::fromStdString(clean_white_space(zLine->text().toStdString()))).toStdString();
    std::ofstream OutStream;
    OutStream.open("defines.txt");
    if(OutStream){OutStream.write(allDefs.c_str(), allDefs.length());}
    else{dfWarn->exec();}
    OutStream.close();
}
void DefineWindow::closeEvent(QCloseEvent *event){
    exitDef();
    event->accept();
}
void DefineWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){isdraggin = true;dragpos = event->globalPosition() - frameGeometry().topLeft();}
    event->accept();
}
void DefineWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){isdraggin = false;}
    event->accept();
}
void DefineWindow::mouseMoveEvent(QMouseEvent *event){
    if(isdraggin){
        DefineWindow::move(event->globalPosition().toPoint() - dragpos.toPoint());
    }
    event->accept();
}
DefineWindow::DefineWindow(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(300, 300);
    this->setStyleSheet("background-color: #101018");
    xLb = new QLabel(this);
    yLb = new QLabel(this);
    zLb = new QLabel(this);
    xLine = new QLineEdit(this);
    yLine = new QLineEdit(this);
    zLine = new QLineEdit(this);
    QWidget *titlebar = new QWidget(this);
    std::ifstream InStream;
    InStream.open("defines.txt");
    std::string a = "";
    int i = 0;
    while(InStream && InStream >> a){
        i++;
        if(i == 1){
            xLine->setText(QString::fromStdString(a));
        }
        else if(i == 2){
            yLine->setText(QString::fromStdString(a));
        }
        else{
            zLine->setText(QString::fromStdString(a));
        }
    }
    titlebar->setStyleSheet("background-color: #2F2F38");
    titlebar->setGeometry(0,0,300,32);
    xLb->setGeometry(50, 80, 60, 32);
    xLb->setStyleSheet("font-size: 28px;");
    xLb->setText("𝑥 =");
    xLine->setGeometry(100, 80, 140, 32);
    xLine->setStyleSheet("background-color: #20202F");
    yLb->setGeometry(50, 160, 60, 32);
    yLb->setStyleSheet("font-size: 28px;");
    yLb->setText("𝑦 =");
    yLine->setGeometry(100, 160, 140, 32);
    yLine->setStyleSheet("background-color: #20202F");
    zLb->setGeometry(50, 240, 60, 32);
    zLb->setStyleSheet("font-size: 28px;");
    zLb->setText("𝑧 =");
    zLine->setGeometry(100, 240, 140, 32);
    zLine->setStyleSheet("background-color: #20202F");
    minBtn = new MouseCache(this);
    minBtn->setText("—");
    minBtn->setGeometry(300 - 64, 0, 28, 28);
    minBtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    closebtn = new MouseCache(this);
    closebtn->setText("✕");
    closebtn->setGeometry(300 - 32, 0, 28, 28);
    closebtn->setStyleSheet("background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;");
    connect(minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(closebtn, SIGNAL(clicked()), this, SLOT(close()));
    InStream.close();
}
DefineWindow::~DefineWindow(){}
