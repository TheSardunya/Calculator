#include "MouseCache.h"

#include <QEnterEvent>
#include "MouseCache.h"

MouseCache::MouseCache(QWidget* parent)
    : QPushButton(parent){setMouseTracking(true);cssHvr = "background-color: #CACAD3;color: #DFDFDF; font-size: 18px; border: none;"; cssUnHvr = "background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;"; cssClick = cssHvr;}

void MouseCache::enterEvent(QEnterEvent* event)
{
    QPushButton::enterEvent(event);
    this->setStyleSheet(cssHvr);
}

void MouseCache::leaveEvent(QEvent* event)
{
    QPushButton::leaveEvent(event);
    this->setStyleSheet(cssUnHvr);
}
void MouseCache::mousePressEvent(QMouseEvent* event)
{
    QPushButton::mousePressEvent(event);
    this->setStyleSheet(cssClick);
    emit clicked();
}
void MouseCache::mouseReleaseEvent(QMouseEvent* event)
{
    QPushButton::mousePressEvent(event);
    this->setStyleSheet(cssHvr);
}
