
// PointOfInterest.h

// Points Of Interest (POI) are used to store special blocks in memory to interact with entities. See https://minecraft.fandom.com/wiki/Java_Edition_level_format#poi_format





#pragma once





enum ePointOfInterestType
{
	// Villagers
	poiArmorer,  // Blast furnace
	poiButcher,  // Smoker
	poiCartographer,  // Cartography table
	poiCleric,  // Brewing stand
	poiFarmer,  // Composter
	poiFisherman,  // Barrel
	poiFletcher,  // Fletching table
	poiLetherworker,  // Cauldron
	poiLibrairian,  // Lectern
	poiMason,  // Stonecutter
	poiShepherd,  // Loom
	poiToolsmith,  // Smithing table
	poiWeaponsmith,  // Grindstone
	poiHome,  // Bed
	poiMeeting,  // Bell

	// Bees
	poiBeehive,  // Beehive
	poiBeeNest,  // Bee nest

	// Others
	poiNetherPortal,  // Nether portal (used for faster portal travel)
	poiLodestone,  // Lodestone (used for player respawn)
	poiLightningRod,  // Lightning rod (used for lightnings)

	poiNone
};





class cPointOfInterest
{
public:

	cPointOfInterest(Vector3i a_BlockPosition, ePointOfInterestType a_PoiType) :
		m_BlockPosition(a_BlockPosition), m_Type(a_PoiType),
		m_FreeTickets(GetMaxFreeTickets(m_Type)) {}

	static ePointOfInterestType GetPointOnInterestType(BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta);
	static unsigned char GetMaxFreeTickets(ePointOfInterestType a_Type);

	static std::string GetPoiTypeName(ePointOfInterestType a_Type);
	static ePointOfInterestType GetPoiFromString(const std::string & a_PoiName);

	// Getters
	const Vector3i & GetBlockPosition() const { return m_BlockPosition; }
	ePointOfInterestType GetPoiType() const { return m_Type; }
	unsigned char GetTicketsRemaining() const { return m_FreeTickets; }

	void RemoveTicket() { m_FreeTickets = std::max(0, m_FreeTickets - 1); }
	void AddTicket() { m_FreeTickets = std::min<unsigned char>(GetMaxFreeTickets(m_Type), m_FreeTickets + 1); }

private:

	Vector3i m_BlockPosition;
	ePointOfInterestType m_Type;
	unsigned char m_FreeTickets;

};
