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
    void delStr();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QString Calculate(QString);
    QString INPUT;
    QLineEdit *InputBox;
    QLabel *ResultLab;
    MouseCache *btnDel;
    MouseCache *btnOpnBrck;
    MouseCache *btnClsBrck;
    MouseCache *btn1;
    MouseCache *btn2;
    MouseCache *minBtn;
    MouseCache *closeBtn;
    MouseCache *btn3;
    MouseCache *btn4;
    MouseCache *btn5;
    MouseCache *btn6;
    MouseCache *btn7;
    MouseCache *btn8;
    MouseCache *btn9;
    MouseCache *btn0;
    MouseCache *btnFact;
    MouseCache *btnSqrt;
    MouseCache *btnRes;
    MouseCache *btnAC;
    MouseCache *btnPlus;
    MouseCache *btnCon;
    MouseCache *btnDiv;
    MouseCache *btnMult;
    MouseCache *btnPwr;
    bool isPower;

};
#endif
