#include "common.h"
#include "pie_chart_creator.h"
#include <GsTL/utils/smartptr.h>
#include <utils/gstl_messages.h>
#include <utils/manager_repository.h>

//extern "C" __declspec(dllexport) int plugin_init() {
extern "C" EDA_DEMO_DECL int plugin_init() {

  // Add the new chart
  SmartPtr<Named_interface> ni = Root::instance()->interface(eda_charts_manager);
  Manager* dir = dynamic_cast<Manager*>( ni.raw_ptr() );
  if( !dir ) {
	  GsTLlog << "Directory " << eda_charts_manager << " does not exist \n";
	  return 1;
  }
  dir->factory( Pie_chart_creator_factory().name(), 
                Pie_chart_creator_factory::create_new_interface);

  return 0;
}
