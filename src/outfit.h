#ifndef FS_OUTFIT_H
#define FS_OUTFIT_H

#include "enums.h"      // pulls in the project’s definition of PlayerSex_t
#include <string>
#include <cstdint>

struct Outfit {
    // TODO: add whatever fields you need, e.g.:
    // uint16_t lookType;
    // std::string name;
    // ... etc.
};

namespace Outfits {

/// Load all outfits from the given XML file.
/// Returns true on success, false on error.
bool loadFromXml(const std::string& filename);

/// Return the Outfit for the given sex and lookType.
/// If not found, returns a reference to a default Outfit.
const Outfit& getOutfitByLookType(PlayerSex_t sex, uint16_t lookType);

}  // namespace Outfits

#endif // FS_OUTFIT_H
