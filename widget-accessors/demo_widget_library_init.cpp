#include "common.h"
#include "location_widget_accessor.h"
#include <GsTL/utils/smartptr.h>
#include <utils/gstl_messages.h>
#include <utils/manager_repository.h>

//extern "C" __declspec(dllexport) int plugin_init() {
extern "C" WIDGET_ACCESSOR_DEMO_DECL int plugin_init() {

  GsTLlog << "\n\n registering widget_accessor" << "\n";
  SmartPtr<Named_interface> ni = 
    Root::instance()->interface(xmlGeostatParamUtils_manager);
  Manager* dir = dynamic_cast<Manager*>( ni.raw_ptr() );
  if( !dir ) {
    GsTLlog << "Directory " << xmlGeostatParamUtils_manager << " does not exist \n";
    return 1;
  }
  
  Location_widget loc_widget;
  std::string classname(loc_widget.metaObject()->className());
  dir->factory(classname, Location_widget_accessor::create_new_interface);



  return 0;
}
