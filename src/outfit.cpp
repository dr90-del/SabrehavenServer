#include "outfits.h"

namespace Outfits {

// static singleton
Manager& Manager::getInstance() {
    static Manager instance;
    return instance;
}

bool Manager::loadFromXml(const std::string& filename) {
    // TODO: actually parse the file and fill _outfits.
    // For now, we'll just return true so the build/link errors go away.
    return true;
}

const Outfit* Manager::getOutfitByLookType(PlayerSex_t sex, uint16_t lookType) const {
    // TODO: search _outfits for matching sex & lookType
    // For now, return a dummy static
    static Outfit dummy{ lookType, false, false };
    return &dummy;
}

} // namespace Outfits
