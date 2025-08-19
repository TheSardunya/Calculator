#ifndef MOUSECACHE_H
#define MOUSECACHE_H
#pragma once
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QEnterEvent>
#include <QEvent>

class MouseCache : public QPushButton {
    Q_OBJECT
public:
    explicit MouseCache(QWidget* parent = nullptr);
    QString cssHvr;
    QString cssUnHvr;
    QString cssClick;
protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

#endif
