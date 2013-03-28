#include "pencil.h"

#include <QPen>
#include <QPainter>

Pencil::Pencil()
{
    shortcut_ = Qt::Key_Z;
    pencil.setCapStyle(Qt::RoundCap);
    pencil.setJoinStyle(Qt::RoundJoin);
}

Pencil::~Pencil()
{
}

void Pencil::drawPoint(const QPointF &st)
{
    QPainter painter;
    painter.begin(surface_->imagePtr());
    painter.setPen(pencil);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPoint(st);
}

void Pencil::drawLine(const QPointF &st,
                      const QPointF &end,
                      qreal &)
{
    QPainter painter;
    painter.begin(surface_->imagePtr());
    painter.setPen(pencil);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawLine(st, end);
}

void Pencil::setColor(const QColor &color)
{
    pencil.setColor(color);
    mainColor = color;
}

int Pencil::width()
{
    return pencil.width();
}

void Pencil::setWidth(int w)
{
    pencil.setWidth(w);
}

QVariantMap Pencil::brushInfo()
{
    QVariantMap map;
    QVariantMap colorMap;
    colorMap.insert("red", pencil.color().red());
    colorMap.insert("green", pencil.color().green());
    colorMap.insert("blue", pencil.color().blue());
    map.insert("width", QVariant(pencil.width()));
    map.insert("color", colorMap);
    map.insert("name", QVariant("Pencil"));
    return map;
}

QVariantMap Pencil::defaultInfo()
{
    QVariantMap map;
    map.insert("width", QVariant(1));
    QVariantMap colorMap;
    colorMap.insert("red", 0);
    colorMap.insert("green", 0);
    colorMap.insert("blue", 0);
    map.insert("color", colorMap);
    return map;
}
