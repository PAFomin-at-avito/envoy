#pragma once

#include <string>

#include "common/common/macros.h"

namespace Envoy {
namespace Extensions {
namespace StatSinks {
namespace Common {
namespace Statsd {

enum class TagPosition {
  TagAfterValue,
  TagAfterName
};

struct TagFormat {
  const std::string & start;
  const std::string & assign;
  const std::string & separator;
  const TagPosition tag_position;
};

static const TagFormat& getDefaultTagFormat() {
    CONSTRUCT_ON_FIRST_USE(
        TagFormat,
        "|#",                        // start
        ":",                         // assign
        ",",                         // separator
        TagPosition::TagAfterValue,  // tag_position
    );
}

static const TagFormat& getGraphiteTagFormat() {
    CONSTRUCT_ON_FIRST_USE(
        TagFormat,
        ";",                        // start
        "=",                        // assign
        ";",                        // separator
        TagPosition::TagAfterName,  // tag_position
    );
}

} // namespace Statsd
} // namespace Common
} // namespace StatSinks
} // namespace Extensions
} // namespace Envoy
