#ifndef FS_OUTFITS_H
#define FS_OUTFITS_H

#include "enums.h"     // for PlayerSex_t
#include <string>
#include <vector>

namespace Outfits {

struct Outfit {
    uint16_t lookType{0};
    bool premium{false};
    bool unlocked{false};
    // later you can add more fields (e.g. addon requirements, display name, etc)
};

class Manager {
public:
    // Singleton accessor
    static Manager& getInstance();

    // Load all outfits from your XML (pass the tibia/creatures xml here)
    bool loadFromXml(const std::string& filename);

    // Return a pointer to the outfit entry (or nullptr if not found)
    const Outfit* getOutfitByLookType(PlayerSex_t sex, uint16_t lookType) const;

private:
    Manager() = default;
    std::vector<Outfit> _outfits;
    // you might index by sex+lookType in a map for speed
};

} // namespace Outfits

#endif // FS_OUTFITS_H
