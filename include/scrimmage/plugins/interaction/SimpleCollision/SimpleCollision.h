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

#ifndef INCLUDE_SCRIMMAGE_PLUGINS_INTERACTION_SIMPLECOLLISION_SIMPLECOLLISION_H_
#define INCLUDE_SCRIMMAGE_PLUGINS_INTERACTION_SIMPLECOLLISION_SIMPLECOLLISION_H_

#include <scrimmage/simcontrol/EntityInteraction.h>
#include <scrimmage/entity/Entity.h>

#include <list>
#include <map>
#include <string>

class SimpleCollision : public scrimmage::EntityInteraction {
 public:
    virtual std::string name() { return std::string("SimpleCollision"); }

    virtual bool init(std::map<std::string, std::string> &mission_params,
                      std::map<std::string, std::string> &plugin_params);

    virtual bool step_entity_interaction(
        std::list<scrimmage::EntityPtr> &ents, double t, double dt);

    virtual bool collision_exists(
        std::list<scrimmage::EntityPtr> &ents, Eigen::Vector3d &p);

 protected:
    double collision_range_;
    bool startup_collisions_only_;
    bool enable_team_collisions_;
    bool enable_non_team_collisions_;
    bool init_alt_deconflict_;

    scrimmage::PublisherPtr team_collision_pub_;
    scrimmage::PublisherPtr non_team_collision_pub_;
};

#endif // INCLUDE_SCRIMMAGE_PLUGINS_INTERACTION_SIMPLECOLLISION_SIMPLECOLLISION_H_