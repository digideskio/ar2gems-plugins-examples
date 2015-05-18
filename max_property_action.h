// DEMO

#ifndef MAX_PROPERTY_ACTIONS_H_
#define MAX_PROPERTY_ACTIONS_H_

#include "common.h"

#include <appli/action.h> 
#include <grid/grid_property.h>
#include <grid/geostat_grid.h>
#include <utils/named_interface.h>


class PLUGIN_DEMOS_DECL Max_property :  public Action {
 
public: 

  static Named_interface* create_new_interface( std::string& );

  virtual ~Max_property() {} 
  virtual bool init( std::string& parameters, GsTL_project* proj,
                     Error_messages_handler* errors ); 
  virtual bool exec(); 

private :
  Geostat_grid* grid_;
  std::vector<Grid_continuous_property*> props_;
  Grid_continuous_property* max_prop_;

};



#endif