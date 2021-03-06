//实际大小为400
struct WSAData 
{
	ushort wVersion;
	ushort wHighVersion;
	char szDescription[257];
	char szSystemStatus[129];
	ushort iMaxSockets;
	ushort iMaxUdpDg;
	char* lpVendorInfo;
	
	~WSAData()
	{
		rfs.WSACleanup
	}
	
	WSAData()
	{
		rbuf<char> buf(400)
		rfs.WSAStartup(0x00000101.toushort,buf.begin)
	}
}

WSAData g_WSAData_init

namespace rfs
{
	//ver is 2 bytes
	int WSAStartup(int ver,char* data)
	{
		push data
		push ver
		rn invoke WSAStartup
		mov s_ret,eax
	}
	
	int WSACleanup()
	{
		rn invoke WSACleanup
		mov s_ret,eax
	}
	
	int socket(int af,int type,int protocol)
	{
		push protocol
		push type
		push af
		rn invoke socket
		mov s_ret,eax
	}

	int connect(int s,void* name,int namelen)
	{
		push namelen
		push name
		push s
		rn invoke connect
		mov s_ret,eax
	}
	
	int close(int sock)
	{
		push sock
		rn invoke closesocket
		mov s_ret,eax
	}
	
	int send(int s,void* data,int size,int flags)
	{
		push flags
		push size
		push data
		push s
		rn invoke send
		mov s_ret,eax
	}

	int recv(int s,void* data,int size,int flags)
	{
		push flags
		push size
		push data
		push s
		rn invoke recv
		mov s_ret,eax
	}
	
	int bind(int s,void* addr,int namelen)
	{
		push namelen
		push addr
		push s
		rn invoke bind
		mov s_ret,eax
	}

	int listen(int s,int backlog)
	{
		push backlog
		push s
		rn invoke listen
		mov s_ret,eax
	}

	int accept(int s,void* addr,int* addrlen)
	{
		push addrlen
		push addr
		push s
		rn invoke accept
		mov s_ret,eax
	}
}