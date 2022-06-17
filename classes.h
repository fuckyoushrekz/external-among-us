#pragma once
#include <stdint.h>

class personalSettings
{
public:
	char pad_0000[8]; //0x0000
	float velocity; //0x0008
	int32_t killDistance; //0x000C
	int32_t killCooldown; //0x0010
	char pad_0014[12]; //0x0014
	int32_t nImpostor; //0x0020
	char pad_0024[20]; //0x0024
	int32_t reativacaoReuniao; //0x0038
	char pad_003C[4]; //0x003C
	int32_t discussionTime; //0x0040
	int32_t voteTime; //0x0044
	float tripulationVision; //0x0048
	float impostorVision; //0x004C
	uint8_t confirmEject; //0x0050
	uint8_t visibleTasks; //0x0051
	uint8_t anonymousVote; //0x0052
	char pad_0053[1]; //0x0053
	int32_t attTasks; //0x0054
	char pad_0058[2024]; //0x0058
}; //Size: 0x0840
static_assert(sizeof(personalSettings) == 0x840);