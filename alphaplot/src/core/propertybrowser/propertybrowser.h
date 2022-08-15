/* This file is part of AlphaPlot.
   Copyright 2022, Arun Narayanankutty <n.arun.lifescience@gmail.com>

   AlphaPlot is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   AlphaPlot is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with AlphaPlot.  If not, see <http://www.gnu.org/licenses/>.

   Description : PropertyBrowser */

#ifndef PROPERTYBROWSER_H
#define PROPERTYBROWSER_H

#include <QDockWidget>

class Ui_PropertyBrowser;
class PropertyItemModel;
class ObjectBrowserTreeItemModel;
class ApplicationWindow;
class MyWidget;
class QItemSelectionModel;
class QMenu;

class PropertyBrowser : public QDockWidget {
  Q_OBJECT
 public:
  PropertyBrowser(QWidget *parent = nullptr, ApplicationWindow *app = nullptr);
  ~PropertyBrowser();

 public slots:
  void populateObjectBrowser(MyWidget *widget);

 private slots:
  void MyWidgetNameChange(MyWidget *widget, const QString &string);
  void MyWidgetLabelChange(MyWidget *widget, const QString &string);
  void showObjectContextMenu(const QPoint &point);
  void selectObjectItem(const QModelIndex &current,
                        const QModelIndex &previous);

 private:
  ApplicationWindow *app_;
  Ui_PropertyBrowser *ui_;
  ObjectBrowserTreeItemModel *objectItemModel_;
  QItemSelectionModel *objectSelectionModel_;
  PropertyItemModel *propItemModel_;
};

#endif  // PROPERTYBROWSER_H
