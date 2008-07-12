#ifndef DEF_H
#define DEF_H

#include "config.h"

#ifdef WINDOWS  // if Windows ********************
typedef int ssize_t;
typedef int socklen_t;

#define PATH_SP '\\'
#define MAXPATHLEN 1024
#define MAXHOSTNAMELEN 256

#define snprintf _snprintf
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#define ioctl ioctlsocket

#define RECV(fd, buf, len) recv((fd), (buf), (len), 0)
#define SEND(fd, buf, len) send((fd), (buf), (len), 0)
#define EWOULDBLOCK  WSAEWOULDBLOCK
#define EINPROGRESS  WSAEINPROGRESS
#define CLOSE_SOCKET(sk) closesocket((sk))

#else           // if unix ***********************

#define CLOSE_SOCKET(sk) close((sk))

#ifndef SOCKET
typedef int SOCKET;
#endif

#define INVALID_SOCKET -1

#define PATH_SP '/'
#define RECV(fd, buf, len) read((fd), (buf), (len))
#define SEND(fd, buf, len) write((fd), (buf), (len))

#endif

#endif  // DEF_H

