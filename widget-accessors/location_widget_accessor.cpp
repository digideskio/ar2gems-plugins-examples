#include "location_widget.h"
#include "location_widget_accessor.h"

#include <utils/gstl_messages.h>
#include <utils/manager_repository.h>
#include <utils/string_manipulation.h>
#include <widget_accessor/qt_accessors.h>

#include <sstream>
#include <QDomDocument>


//=====================================

std::string Location_widget_accessor::value() const {
  const std::string widget_name = widgetName();
  std::ostringstream result;
  result << "<" << widget_name
    << " x=\"" << widget_->x_location() << "\""
    << " y=\"" << widget_->y_location() << "\""
    << " z=\"" << widget_->z_location() << "\"/>";

  return result.str();
}


bool Location_widget_accessor::set_value(const std::string& str) {
  QString qstr(str.c_str());

  // str is just an element of an xml file, hence can not be parsed
  // by QDomDocument. We need to add a root element.
  qstr = "<root>" + qstr + "</root>";
  QDomDocument doc;
  bool parsed = doc.setContent(qstr);
  appli_assert(parsed);

  QDomElement root_element = doc.documentElement();
  QDomElement elem = root_element.firstChild().toElement();

  widget_->x_location(elem.attribute("x").toDouble());
  widget_->y_location(elem.attribute("y").toDouble());
  widget_->z_location(elem.attribute("z").toDouble());

  return true;

}


void Location_widget_accessor::clear() {
  widget_->x_location(0.);
  widget_->y_location(0.);
  widget_->z_location(0.);
}

