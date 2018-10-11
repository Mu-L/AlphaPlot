#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QMenu>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class AxisRect2D;

class MyTreeWidget : public QTreeWidget {
  Q_OBJECT;

 public:
  enum class PropertyItemType : int {
    Layout = 0,
    Grid = 1,
    Axis = 2,
    Legend = 3,
    TextItem = 4,
    LineItem = 5,
    ImageItem = 6,
    LSGraph = 7,
    Curve = 8,
    Spline = 9,
    StatBox = 10,
    Vector = 11,
    BarGraph = 12,
    PieGraph = 13,
  };
  MyTreeWidget(QWidget *parent = nullptr);
  ~MyTreeWidget() {}

 private slots:
  void CurrentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
  void showContextMenu(const QPoint &pos);
  void addfunctiongraph();
  void addplot();
  void addaxis();
  void removeaxis();
  void removels();
  void removecurve();
  void removespline();
  void removebar();
  // void removevector();
  // void removepie();

 private:
  QWidget *widget_;
  QAction *addgraph_;
  QAction *addfunctiongraph_;
  QAction *addaxis_;
  QAction *removeaxis_;
  QAction *removels_;
  QAction *removespline_;
  QAction *removecurve_;
  QAction *removebar_;
  QAction *removevector_;
  QAction *removepie_;
};

#endif  // MYTREEWIDGET_H
