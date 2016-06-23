/*
 * Local_high_values.cpp
 *
 *  Created on: Feb 10, 2010
 *      Author: aboucher
 */

#include "local_high_values_algo.h"

#include <geostat/utilities.h>
#include <utils/string_manipulation.h>
#include <grid/utilities.h>
#include <grid/neighbors.h>
#include <geostat/utilities.h>



Local_high_values::Local_high_values() {

}

Local_high_values::~Local_high_values() {

}

Named_interface* Local_high_values::create_new_interface( std::string& ) {
	return new Local_high_values;
}

bool Local_high_values::initialize( const Parameters_handler* parameters,
  Error_messages_handler* errors, Progress_notifier* notifier) {

	std::string grid_name = parameters->value( "Data_selector.grid" );
	errors->report( grid_name.empty(),
		  "Data_selector", "No grid selected" );

  std::string input_prop = parameters->value( "Data_selector.property" );
  errors->report( input_prop.empty(),
		  "Data_selector", "No property name specified" );

  out_name_ = parameters->value( "output.value" );
	errors->report( out_name_.empty(),
		  "output", "No property name specified" );


  grid_ = grid_utilities::get_grid_from_manager(grid_name);
  errors->report(grid_ == 0, "Grid_Name", "Grid does not exist" );
  
  if(!errors->empty()) {
    return false;
  }

  prop_ = grid_->property(input_prop);
  if(prop_ == 0) {
	  errors->report( "Data_selector", "Property does not exist" );
	  return false;
  }
  region_ = grid_->region( parameters->value( "Data_selector.region" ));

  GsTLTriplet ranges;
  GsTLTriplet angles;

  bool ok = geostat_utils::extract_ellipsoid_definition( ranges, angles, "Ellipsoid",parameters, errors );

  if(!ok) {
    return false;
  }

  neigh_ = grid_->neighborhood(ranges, angles, 0, false, region_, 0 );

  threshold_ = String_Op::to_number<float>( parameters->value( "threshold.value" ) );

  return true;

}

int Local_high_values::execute(GsTL_project* proj, Progress_notifier* notifier){

  Grid_continuous_property* count_prop = grid_utilities::add_property_to_grid(grid_, out_name_);

  neigh_->select_property( prop_->name() );

  int grid_size = grid_->size();

  #pragma omp parallel for
  for(int i=0; i< grid_size; ++i) {

    if( region_ && !region_->is_inside_region(i) ) continue;

    Neighbors neighbors;
    Geovalue gval(grid_, prop_, i );
    neigh_->find_neighbors( gval, neighbors );
    if(neighbors.empty()) continue;

    int count = 0;
    Neighbors::iterator it = neighbors.begin();
    for( ; it != neighbors.end(); ++it) {
      if(!it->is_informed()) continue;
      if( it->property_value() > threshold_ ) count++;
    }

    count_prop->set_value( count, i );

  }

  return 0;

}
