#pragma once
#include "ILogicEntry.h"
#include <map>

class ChatUser;
class BasePacket;

class ChatLogicJsonEntry : public ILogicEntry
{
	typedef std::map<int, ChatUser*> ChatUserMap;
public:
	ChatLogicJsonEntry(void);
	virtual ~ChatLogicJsonEntry(void);

	virtual bool Initialize() override;
	virtual bool ProcessPacket(BasePacket* pBasePacket) override;
	bool Broadcast(BasePacket* pPacket);

protected:
	bool OnConnectPlayer(int Serial);
	bool OnPlayerData(BasePacket* pPacket);
	bool OnDisconnectPlayer(int Serial);

private:
	ChatUserMap m_ChatUserMap;
};

