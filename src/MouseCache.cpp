#include "MouseCache.h"

#include <QEnterEvent>
#include "MouseCache.h"

MouseCache::MouseCache(QWidget* parent)
    : QPushButton(parent){setMouseTracking(true);}

void MouseCache::enterEvent(QEnterEvent* event)
{
    QPushButton::enterEvent(event);
    emit hovered();
}

void MouseCache::leaveEvent(QEvent* event)
{
    QPushButton::leaveEvent(event);
    emit unhovered();
}
