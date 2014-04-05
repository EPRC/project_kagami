#ifndef LAYERMANGER_H
#define LAYERMANGER_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QColor>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QLayout>
#include <QGridLayout>

#include <QDebug>

class LayerManager : public QDialog
{
    Q_OBJECT
public:
    explicit LayerManager(QWidget *parent = 0);
    ~LayerManager();

    QLabel *label_name;
    QLabel *label_num;
    QLabel *label_color;
    QLabel *label_depth;
    QLineEdit *name;
    QLineEdit *depth;
    QSpinBox *num;
    QComboBox *color;
    QPushButton *confirm;
    QPushButton *cancel;

    QGridLayout *lyt;

    QColor getColor() const;
    int getNum() const;
    QString getName() const;
    double getDepth() const;

    void reset();

    static const int NUM_EXIST = 0;
    static const int INFO_MISS = 1;

signals:
    bool addLayer(const QColor&, const int&, const QString&, const double&);

public slots:
    void onConfirmClick();
    void onCancelClick();
    void addLayerSucceed();
    void addLayerFail(const int &failureCode);


};

#endif // LAYERMANGER_H
