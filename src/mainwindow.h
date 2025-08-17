#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>
#include <QMainWindow>
#include <QLabel>
#include "MouseCache.h"
#include <QPushButton>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private slots:
    void StringSet();
    void addStr1();
    void addStr2();
    void addStr3();
    void addStr4();
    void addStr5();
    void addStr6();
    void addStr7();
    void addStr8();
    void addStr9();
    void addStr0();
    void addStrAC();
    void addStrRes();
    void addStrPlus();
    void addStrCon();
    void addStrDiv();
    void addStrMult();
    void addStrOpnBrck();
    void addStrClsBrck();
    void addStrPwr();
    void addStrSqrt();
    void addStrFact();
    void catchHoverMin();
    void catchUnHoverMin();
    void catchHoverCls();
    void catchUnHoverCls();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    QString Calculate(QString);
    QString INPUT;
    QLineEdit *InputBox;
    QLabel *ResultLab;
    QPushButton *btnOpnBrck;
    QPushButton *btnClsBrck;
    QPushButton *btn1;
    QPushButton *btn2;
    MouseCache *minBtn;
    MouseCache *closeBtn;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn0;
    QPushButton *btnFact;
    QPushButton *btnSqrt;
    QPushButton *btnRes;
    QPushButton *btnAC;
    QPushButton *btnPlus;
    QPushButton *btnCon;
    QPushButton *btnDiv;
    QPushButton *btnMult;
    QPushButton *btnPwr;
    bool isPower;

};
#endif
