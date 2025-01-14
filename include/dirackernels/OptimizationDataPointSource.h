//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

// Moose Includes
#include "DiracKernel.h"
#include "ReporterInterface.h"

/**
 * A OptimizationDataPointSource DiracKernel is used to create variable valued point sources.
 * Coordinates and values are given by the optimization tuple.
 */
class OptimizationDataPointSource : public DiracKernel, public ReporterInterface
{
public:
  static InputParameters validParams();
  OptimizationDataPointSource(const InputParameters & parameters);
  virtual void addPoints() override;

protected:
  virtual Real computeQpResidual() override;

private:
  const std::vector<Point> & _points;
  const std::vector<Real> & _values;
  /// map to associate points with their index into the vpp value
  std::map<Point, size_t> _point_to_index;
};
