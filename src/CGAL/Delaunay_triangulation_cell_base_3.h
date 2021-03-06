// Copyright (c) 2014  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//                 Sylvain Pion
//                 Jane Tournois <jane.tournois@geometryfactory.com>

// cell of a Delaunay triangulation of any dimension <=3

#ifndef CGAL_DELAUNAY_TRIANGULATION_CELL_BASE_3_H
#define CGAL_DELAUNAY_TRIANGULATION_CELL_BASE_3_H

#include <CGAL/basic.h>
#include <CGAL/triangulation_assertions.h>
#include <CGAL/Triangulation_ds_cell_base_3.h>
#include <CGAL/Triangulation_cell_base_3.h>

namespace CGAL {

template < typename GT, typename Cb = Triangulation_ds_cell_base_3<> >
class Delaunay_triangulation_cell_base_3
  : public Triangulation_cell_base_3<GT, Cb>
{
public:
  typedef GT Geom_traits;
  typedef typename Geom_traits::Point_3 Point_3;

  Point_3
  circumcenter(const Geom_traits& gt = Geom_traits()) const
  {
      return gt.construct_circumcenter_3_object()(this->vertex(0)->point(),
                                                  this->vertex(1)->point(),
                                                  this->vertex(2)->point(),
                                                  this->vertex(3)->point());
  }

};

} //namespace CGAL

#endif // CGAL_DELAUNAY_TRIANGULATION_CELL_BASE_3_H
