
//头文件
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <gcrypt.h>
#include <pcap.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <assert.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

const uint8_t BroadcastAddr[6] = {0xff,0xff,0xff,0xff,0xff,0xff}; // 广播MAC地址
const uint8_t MultcastAddr[6]  = {0x01,0x80,0xc2,0x00,0x00,0x03}; // 多播MAC地址
const char H3C_VERSION[16]="EN V2.40-0335"; // 华为客户端版本号
const char H3C_KEY[]      ="HuaWei3COM1X";  // H3C的固定密钥

static uint8_t DstMAC[6];//目标MAC


//自定义报文结构
typedef enum {REQUEST=1, RESPONSE=2, SUCCESS=3, FAILURE=4, H3CDATA=10} EAP_Code;
typedef enum {IDENTITY=1, NOTIFICATION=2, MD5=4, AVAILABLE=20} EAP_Type;
typedef uint8_t EAP_ID;


//主函数声明
int Authentication(char *UserName,char *Password,char *DeviceName);

// 子函数声明
static void SendStartPkt(pcap_t *adhandle, const uint8_t mac[]);
 void SendLogoffPkt(char *DeviceName);
static void SendResponseIdentity(pcap_t *adhandle,
                                 const uint8_t request[],
                                 const uint8_t ethhdr[],
                                 const uint8_t ip[4],
                                 const char    username[]);
static void SendResponseMD5(pcap_t *adhandle,
                            const uint8_t request[],
                            const uint8_t ethhdr[],
                            const char username[],
                            const char passwd[]);
static void GetMacFromDevice(uint8_t mac[6], const char *devicename);

static void FillClientVersionArea(uint8_t area[]);

void FillMD5Area(uint8_t digest[],
                 uint8_t id, const char passwd[], const uint8_t srcMD5[]);

void GetIpFromDevice(uint8_t ip[4], const char DeviceName[]);

int GetNetState(char *devicename);


