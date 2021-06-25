#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class MyPainter
{
public:
    MyPainter();

public:
    void draw(QPainter *painter, QPaintEvent *event);
    QBrush front;

private:
    QBrush back;
    QFont glFont;
    QPen textPen;
};

#endif // MYPAINTER_H
