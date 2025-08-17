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

signals:
    void hovered();
    void unhovered();

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
};

#endif
