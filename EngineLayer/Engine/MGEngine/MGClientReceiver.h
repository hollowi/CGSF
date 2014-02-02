#pragma once
#include "asios.h"
#include <map>
#include "ISession.h"

class INetworkEngine;

class MGClientReceiver : public INetworkReceiver
{
	typedef std::map<long, ASSOCKDESCEX> SessionMap;
public:
	MGClientReceiver(INetworkEngine* pOwner);
	virtual ~MGClientReceiver(void);

	virtual void notifyRegisterSocket(ASSOCKDESCEX& sockdesc, SOCKADDR_IN& ip) override;
	virtual void notifyReleaseSocket(ASSOCKDESCEX& sockdesc) override;
	virtual void notifyMessage(ASSOCKDESCEX& sockdesc, size_t length, char* data) override;
	virtual void notifyConnectingResult(INT32 requestID, ASSOCKDESCEX& sockdesc, DWORD error);

	bool SendRequest(BasePacket* pPacket);
	bool Disconnect(int Serial);

protected:

private:
//멀티쓰레드로 접근해서
	SessionMap m_SessionMap;
	CriticalSectionLock m_SessionLock;
	ASSOCKDESCEX m_SocketDesc;
	ISession m_Session;

	INetworkEngine* m_pOwner;
};