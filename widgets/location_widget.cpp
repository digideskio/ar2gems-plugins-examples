#include "location_widget.h"
#include <QLabel>

Location_widget::Location_widget(QWidget *parent)
  : QWidget(parent)
{

  x_ = new QDoubleSpinBox(this);
  y_ = new QDoubleSpinBox(this);
  z_ = new QDoubleSpinBox(this);

  x_->setMinimum(-9e20);
  x_->setMaximum(9e20);
  y_->setMinimum(-9e20);
  y_->setMaximum(9e20);
  z_->setMinimum(-9e20);
  z_->setMaximum(9e20);

  x_->setSingleStep(10);
  y_->setSingleStep(10);
  z_->setSingleStep(10);

  QHBoxLayout* layout = new QHBoxLayout(this);

  layout->addWidget(new QLabel("X", this));
  layout->addWidget(x_);
  layout->addWidget(new QLabel("Y", this));
  layout->addWidget(y_);
  layout->addWidget(new QLabel("Z", this));
  layout->addWidget(z_);

  this->setLayout(layout);

}

double Location_widget::x_location() const { return x_->value(); }
double Location_widget::y_location() const { return y_->value(); }
double Location_widget::z_location() const { return z_->value(); }

void Location_widget::x_location(double _x) { x_->setValue(_x); }
void Location_widget::y_location(double _y) { y_->setValue(_y); }
void Location_widget::z_location(double _z) { z_->setValue(_z); }

