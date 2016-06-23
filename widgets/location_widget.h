#ifndef LOCATION_WIDGET_H
#define LOCATION_WIDGET_H

#include "common.h"


#include <QWidget>
#include <QDoubleSpinBox>
#include <QLayout>



class WIDGET_DEMO_DECL Location_widget : public QWidget
{
    Q_OBJECT
public:
  Location_widget(QWidget *parent = 0);

  double x_location() const;
  double y_location() const;
  double z_location() const;

  void x_location(double _x);
  void y_location(double _y);
  void z_location(double _z);

 private :
  QDoubleSpinBox* x_;
  QDoubleSpinBox* y_;
  QDoubleSpinBox* z_;
  
};

#endif // 
