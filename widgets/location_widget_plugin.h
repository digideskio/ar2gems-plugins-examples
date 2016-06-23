#ifndef LOCATION_WIDGET_PLUGIN_H
#define LOCATION_WIDGET_PLUGIN_H


#include <QtDesigner/QDesignerContainerExtension>
#include <QtDesigner/QDesignerCustomWidgetInterface>
#include <QtCore/QtPlugin>
#include <QtGui/QIcon>
#include <QPixmap>

class QDesignerFormEditorInterface;

class LocationWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    //Q_PLUGIN_METADATA(IID "demo.myplugin" FILE "QDesignerCustomWidgetInterface.json")
    Q_PLUGIN_METADATA(IID "demo.myplugin")
    Q_INTERFACES(QDesignerCustomWidgetInterface)
    //Q_PLUGIN_METADATA(IID "mydemoplugin.QDesignerCustomWidgetInterface" FILE "QDesignerCustomWidgetInterface.json")
    

public:
  explicit LocationWidgetPlugin(QObject * o) : QObject(o) { _initialized = false; }
  LocationWidgetPlugin() { _initialized = false; }
  void initialize(QDesignerFormEditorInterface *) Q_DECL_OVERRIDE;

  bool isInitialized() const { return _initialized; }
  QWidget * createWidget(QWidget * parent);
  QString name() const { return QLatin1String("Location_widget"); }
  QString group() const { return QLatin1String("My Widgets"); }
  QString toolTip() const { return QLatin1String("Location_widget"); }
  QString includeFile() const { return "Location_widget.h"; }
  QString whatsThis() const { return "Widget defining a 3d location"; }
  QIcon icon() const;
  bool isContainer() const { return false; }

private:
  bool _initialized;
};
#endif

