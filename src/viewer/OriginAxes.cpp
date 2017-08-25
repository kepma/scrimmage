/*!
 * @file
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 by the Georgia Tech Research Institute (GTRI)
 *
 * This file is part of SCRIMMAGE.
 *
 *   SCRIMMAGE is free software: you can redistribute it and/or modify it under
 *   the terms of the GNU Lesser General Public License as published by the
 *   Free Software Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   SCRIMMAGE is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 *   License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with SCRIMMAGE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Kevin DeMarco <kevin.demarco@gtri.gatech.edu>
 * @author Eric Squires <eric.squires@gtri.gatech.edu>
 * @date 31 July 2017
 * @version 0.1.0
 * @brief Brief file description.
 * @section DESCRIPTION
 * A Long description goes here.
 *
 */

#include <scrimmage/viewer/OriginAxes.h>

namespace scrimmage {

void OriginAxes::create(int length, vtkSmartPointer<vtkRenderer> &renderer) {
    renderer_ = renderer;

    axes_ =
            vtkSmartPointer<vtkAxesActor>::New();
    axes_->SetTotalLength(length, length, length);

    // The axes are positioned with a user transform
    vtkSmartPointer<vtkTransform> transform =
            vtkSmartPointer<vtkTransform>::New();
    transform->Translate(0, 0.0, 0);

    axes_->SetUserTransform(transform);
    // properties of the axes_ labels can be set as follows
    // this sets the x axis label to red
    // axes_->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(1,0,0);
    // the actual text of the axis label can be changed:
    // axes_->SetXAxisLabelText("test");
    renderer_->AddActor(axes_);
}

void OriginAxes::remove() {
    renderer_->RemoveActor(axes_);
}

} // namespace scrimmage