#include "rect.h"

Rect::Rect() : AbstractShape()
{
    anchor = CENTER;
    width = 0;
    height = 0;
    shiftX = 0;
    shiftY = 0;

    typeName = "Rect";
    widthPar = "";
    heightPar = "";
    shiftXPar = "";
    shiftYPar = "";

    points->append(new Point(0,0));
    points->append(new Point(0,0));
    points->append(new Point(0,0));
    points->append(new Point(0,0));
}

Rect::Rect(Rect *src)
{
    anchor = src->getAnchor();
    width = src->getWidth();
    height = src->getHeight();
    shiftX = src->getShiftX();
    shiftY = src->getShiftY();
    shiftXPar = src->getShiftXPar();
    shiftYPar = src->getShiftYPar();

}

Rect::~Rect()
{

}

AbstractShape *Rect::createShape()
{
    return new Rect();
}

BBox *Rect::getBBox() const
{
    BBox *bBox = new BBox();
    bBox->left = points->at(0)->x;
    bBox->top = points->at(1)->y;
    bBox->right = points->at(2)->x;
    bBox->bottom = points->at(3)->y;
}

QString Rect::getType() const
{
    return typeName;
}

int Rect::getAnchor() const
{
    return anchor;
}

bool Rect::move(double &x, double &y)
{
    shiftX += x;
    shiftY += y;

    if(points){
        foreach(Point *p, *points){
            p->x += x;
            p->y += y;
        }
        return true;
    }
    return false;
}

bool Rect::translate(double &x, double &y)
{
    move(x,y);

    if (childCells){
        foreach(AbstractShape* child, *childCells){
            child->translate(x,y);
        }
    }
    return true;
}

bool Rect::changeAnchor(int &ref)
{
    anchor = ref;
    return true;
}

bool Rect::shrink(double &left, double &top, double &right, double &bottom)
{
    if ((width-left-right)<=0 || (height-top-bottom) >=0)
        return false;
    width -= left+right;
    height -= top+bottom;

    if (points){
        points->at(0)->x += left;
        points->at(0)->y += bottom;
        points->at(1)->x += left;
        points->at(1)->y -= top;
        points->at(2)->x -= right;
        points->at(2)->y -= top;
        points->at(3)->x -= right;
        points->at(3)->y += bottom;
        return true;
    }
    return false;
}

bool Rect::expand(double &left, double &top, double &right, double &bottom)
{
    return shrink(-left,-top,-right,-bottom);
}

bool Rect::copy(AbstractShape *shape)
{
    if (compare(shape)){
        Rect *src = static_cast<Rect*>(shape);
        layer = src->getLayer();
        anchor = src->getAnchor();
        width = src->getWidth();
        widthPar = src->getWidthPar();
        height = src->getHeight();
        heightPar = src->getHeightPar();
        shiftX = src->getShiftX();
        shiftXPar = src->getShiftXPar();
        shiftY = src->getShiftY();
        shiftYPar = src->getShiftYPar();
        points->clear();
        foreach(Point* p, *(src->getPoint())){
            points->append(new Point(*p));
        }
        return true;
    }
    return false;
}

bool Rect::compare(AbstractShape *shape)
{
    if (shape)
        if (typeName == shape->getType())
            return true;
    return false;
}

double Rect::getWidth() const
{
    return width;
}

double Rect::getHeight() const
{
    return height;
}

double Rect::getShiftX() const
{
    return shiftX;
}

double Rect::getShiftY() const
{
    return shiftY;
}

QString Rect::getWidthPar() const
{
    return widthPar;
}

QString Rect::getHeightPar() const
{
    return heightPar;
}

QString Rect::getShiftXPar() const
{
    return shiftXPar;
}

QString Rect::getShiftYPar() const
{
    return shiftYPar;
}

QList<Point *> *Rect::getPoints() const
{
    return points;
}

QString Rect::typeName = "Rect";
QWidget *settingPad = new QWidget();
QGridLayout *layout = new QGridLayout();
