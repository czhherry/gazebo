/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef BULLETTYPES_HH
#define BULLETTYPES_HH

#include <boost/shared_ptr.hpp>
#include "gazebo/physics/bullet/bullet_math_inc.h"
#include "gazebo/math/Vector3.hh"
#include "gazebo/math/Vector4.hh"
#include "gazebo/math/Pose.hh"

/// \file
/// \ingroup gazebo_physics
/// \ingroup gazebo_physics_bullet
/// \brief Bullet wrapper forward declarations and typedefs
namespace gazebo
{
  namespace physics
  {
    class BulletCollision;
    class BulletLink;
    class BulletPhysics;
    class BulletRayShape;

    typedef boost::shared_ptr<BulletPhysics> BulletPhysicsPtr;
    typedef boost::shared_ptr<BulletCollision> BulletCollisionPtr;
    typedef boost::shared_ptr<BulletLink> BulletLinkPtr;
    typedef boost::shared_ptr<BulletRayShape> BulletRayShapePtr;

    class BulletTypes {
      /// \brief Convert a bullet btVector3 to a gazebo Vector3
      public: static math::Vector3 ConvertVector3(const btVector3 &_bt)
              {
                return math::Vector3(_bt.getX(), _bt.getY(), _bt.getZ());
              }

      /// \brief Convert a gazebo Vector3 to a bullet btVector3
      public: static btVector3 ConvertVector3(const math::Vector3 &_vec)
              {
                return btVector3(_vec.x, _vec.y, _vec.z);
              }

      /// \brief Convert a bullet btVector4 to a gazebo Vector4
      public: static math::Vector4 ConvertVector4(const btVector4 &_bt)
              {
                return math::Vector4(_bt.getX(), _bt.getY(),
                                     _bt.getZ(), _bt.getW());
              }

      /// \brief Convert a gazebo Vector4 to a bullet btVector4
      public: static btVector4 ConvertVector4(const math::Vector4 &_vec)
              {
                return btVector4(_vec.x, _vec.y, _vec.z, _vec.w);
              }

      /// \brief Convert a bullet transform to a gazebo pose
      public: static math::Pose ConvertPose(const btTransform &_bt)
              {
                math::Pose pose;
                pose.pos = ConvertVector3(_bt.getOrigin());
                pose.rot.w = _bt.getRotation().getW();
                pose.rot.x = _bt.getRotation().getX();
                pose.rot.y = _bt.getRotation().getY();
                pose.rot.z = _bt.getRotation().getZ();
                return pose;
              }

      /// \brief Convert a gazebo pose to a bullet transform
      public: static btTransform ConvertPose(const math::Pose &_pose)
              {
                btTransform trans;

                trans.setOrigin(ConvertVector3(_pose.pos));
                trans.setRotation(btQuaternion(_pose.rot.x, _pose.rot.y,
                                               _pose.rot.z, _pose.rot.w));
                return trans;
              }

    };
  }
}
#endif  // #ifndef BULLETTYPES_HH
