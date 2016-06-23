#ifndef LOCATION_WIDGET_ACCESSOR_H
#define LOCATION_WIDGET_ACCESSOR_H

#include "common.h"
#include "Location_widget.h"
#include <widget_accessor/accessor_base.h>
#include <gui/utils/qwidget_value_accessor.h>


class WIDGET_ACCESSOR_DEMO_DECL Location_widget_accessor : public QWidget_value_accessor {
public:
  static Named_interface* create_new_interface(std::string&);

public:
  Location_widget_accessor(QWidget* widget = 0);
  virtual ~Location_widget_accessor() {}

  virtual bool initialize(QWidget* widget = 0);
  virtual bool is_valid() const { return widget_ != 0; }
  virtual std::string value() const;
  virtual bool set_value(const std::string& str);
  virtual void clear();

private:
  Location_widget* widget_;

};


/*
class WIDGET_ACCESSOR_DEMO_DECL Location_widget_accessor
  : public accessor_base<Location_widget_accessor, Location_widget>
{
public:
  std::string value() const override;
  bool set_value(const std::string& str) override;
  void clear() override;
};
*/

#endif // 
