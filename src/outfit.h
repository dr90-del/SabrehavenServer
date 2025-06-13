/**
 * Tibia GIMUD Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019 Sabrehaven and Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"
#include "outfit.h"         // declares loadFromXml, getOutfitByLookType
#include "tools.h"
#include <stdexcept>

namespace Outfits {

// Loads your outfits data from XML (implement according to your parser)
bool loadFromXml(const std::string& filename) {
    // TODO: parse the file, populate your internal data structures.
    // Return true on success or false if parse errors occur.
    throw std::runtime_error("Outfits::loadFromXml not yet implemented");
}

// Returns a reference to the outfit by sex and lookType
const Outfit& getOutfitByLookType(PlayerSex_t sex, uint16_t lookType) {
    // TODO: lookup in your container (e.g. a map) and return.
    // If not found, you might throw or return a default outfit.
    static Outfit dummy;
    return dummy;
}

} // namespace Outfits
