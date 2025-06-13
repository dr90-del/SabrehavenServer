#ifndef FS_OUTFIT_H
#define FS_OUTFIT_H

#include <string>
#include <cstdint>

enum class PlayerSex_t : uint8_t { MALE = 0, FEMALE = 1 };

struct Outfit {
  // Define your outfit data here, e.g.:
  // uint16_t lookType;
  // std::string name;
};

namespace Outfits {

/// Load all outfits from the given XML file.  
/// Returns true on success, false on error.
bool loadFromXml(const std::string& filename);

/// Return the Outfit for the given sex and lookType.
/// If not found, returns a reference to a default Outfit.
const Outfit& getOutfitByLookType(PlayerSex_t sex, uint16_t lookType);

} // namespace Outfits

#endif // FS_OUTFIT_H
