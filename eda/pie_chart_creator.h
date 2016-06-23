/* -----------------------------------------------------------------------------
** Copyright� 2012 Advanced Resources and Risk Technology, LLC
** All rights reserved.
**
** This file is part of Advanced Resources and Risk Technology, LLC (AR2TECH) 
** version of the open source software sgems.  It is a derivative work by 
** AR2TECH (THE LICENSOR) based on the x-free license granted in the original 
** version of the software (see notice below) and now sublicensed such that it 
** cannot be distributed or modified without the explicit and written permission 
** of AR2TECH.
**
** Only AR2TECH can modify, alter or revoke the licensing terms for this 
** file/software.
**
** This file cannot be modified or distributed without the explicit and written 
** consent of AR2TECH.
**
** Contact Dr. Alex Boucher (aboucher@ar2tech.com) for any questions regarding
** the licensing of this file/software
**
** The open-source version of sgems can be downloaded at 
** sourceforge.net/projects/sgems.
** ----------------------------------------------------------------------------*/


#ifndef __PIE_CHART_CREATOR_H
#define __PIE_CHART_CREATOR_H

#include "common.h"

#include <charts/chart_creator.h>
#include <charts/chart_mdi_area.h>
#include <qtplugins/selectors.h>
#include <qtplugins/categorical_selectors.h>
#include <grid/grid_filter.h>

#include <QDialog>
#include <QMainWindow>
#include <QItemSelectionModel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QRadioButton>


class EDA_DEMO_DECL Pie_chart_creator : public Chart_creator 
{
  Q_OBJECT

public:
    Pie_chart_creator(Chart_mdi_area* mdi_area, QWidget *parent=0);
    ~Pie_chart_creator(){}


  private slots:
  void show_chart();

private:
  QWidget* build_help_page();

private :
  
  GridSelector* grid_selector_;
  Grid_filter* grid_filter_;
  SinglePropertySelector* weight_prop_selector_;
  SingleCategoricalPropertySelector* cat_prop_selector_;


};

class EDA_DEMO_DECL Pie_chart_creator_factory : public Chart_creator_factory
{

public:

  static Named_interface* create_new_interface(std::string&) {
    return new Pie_chart_creator_factory;
  }

  Pie_chart_creator_factory(){}
  ~Pie_chart_creator_factory(){}

  virtual QString title_name() const {return "Pie Chart";}
  virtual QString tab_name() const{return "DEMO";}
  std::string name() const {return "Pie Chart";}

  virtual Chart_creator* get_interface(Chart_mdi_area* mdi_area){return new Pie_chart_creator(mdi_area);}

};




#endif

