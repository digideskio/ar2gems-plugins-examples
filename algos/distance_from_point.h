#ifndef __DISTANCE_FROM_POINT_H__
#define __DISTANCE_FROM_POINT_H__


#include "common.h"
#include <geostat/geostat_algo.h>
#include <grid/geostat_grid.h>
#include <grid/grid_property.h>
#include <grid/grid_region.h>
#include <grid/neighborhood.h>
#include <utils/error_messages_handler.h>
#include <appli/project.h>
#include <geostat/parameters_handler.h>

class Distance_from_point : public Geostat_algo {
public:
  Distance_from_point();
  virtual ~Distance_from_point();

	  virtual bool initialize( const Parameters_handler* parameters,
      Error_messages_handler* errors, Progress_notifier* notifier);
    virtual int execute(GsTL_project* proj, Progress_notifier* notifier);
	  virtual std::string name() const { return "distance-from-point"; }

	 public:
	  static Named_interface* create_new_interface( std::string& );

private :

  Geostat_grid* grid_;
  Grid_region* target_region_;

  Geostat_grid::location_type point_;
  std::string out_name_;


};

#endif /* GEOBODY_H_ */
