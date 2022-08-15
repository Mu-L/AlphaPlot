#ifndef TEXTITEM2D_H
#define TEXTITEM2D_H

#include "../3rdparty/qcustomplot/qcustomplot.h"

class AxisRect2D;
class Plot2D;
class XmlStreamReader;
class XmlStreamWriter;

class TextItem2D : public QCPItemText {
  Q_OBJECT
 public:
  TextItem2D(AxisRect2D *axisrect, Plot2D *plot);
  ~TextItem2D();

  QString getItemName();
  QIcon getItemIcon();
  QString getItemTooltip();

  enum class TextAlignment : int {
    TopLeft = 0,
    TopCenter = 1,
    TopRight = 2,
    CenterLeft = 3,
    CenterCenter = 4,
    CenterRight = 5,
    BottomLeft = 6,
    BottomCenter = 7,
    BottomRight = 8
  };

  AxisRect2D *getaxisrect() const;
  QColor getstrokecolor_textitem() const;
  double getstrokethickness_textitem() const;
  Qt::PenStyle getstrokestyle_textitem() const;
  TextAlignment gettextalignment_textitem() const;

  void setstrokecolor_textitem(const QColor &color);
  void setstrokethickness_textitem(const double value);
  void setstrokestyle_textitem(const Qt::PenStyle &style);
  void settextalignment_textitem(const TextAlignment &value);
  void setpixelposition_textitem(const QPointF &point);

  void save(XmlStreamWriter *xmlwriter);
  bool load(XmlStreamReader *xmlreader);

 signals:
  void positionChanged();

 protected:
  void mousePressEvent(QMouseEvent *event, const QVariant &details) override;
  void mouseMoveEvent(QMouseEvent *event, const QPointF &startPos) override;
  void mouseReleaseEvent(QMouseEvent *event, const QPointF &startPos) override;

 private:
  AxisRect2D *axisrect_;
  QString layername_;
  bool draggingtextitem_;
  QPointF dragtextitemorigin_;
  TextAlignment textalignment_;
  QCursor cursorshape_;
};

Q_DECLARE_METATYPE(TextItem2D *);
#endif  // TEXTITEM2D_H
