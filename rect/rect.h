/************************************************************
 *              Shape : Rectangle
 * Notes:   point sequences: 1.lower-left, 2.top-left,
 *          3.top-right, 4. bottom-right
************************************************************/

#ifndef RECT_H
#define RECT_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QString>
#include "../AbstractShape/bbox.h"
#include "../AbstractShape/point.h"
#include "../AbstractShape/abstractshape.h"

class Rect : public AbstractShape
{
public:
    Rect();
    Rect(Rect *src);
    ~Rect();

    // AbstractShape interface
public:
    AbstractShape* createShape();

    QWidget* getSettingPad();
    QGridLayout* getLayout();

    BBox *getBBox() const;
    QString getType() const;
    int getAnchor() const;
    bool move(double x, double y);
    bool translate(double x, double y);
    bool changeAnchor(int ref);
    bool shrink(double left, double top, double right, double bottom);
    bool expand(double left, double top, double right, double bottom);
    bool copy(AbstractShape *shape);
    bool compare(AbstractShape *shape);

    static QString typeName;

    // Special Method/Member
    double getWidth() const;
    double getHeight() const;
    double getShiftX() const;
    double getShiftY() const;
    QString getWidthPar() const;
    QString getHeightPar() const;
    QString getShiftXPar() const;
    QString getShiftYPar() const;
    QList<Point*>* getPoints() const;

    // Special Parameters
    static QWidget *settingPad;
    static QGridLayout *layout;

private:

    double width;
    double height;
    double shiftX;
    double shiftY;

    QString widthPar;
    QString heightPar;
    QString shiftXPar;
    QString shiftYPar;

};

#endif // RECT_H
