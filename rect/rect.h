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
#include <QLabel>
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

    // Cell interface
    QGridLayout *getQGridLayout();
    Cell *createCell();
    bool applySetting();

    // AbstractShape interface
public:

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
    bool overlap(AbstractShape *shape);

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

public slots:
    void onCreate();
    void onSet();

public:
    // Special Parameters
    static QWidget *settingPad;
    static QGridLayout *layout;
    static QLabel *widthLabel;
    static QLabel *heightLabel;
    static QLabel *paraLabel;
    static QLabel *shiftXLabel;
    static QLabel *shiftYLabel;
    static QLineEdit *widthEdit;
    static QLineEdit *heightEdit;
    static QLineEdit *shiftXEdit;
    static QLineEdit *shiftYEdit;
    static QLineEdit *widthParEdit;
    static QLineEdit *heightParEdit;
    static QLineEdit *shiftXParEdit;
    static QLineEdit *shiftYParEdit;
    static bool isSet;

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
