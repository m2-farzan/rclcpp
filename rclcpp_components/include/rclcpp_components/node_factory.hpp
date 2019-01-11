// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP_COMPONENTS__NODE_FACTORY_HPP_
#define RCLCPP_COMPONENTS__NODE_FACTORY_HPP_

#include <memory>

#include "class_loader/class_loader.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rclcpp_components
{

class NodeFactory
{
public:
  NodeFactory() = default;
  virtual ~NodeFactory() = default;

  virtual
  NodeInstanceWrapper
  create_node_instance(const rclcpp::NodeOptions & node_options) = 0;

private:
  std::shared_ptr<class_loader::ClassLoader> class_loader_;
  std::shared_ptr<void> node_instance_;
};

}  // namespace rclcpp_components

#endif  // RCLCPP_COMPONENTS__NODE_FACTORY_HPP_