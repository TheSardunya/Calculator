#ifndef DEFINEWINDOW_H
#define DEFINEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>
#include <QLabel>
#include <QCloseEvent>
#include <QLineEdit>
#include <QPointF>

#include "MouseCache.h"
namespace Ui {
class DefineWindow;
}

class DefineWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DefineWindow(QWidget *parent = nullptr);
    ~DefineWindow();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private:
    void exitDef();
    Ui::DefineWindow *ui;
    MouseCache *closebtn;
    MouseCache *minBtn;
    QLineEdit *xLine;
    QLineEdit *yLine;
    QLineEdit *zLine;
    QLabel *xLb;
    QLabel *yLb;
    QLabel *zLb;
};

#endif // DEFINEWINDOW_H
