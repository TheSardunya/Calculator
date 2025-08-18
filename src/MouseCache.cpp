#include "MouseCache.h"

#include <QEnterEvent>
#include "MouseCache.h"

MouseCache::MouseCache(QWidget* parent)
    : QPushButton(parent){setMouseTracking(true);cssHvr = "background-color: #CACAD3;color: #DFDFDF; font-size: 18px; border: none;"; cssUnHvr = "background-color: #2F2F38;color: #DFDFDF; font-size: 18px; border: none;";}

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
