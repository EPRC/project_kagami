#ifndef CELLWINDOW_H
#define CELLWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include "layertablemodel.h"

class CellWindow : public QDialog
{
    Q_OBJECT
public:
    explicit CellWindow(QWidget *parent = 0);
    ~CellWindow();

    QLabel *layerLabel;
    QLabel *cellLabel;
    QLabel *pointLabel;

    QComboBox *layerBox;
    QLineEdit *cellName;
    QListView *pointView;

    QPushButton *addConfirm;
    QPushButton *setConfirm;
    QPushButton *cancel;

    QGridLayout *layout;

    bool setLayerModel(LayerTableModel *lm);
    int checkMode();
    void reset(const int &m);

    static const int ADD_MODE = 0;
    static const int SET_MODE = 1;

private:
    LayerTableModel *layerModel;
    int mode = CellWindow::ADD_MODE;

    void initObj();

signals:

public slots:

};

#endif // CELLWINDOW_H
