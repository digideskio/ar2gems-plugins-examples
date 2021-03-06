#include "location_widget_plugin.h"
#include "Location_widget.h"

QIcon LocationWidgetPlugin::icon() const { return QIcon(); }
QWidget * LocationWidgetPlugin::createWidget(QWidget * parent) { return new Location_widget(parent); }


void LocationWidgetPlugin::initialize(QDesignerFormEditorInterface *)
{
  if (_initialized) return;
  _initialized = true;
}