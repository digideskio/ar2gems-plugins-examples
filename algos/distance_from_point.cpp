/*
 * Distance_from_point.cpp
 *
 *  Created on: Feb 10, 2010
 *      Author: aboucher
 */

#include "distance_from_point.h"

#include <geostat/utilities.h>
#include <utils/string_manipulation.h>
#include <grid/utilities.h>
#include <grid/utilities.h>



Distance_from_point::Distance_from_point() {

}

Distance_from_point::~Distance_from_point() {

}

Named_interface* Distance_from_point::create_new_interface( std::string& ) {
	return new Distance_from_point;
}

bool Distance_from_point::initialize( const Parameters_handler* parameters,
  Error_messages_handler* errors, Progress_notifier* notifier) {

	std::string grid_name = parameters->value( "Grid_Name.value" );
	errors->report( grid_name.empty(),
		  "Grid_Name", "No grid selected" );

  std::string region_name = parameters->value("Grid_Name.region");


  out_name_ = parameters->value( "Output_name.value" );
	errors->report( out_name_.empty(),
		  "Output_name", "No property name specified" );
  is_using_existing_prop_ = parameters->value("Output_name.reuse_property") == "1";

  grid_ = grid_utilities::get_grid_from_manager(grid_name);
  if (grid_ == 0) {
    errors->report("Grid_Name", "Grid does not exist");
    return false;
  }
  
  target_region_ = grid_->region(region_name);
  
  if (!region_name.empty() && target_region_ == 0)
  {
    errors->report("Grid_Name", "Region " + region_name + " does not exist");
    return false;
  }

  // retrieve data from the widget created in widget-demo with the accessor in widget-accessor-demo
  point_.x() = String_Op::to_number<double>(parameters->value("Point.x"));
  point_.y() = String_Op::to_number<double>(parameters->value("Point.y"));
  point_.z() = String_Op::to_number<double>(parameters->value("Point.z"));

  nb_threads_ = geostat_utils::initialize_nb_processors("Nb_processors", parameters, errors);

  if(!errors->empty()) {
    return false;
  }


  return true;

}

int Distance_from_point::execute(GsTL_project* proj, Progress_notifier* notifier){

  Grid_continuous_property* count_prop = grid_utilities::get_continous_property(grid_, out_name_, is_using_existing_prop_);


  int grid_size = grid_->size();

  Property_data_lock_guard lock(count_prop);

  #pragma omp parallel for num_threads(nb_threads_)
  for(int i=0; i< grid_size; ++i) {

    if (target_region_ && !target_region_->is_inside_region(i)) continue;

    Geostat_grid::location_type loc = grid_->location(i);

    double d = loc.distance2(point_);
    count_prop->set_value( std::sqrt(d), i);

  }

  return 0;

}
