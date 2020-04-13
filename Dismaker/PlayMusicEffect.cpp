#include "PlayMusicEffect.h"
#include "SFMLManager.h"
#include "AudioManager.h"

PlayMusicEffect::PlayMusicEffect(World& world, std::string id, bool loop) : Effect(world)
{
	_id = id;
	_loop = loop;
}

PlayMusicEffect::~PlayMusicEffect()
{
}

void PlayMusicEffect::Excute()
{
	SFMLManager::GetInstane()->GetAudioManager().PlayMusic(_id);
}
