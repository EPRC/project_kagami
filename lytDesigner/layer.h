#ifndef LAYER_H
#define LAYER_H
#include <QString>
#include <QColor>
#include <QVariant>

//Q_DECLARE_METATYPE(QColor)

class Layer
{
public:

    Layer();
    ~Layer();

    QColor getColor() const;
    QVariant getName() const;
    QVariant getNum() const;
    QVariant getDepth() const;

    bool setColor(const QColor &colorp);
    bool setColor(const QVariant &colorp);
    bool setName(const QVariant &namep);
    bool setName(const QString &namep);
    bool setNum(const QVariant &nump);
    bool setNum(const int &nump);
    bool setDepth(const QVariant &depthp);
    bool setDepth(const double &depthp);

    static const int COLOR  = 0;
    static const int NUMBER = 1;
    static const int NAME   = 2;
    static const int DEPTH  = 3;

private:
    QColor color;
    QString name;
    int num;
    double depth;
};

#endif // LAYER_H
