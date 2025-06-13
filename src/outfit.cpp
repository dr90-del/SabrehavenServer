#include "otpch.h"
#include "outfit.h"
#include "tools.h"
#include <stdexcept>

namespace Outfits {

bool loadFromXml(const std::string& filename) {
    // TODO: parse XML here and populate a map or vector
    throw std::runtime_error("Outfits::loadFromXml not yet implemented");
}

const Outfit& getOutfitByLookType(PlayerSex_t sex, uint16_t lookType) {
    // TODO: lookup in your data structure
    static Outfit dummy;
    return dummy;
}

} // namespace Outfits
