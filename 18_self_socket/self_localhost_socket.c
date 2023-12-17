#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sockaddr {
  uint8_t sa_len;
  uint8_t sa_family;
  char sa_data[14];
};

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef AF_INET
#define AF_INET 2
#endif

#ifndef SOCK_STREAM
#define SOCK_STREAM 1
#endif

#ifndef RET_OK
#define RET_OK (0)
#endif

#ifndef bool
typedef uint8_t bool;
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef RET_ERR
#define RET_ERR (-1)
#endif

#ifndef INADDR_ANY
#define INADDR_ANY (0x00000000)
#endif

#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK ((uint32_t)0x7f000001UL)
#endif

#ifndef HTTP_PORT
#define HTTP_PORT (80)
#endif

#define MAX_BACKLOG 1

#define PP_HTONS(x)                                                            \
  ((uint16_t)((((x) & (uint16_t)0x00ffU) << 8) |                               \
              (((x) & (uint16_t)0xff00U) >> 8)))

#ifndef htons
#define htons(x) PP_HTONS(x)
#endif

typedef uint32_t socklen_t;
typedef uint32_t in_addr_t;

struct in_addr {
  in_addr_t s_addr;
};

struct sockaddr_in {
  uint8_t sin_len;
  uint8_t sin_family;
  uint16_t sin_port;
  struct in_addr sin_addr;
#define SIN_ZERO_LEN 8
  char sin_zero[SIN_ZERO_LEN];
};
// typedef int ssize_t;

// #define MEMP_NUM_NETCONN 4
// #define SOCKET_OFFSET 0

// #define FD_SETSIZE MEMP_NUM_NETCONN
// #define FDSETSAFESET(n, code) \
//   do { \
//     if (((n)-SOCKET_OFFSET < MEMP_NUM_NETCONN) && \
//         (((int)(n)-SOCKET_OFFSET) >= 0)) { \
//       code; \
//     } \
//   } while (0)
// #define FDSETSAFEGET(n, code) \
//   (((n)-SOCKET_OFFSET < MEMP_NUM_NETCONN) && (((int)(n)-SOCKET_OFFSET) >= 0)
//   \
//        ? (code) \ : 0)
// #define FD_SET(n, p) \
//   FDSETSAFESET(n, (p)->fd_bits[((n)-SOCKET_OFFSET) / 8] = \
//                       (u8_t)((p)->fd_bits[((n)-SOCKET_OFFSET) / 8] | \
//                              (1 << (((n)-SOCKET_OFFSET) & 7))))
// #define FD_CLR(n, p) \
//   FDSETSAFESET(n, (p)->fd_bits[((n)-SOCKET_OFFSET) / 8] = \
//                       (u8_t)((p)->fd_bits[((n)-SOCKET_OFFSET) / 8] & \
//                              ~(1 << (((n)-SOCKET_OFFSET) & 7))))
// #define FD_ISSET(n, p) \
//   FDSETSAFEGET(n, (p)->fd_bits[((n)-SOCKET_OFFSET) / 8] & \
//                       (1 << (((n)-SOCKET_OFFSET) & 7)))
// #define FD_ZERO(p) memset((void *)(p), 0, sizeof(*(p)))

// typedef struct fd_set {
//   unsigned char fd_bits[(FD_SETSIZE + 7) / 8];
// } fd_set;

// struct timeval {
//   long tv_sec;  /* seconds */
//   long tv_usec; /* and microseconds */
// };

// 仅支持本地相互通信
// 阻塞使用消息通知，非阻塞直接进行函数回调
// 尽量零拷贝
// 服务端接收消息将消息拷贝至提供服务端实现
// 服务端发送消息可通过直接设置回调
// 仅支持tcp ipv4

int self_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int self_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int self_getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int self_getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int self_getsockopt(int sockfd, int level, int optname, void *optval,
                    socklen_t *optlen);
int self_closesocket(int sockfd);
int self_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int self_listen(int sockfd, int backlog);
ssize_t self_recv(int sockfd, void *buf, size_t len, int flags);
ssize_t self_recvfrom(int sockfd, void *buf, size_t len, int flags,
                      struct sockaddr *src_addr, socklen_t *addrlen);
ssize_t self_send(int sockfd, const void *buf, size_t len, int flags);
ssize_t self_sendto(int sockfd, const void *buf, size_t len, int flags,
                    const struct sockaddr *dest_addr, socklen_t addrlen);
int self_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
                struct timeval *timeout);
const char *self_inet_ntop(int af, const void *src, char *dst, socklen_t size);
int self_inet_pton(int af, const char *src, void *dst);
int self_socket(int domain, int type, int protocol);

typedef struct signal_socket {
  int fd;
  int domain;
  int type;
  int protocol;
  struct signal_socket *next;
} SIGNAL_SOCK_T;

typedef struct server_listen {
  int fd;
  int port;
  int backlog;
  struct server_listen *next;
} SER_LISTEN_T;

typedef struct socket_resource {
  int last_fd;
  pthread_mutex_t mutex;
  SIGNAL_SOCK_T *socket_list;
  SER_LISTEN_T *server_list;
} SOCK_RES_T;

static SOCK_RES_T g_socket_res;

#define MAX_FD (255)

void self_localhost_socket_init(void) {
  g_socket_res.last_fd = 0;
  g_socket_res.socket_list = NULL;
  g_socket_res.server_list = NULL;
  pthread_mutex_init(&g_socket_res.mutex, NULL);
}

bool is_in_socket_list(int fd) {
  SIGNAL_SOCK_T *sock = g_socket_res.socket_list;
  while (sock != NULL) {
    if (sock->fd == fd) {
      return TRUE;
    }

    sock = sock->next;
  }

  return FALSE;
}

bool is_in_server_list(int fd, int port) {
  SER_LISTEN_T *server_list = g_socket_res.server_list;
  while (server_list != NULL) {
    if (server_list->fd == fd || server_list->port == port) {
      return TRUE;
    }

    server_list = server_list->next;
  }

  return FALSE;
}

void add_into_socket_list(SIGNAL_SOCK_T *socket) {
  SIGNAL_SOCK_T *sock = g_socket_res.socket_list;

  if (sock == NULL) {
    g_socket_res.socket_list = socket;
    return;
  }

  while (sock != NULL) {
    if (sock->next == NULL) {
      sock->next = socket;
      return;
    }
    sock = sock->next;
  }
}

void add_into_server_list(SER_LISTEN_T *server) {
  SER_LISTEN_T *srv = g_socket_res.server_list;

  if (srv == NULL) {
    g_socket_res.server_list = server;
    return;
  }

  while (srv != NULL) {
    if (srv->next == NULL) {
      srv->next = server;
      return;
    }
    srv = srv->next;
  }
}

SER_LISTEN_T *get_server_by_fd(int fd) {
  SER_LISTEN_T *srv = g_socket_res.server_list;

  while (srv != NULL) {
    if (srv->fd == fd) {
      return srv;
    }
    srv = srv->next;
  }

  return NULL;
}

SIGNAL_SOCK_T *get_a_new_fd(void) {
  int count = 0;
  int avild_fd = 0;

  pthread_mutex_lock(&g_socket_res.mutex);
  avild_fd = g_socket_res.last_fd;

  while (1) {
    if (count > MAX_FD) {
      pthread_mutex_unlock(&g_socket_res.mutex);
      return NULL;
    }

    if (is_in_socket_list(avild_fd) == FALSE) {
      break;
    }

    avild_fd = (avild_fd + 1) % MAX_FD;

    count++;
  }

  SIGNAL_SOCK_T *new_socket = (SIGNAL_SOCK_T *)malloc(sizeof(SIGNAL_SOCK_T));
  if (new_socket == NULL) {
    printf("malloc failed\n");
    pthread_mutex_unlock(&g_socket_res.mutex);
    return NULL;
  }

  memset(new_socket, 0, sizeof(SIGNAL_SOCK_T));
  new_socket->fd = avild_fd;
  new_socket->next = NULL;
  add_into_socket_list(new_socket);

  g_socket_res.last_fd = (avild_fd + 1) % MAX_FD;
  pthread_mutex_unlock(&g_socket_res.mutex);
  return new_socket;
}

SIGNAL_SOCK_T *get_socket_by_fd(int fd) {
  SIGNAL_SOCK_T *sock = g_socket_res.socket_list;

  if (sock == NULL) {
    return NULL;
  }

  while (sock != NULL) {
    if (sock->fd == fd) {
      return sock;
    }
    sock = sock->next;
  }

  return NULL;
}

void delete_and_free_socket_by_fd(int fd) {
  SIGNAL_SOCK_T *sock = g_socket_res.socket_list;

  if (sock == NULL) {
    return;
  }

  while (sock != NULL) {
    if (sock->fd == fd) {
      SIGNAL_SOCK_T *tmp = sock;
      sock = sock->next;
      free(tmp);
      break;
    }
    sock = sock->next;
  }
}

void delete_socket_by_fd(int fd) {
  SIGNAL_SOCK_T *sock = g_socket_res.socket_list;

  if (sock == NULL) {
    return;
  }

  while (sock != NULL) {
    if (sock->fd == fd) {
      sock = sock->next;
      break;
    }
    sock = sock->next;
  }
}

int self_socket(int domain, int type, int protocol) {
  if (domain != AF_INET) {
    printf("unsupport domain\n");
    return -1;
  }

  if (type != SOCK_STREAM) {
    printf("unsupport type\n");
    return -1;
  }

  if (protocol != 0) {
    printf("unsupport protocol\n");
    return -1;
  }

  SIGNAL_SOCK_T *new_socket = get_a_new_fd();
  if (new_socket == NULL) {
    printf("get_a_new_fd failed\n");
    return -1;
  }

  new_socket->domain = domain;
  new_socket->type = type;
  new_socket->protocol = protocol;

  return new_socket->fd;
}

int self_closesocket(int sockfd) {
  pthread_mutex_lock(&g_socket_res.mutex);
  delete_and_free_socket_by_fd(sockfd);
  pthread_mutex_unlock(&g_socket_res.mutex);
}

int self_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  struct sockaddr_in *addr_in = (struct sockaddr_in *)addr;

  if (addr_in->sin_family != AF_INET) {
    printf("unsupport sin_family\n");
    return RET_ERR;
  }

  if (addr_in->sin_addr.s_addr != INADDR_ANY &&
      addr_in->sin_addr.s_addr != INADDR_LOOPBACK) {
    printf("unsupport addr\n");
    return RET_ERR;
  }

  pthread_mutex_lock(&g_socket_res.mutex);
  if (get_socket_by_fd(sockfd) == NULL) {
    pthread_mutex_unlock(&g_socket_res.mutex);
    printf("invalid sockfd");
    return RET_ERR;
  }

  if (is_in_server_list(sockfd, addr_in->sin_port) == TRUE) {
    pthread_mutex_unlock(&g_socket_res.mutex);
    printf("sockfd or port invaild\n");
    return RET_ERR;
  }

  SER_LISTEN_T *new_server = (SER_LISTEN_T *)malloc(sizeof(SER_LISTEN_T));
  if (new_server == NULL) {
    pthread_mutex_unlock(&g_socket_res.mutex);
    printf("malloc failed\n");
    return RET_ERR;
  }
  memset(new_server, 0, sizeof(SER_LISTEN_T));
  new_server->fd = sockfd;
  new_server->port = addr_in->sin_port;
  new_server->backlog = 1;
  new_server->next = NULL;

  add_into_server_list(new_server);

  pthread_mutex_unlock(&g_socket_res.mutex);
}

int self_listen(int sockfd, int backlog) {
  if (get_socket_by_fd(sockfd) == NULL) {
    printf("invalid sockfd\n");
    return RET_ERR;
  }

  if (backlog <= 0 || backlog > MAX_BACKLOG) {
    printf("backlog out of range\n");
    return RET_ERR;
  }

  pthread_mutex_lock(&g_socket_res.mutex);

  SER_LISTEN_T *ser = get_server_by_fd(sockfd);
  if (ser == NULL) {
    pthread_mutex_unlock(&g_socket_res.mutex);
    printf("invalid sockfd\n");
    return RET_ERR;
  }

  ser->backlog = backlog;

  pthread_mutex_unlock(&g_socket_res.mutex);

  return RET_OK;
}

int self_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  if (get_socket_by_fd(sockfd) == NULL) {
    printf("invalid sockfd\n");
    return RET_ERR;
  } 
}

// 线程函数的原型
void *client_thread(void *arg) {
  struct sockaddr_in serv_addr;

  int sockfd = self_socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("self_socket failed\n");
    return NULL;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(HTTP_PORT);

  printf("Client Getsockfd %d\n", sockfd);

  self_closesocket(sockfd);

  return NULL;
}

void *server_thread(void *arg) {
  struct sockaddr_in address;

  int sockfd = self_socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("self_socket failed\n");
    return NULL;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(HTTP_PORT);

  // 绑定socket到端口
  if (self_bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    printf("bind failed\n");
    return NULL;
  }

  // 绑定socket到端口
  if (self_listen(sockfd, 1) < 0) {
    printf("listen failed\n");
    return NULL;
  }

  printf("Server Getsockfd %d\n", sockfd);
  self_closesocket(sockfd);
  return NULL;
}

int main(void) {
  pthread_t client_thread_id;
  pthread_t server_thread_id;
  int ret;

  // 创建新线程
  ret = pthread_create(&client_thread_id, NULL, client_thread, NULL);
  if (ret != 0) {
    perror("pthread_create");
    exit(EXIT_FAILURE);
  }

  // 创建新线程
  ret = pthread_create(&server_thread_id, NULL, server_thread, NULL);
  if (ret != 0) {
    perror("pthread_create");
    exit(EXIT_FAILURE);
  }

  // 等待线程完成
  ret = pthread_join(client_thread_id, NULL);
  if (ret != 0) {
    perror("pthread_join");
    exit(EXIT_FAILURE);
  }

  // 等待线程完成
  ret = pthread_join(server_thread_id, NULL);
  if (ret != 0) {
    perror("pthread_join");
    exit(EXIT_FAILURE);
  }

  printf("Thread finished execution.\n");
  return 0;
}