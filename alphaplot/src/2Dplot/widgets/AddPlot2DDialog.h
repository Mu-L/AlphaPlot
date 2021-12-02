#ifndef ADDPLOT2DDIALOG_H
#define ADDPLOT2DDIALOG_H

#include <QDialog>

#include "2Dplot/AxisRect2D.h"
#include "ApplicationWindow.h"

class QComboBox;
class QListWidget;
class QPushButton;
class QCheckBox;
class AxisRect2D;

//! Add/remove curves dialog
class AddPlot2DDialog : public QDialog {
  Q_OBJECT

 public:
  enum class Type : int {
    Table_Y = 0,
    Table_X_Y = 1,
    Table_X_Y_Y = 2,
    Table_X_Y_Y_Y = 3
  };
  AddPlot2DDialog(QWidget* parent, AxisRect2D* axisrect, Type type,
                  Qt::WindowFlags fl = Qt::Widget);

 private slots:
  ApplicationWindow::Graph plotStyle();
  void addPlots();
  void showPlotAssociations();
  void showFunctionDialog();
  void enableAddBtn();

 private:
  void closeEvent(QCloseEvent* event);
  void init();
  void populatePlotted();
  void populateAvailable();
  QSize sizeHint() const;
  void contextMenuEvent(QContextMenuEvent*);

  struct Data {
    Type type;
    Table* table;
    Column* xcol;
    Column* ycol1;
    Column* ycol2;
    Column* ycol3;
    Data()
        : type(Type::Table_Y),
          table(nullptr),
          xcol(nullptr),
          ycol1(nullptr),
          ycol2(nullptr),
          ycol3(nullptr) {}
  };
  ApplicationWindow* app_;
  AxisRect2D* axisrect_;
  Type type_;
  QList<Data> available_columns_;
  QList<Data> plotted_columns_;

  QPushButton* btnAdd_;
  QPushButton* btnOK_;
  QPushButton* btnCancel_;
  QPushButton* btnAssociations_;
  QPushButton* btnEditFunction_;
  QListWidget* available_;
  QListWidget* contents_;
  QComboBox* boxStyle_;
  QComboBox* boxMatrixStyle_;
  QCheckBox* boxShowCurrentFolder_;
  QGroupBox* groupBox_;
  QLabel* rowFromLabel_;
  QLabel* rowToLabel_;
  QSpinBox* rowFromBox_;
  QSpinBox* rowToBox_;
};

#endif  // ADDPLOT2DDIALOG_H
