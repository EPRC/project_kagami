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
#include "../AbstractShape/cell.h"

class CellWindow : public QDialog
{
    Q_OBJECT
public:
    explicit CellWindow(QWidget *parent = 0);
    ~CellWindow();

    QLabel *layerLabel;
    QLabel *cellLabel;

    QComboBox *layerBox;
    QLineEdit *cellName;

    QPushButton *addConfirm;
    QPushButton *setConfirm;
    QPushButton *cancel;

    QGridLayout *layout;
    QWidget *centralWidget;

    bool setLayerModel(LayerTableModel *lm);
    bool setCurrentCell(Cell* cell);
    int checkMode();
    void reset(const int &m);

    static const int ADD_MODE = 0;
    static const int SET_MODE = 1;

private:
    LayerTableModel *layerModel;
    int mode = CellWindow::ADD_MODE;
    Cell* currentCell;

    void initObj();

signals:

public slots:

};

#endif // CELLWINDOW_H
