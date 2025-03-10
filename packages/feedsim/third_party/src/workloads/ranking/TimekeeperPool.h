// Copyright (c) Meta Platforms, Inc. and affiliates.
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
#pragma once

#include <memory>
#include <vector>

#include <folly/futures/ThreadWheelTimekeeper.h>

namespace ranking {

class TimekeeperPool {
public:
  explicit TimekeeperPool(int numTimekeepers);
  ~TimekeeperPool() = default;

  TimekeeperPool(const TimekeeperPool &) = delete;
  TimekeeperPool &operator=(const TimekeeperPool &) = delete;

  std::shared_ptr<folly::ThreadWheelTimekeeper> getTimekeeper() const;

private:
  std::vector<std::shared_ptr<folly::ThreadWheelTimekeeper>> timekeepers_;
};

} // namespace ranking
