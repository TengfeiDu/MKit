/*
 * Copyright © 2001-2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _MODBUS_H_
#define _MODBUS_H_

/* Add this for macros that defined unix flavor */
#if (defined(__unix__) || defined(unix)) && !defined(USG)
#include <sys/param.h>
#endif

#ifndef _MSC_VER
#include <stdint.h>
#include <sys/time.h>
#else
#include "stdint.h"
#include <time.h>
#endif

#include "modbus-version.h"

#ifdef  __cplusplus
# define MODBUS_BEGIN_DECLS  extern "C" {
# define MODBUS_END_DECLS    }
#else
# define MODBUS_BEGIN_DECLS
# define MODBUS_END_DECLS
#endif

MODBUS_BEGIN_DECLS

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef OFF
#define OFF 0
#endif

#ifndef ON
#define ON 1
#endif

#define MODBUS_BROADCAST_ADDRESS    0

/* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 1 page 12)
 * Quantity of Coils to read (2 bytes): 1 to 2000 (0x7D0)
 * (chapter 6 section 11 page 29)
 * Quantity of Coils to write (2 bytes): 1 to 1968 (0x7B0)
 */
#define MODBUS_MAX_READ_BITS              2000
#define MODBUS_MAX_WRITE_BITS             1968

/* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 3 page 15)
 * Quantity of Registers to read (2 bytes): 1 to 125 (0x7D)
 * (chapter 6 section 12 page 31)
 * Quantity of Registers to write (2 bytes) 1 to 123 (0x7B)
 * (chapter 6 section 17 page 38)
 * Quantity of Registers to write in R/W registers (2 bytes) 1 to 121 (0x79)
 */
#define MODBUS_MAX_READ_REGISTERS          125
#define MODBUS_MAX_WRITE_REGISTERS         123
#define MODBUS_MAX_RW_WRITE_REGISTERS      121

/* Random number to avoid errno conflicts */
#define MODBUS_ENOBASE 112345678

/* Protocol exceptions */
enum {
    MODBUS_EXCEPTION_ILLEGAL_FUNCTION = 0x01,
    MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS,
    MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE,
    MODBUS_EXCEPTION_SLAVE_OR_SERVER_FAILURE,
    MODBUS_EXCEPTION_ACKNOWLEDGE,
    MODBUS_EXCEPTION_SLAVE_OR_SERVER_BUSY,
    MODBUS_EXCEPTION_NEGATIVE_ACKNOWLEDGE,
    MODBUS_EXCEPTION_MEMORY_PARITY,
    MODBUS_EXCEPTION_NOT_DEFINED,
    MODBUS_EXCEPTION_GATEWAY_PATH,
    MODBUS_EXCEPTION_GATEWAY_TARGET,
    MODBUS_EXCEPTION_MAX
};

#define EMBXILFUN  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_FUNCTION)
#define EMBXILADD  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS)
#define EMBXILVAL  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE)
#define EMBXSFAIL  (MODBUS_ENOBASE + MODBUS_EXCEPTION_SLAVE_OR_SERVER_FAILURE)
#define EMBXACK    (MODBUS_ENOBASE + MODBUS_EXCEPTION_ACKNOWLEDGE)
#define EMBXSBUSY  (MODBUS_ENOBASE + MODBUS_EXCEPTION_SLAVE_OR_SERVER_BUSY)
#define EMBXNACK   (MODBUS_ENOBASE + MODBUS_EXCEPTION_NEGATIVE_ACKNOWLEDGE)
#define EMBXMEMPAR (MODBUS_ENOBASE + MODBUS_EXCEPTION_MEMORY_PARITY)
#define EMBXGPATH  (MODBUS_ENOBASE + MODBUS_EXCEPTION_GATEWAY_PATH)
#define EMBXGTAR   (MODBUS_ENOBASE + MODBUS_EXCEPTION_GATEWAY_TARGET)

/* Native libmodbus error codes */
#define EMBBADCRC  (EMBXGTAR + 1)
#define EMBBADDATA (EMBXGTAR + 2)
#define EMBBADEXC  (EMBXGTAR + 3)
#define EMBUNKEXC  (EMBXGTAR + 4)
#define EMBMDATA   (EMBXGTAR + 5)

extern const unsigned int libmodbus_version_major;
extern const unsigned int libmodbus_version_minor;
extern const unsigned int libmodbus_version_micro;

typedef struct _modbus modbus_t;

typedef struct {
    int nb_bits;
    int nb_input_bits;
    int nb_input_registers;
    int nb_registers;
    uint8_t *tab_bits;
    uint8_t *tab_input_bits;
    uint16_t *tab_input_registers;
    uint16_t *tab_registers;
} modbus_mapping_t;

typedef enum
{
    MODBUS_ERROR_RECOVERY_NONE          = 0,
    MODBUS_ERROR_RECOVERY_LINK          = (1<<1),
    MODBUS_ERROR_RECOVERY_PROTOCOL      = (1<<2),
} modbus_error_recovery_mode;

int modbus_set_slave(modbus_t* ctx, int slave);
int modbus_set_error_recovery(modbus_t *ctx, modbus_error_recovery_mode error_recovery);
void modbus_set_socket(modbus_t *ctx, int socket);
int modbus_get_socket(modbus_t *ctx);

void modbus_get_response_timeout(modbus_t *ctx, struct timeval *timeout);
void modbus_set_response_timeout(modbus_t *ctx, const struct timeval *timeout);

void modbus_get_byte_timeout(modbus_t *ctx, struct timeval *timeout);
void modbus_set_byte_timeout(modbus_t *ctx, const struct timeval *timeout);

int modbus_get_header_length(modbus_t *ctx);

int modbus_connect(modbus_t *ctx);
void modbus_close(modbus_t *ctx);

void modbus_free(modbus_t *ctx);

int modbus_flush(modbus_t *ctx);
void modbus_set_debug(modbus_t *ctx, int boolean);

const char *modbus_strerror(int errnum);

int modbus_read_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest);
int modbus_read_input_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest);
int modbus_read_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest);
int modbus_read_input_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest);
int modbus_write_bit(modbus_t *ctx, int coil_addr, int status);
int modbus_write_register(modbus_t *ctx, int reg_addr, int value);
int modbus_write_bits(modbus_t *ctx, int addr, int nb, const uint8_t *data);
int modbus_write_registers(modbus_t *ctx, int addr, int nb, const uint16_t *data);
int modbus_write_and_read_registers(modbus_t *ctx, int write_addr, int write_nb,
                                    const uint16_t *src, int read_addr, int read_nb,
                                    uint16_t *dest);
int modbus_report_slave_id(modbus_t *ctx, uint8_t *dest);

modbus_mapping_t* modbus_mapping_new(int nb_coil_status, int nb_input_status,
                                     int nb_holding_registers, int nb_input_registers);
void modbus_mapping_free(modbus_mapping_t *mb_mapping);

int modbus_send_raw_request(modbus_t *ctx, uint8_t *raw_req, int raw_req_length);

int modbus_receive(modbus_t *ctx, uint8_t *req);
int modbus_receive_from(modbus_t *ctx, int sockfd, uint8_t *req);

int modbus_receive_confirmation(modbus_t *ctx, uint8_t *rsp);

int modbus_reply(modbus_t *ctx, const uint8_t *req,
                 int req_length, modbus_mapping_t *mb_mapping);
int modbus_reply_exception(modbus_t *ctx, const uint8_t *req,
                           unsigned int exception_code);

/**
 * UTILS FUNCTIONS
 **/

#define MODBUS_GET_HIGH_BYTE(data) (((data) >> 8) & 0xFF)
#define MODBUS_GET_LOW_BYTE(data) ((data) & 0xFF)
#define MODBUS_GET_INT32_FROM_INT16(tab_int16, index) ((tab_int16[(index)] << 16) + tab_int16[(index) + 1])
#define MODBUS_GET_INT16_FROM_INT8(tab_int8, index) ((tab_int8[(index)] << 8) + tab_int8[(index) + 1])
#define MODBUS_SET_INT16_TO_INT8(tab_int8, index, value) \
    do { \
        tab_int8[(index)] = (value) >> 8;  \
        tab_int8[(index) + 1] = (value) & 0xFF; \
    } while (0)

void modbus_set_bits_from_byte(uint8_t *dest, int index, const uint8_t value);
void modbus_set_bits_from_bytes(uint8_t *dest, int index, unsigned int nb_bits,
                                const uint8_t *tab_byte);
uint8_t modbus_get_byte_from_bits(const uint8_t *src, int index, unsigned int nb_bits);
float modbus_get_float(const uint16_t *src);
void modbus_set_float(float f, uint16_t *dest);

#include "modbus-tcp.h"
#include "modbus-rtu.h"

MODBUS_END_DECLS


/*
 *  MODBUS-ASCII:
 *                        ???     ???
 *    起始符 地址    功能码  数据个数 数据    LRC    结束符
 *    3A    30 31  30 33  30 31   32 31  0E 78  0D 0A
 *
 *    LRC = ~(3A    + 30 +  31 + 30 + 33 + 30 + 31  + 32 + 31) + 1
 *
 *  MODBUS-TCP：
 *
 *    请求：00 00 00 00 00 06 09 03 00 00 00 01
 *    00 00 为此次通信事务处理标识符，一般每次通信之后将被要求加1以区别不同的通信数据报文;
 *    00 00 表示协议标识符，00 00为modbus协议;
 *    00 06 为数据长度，用来指示接下来数据的长度，单位字节;
 *    09    为设备地址，用以标识连接在串行线或者网络上的远程服务端的地址。以上七个字节也被称为modbus报文头；
 *    03    为功能码，此时代码03为读取保持寄存器数据；
 *    00 00 为起始地址；
 *    00 01 为寄存器数量，（word数量）。
 *
 *    响应：00 00 00 00 00 05 09 03 02 12 34
 *    00 00 为此次通信事务处理标识符，应答报文要求与先前对应的请求保持一致;
 *    00 00 为协议标识符，与先前对应的请求保持一致;
 *    00 05 为数据长度，用来指示接下来数据的长度，单位字节;
 *    09    为设备地址，应答报文要求与先前对应的请求保持一致；
 *    03    为功能码，正常情况下应答报文要求与先前对应的请求保持一致，如果出错则返回80h+先前的功能码；
 *    02    指示接下来数据的字节长度;
 *    12 34 为被读取的保持寄存器中的数据值，即要求被读取的地址为00 00的保持寄存器中的数值为1234h。
 *
 * */
/*
 * Below read operation is equal:
 *  ASCII:
 *   3A 3131 3033 3030 3642 3030 3033 3745 0D 0A
 *  RTU:
 *   11 03 00 6B 00 03 76 87
 *
 * MODBUS-RTU:
 *
 *  read:
 *  TX: 01       03    0000   0002          xxxx
 *      device   read  offset numberOfRead  checksum(lower byte from beginning)
 *  RX: 01       03  04                 0000              0000               xxxx
 *                   numberOfReaded     first unit data   second unit data
 *
 *  write:
 *  TX: 01      10     0000     0003           06               0000         0000    0000   xxxx
 *              write  offset   numberOfWrite  numberOfByte     first data   second  third
 *  RX: 01      10  0000   0003     xxxx
 *
 *  checksum:from beginning to end
 *
 */

/*********************************************************************
 *                              demo
 * *******************************************************************/
#if 0

modbus_t *mb;
uint16_t tab_reg[32];

mb = modbus_new_tcp("127.0.0.1", 1502);
MDG<<modbus_connect(mb);

/* Read 5 registers from the address 0 */
MDG<<modbus_read_registers(mb, 0, 5, tab_reg);

modbus_close(mb);
modbus_free(mb);
//////////////////////////////////////////////////////////////////////
uint16_t rec[64]={0};

//1-open port
mb = modbus_new_rtu("com1",19200,'N',8,1);
if(!mb){
    MDG<<"ERR...";
    qApp->exit(1);
}

//2-set device id
modbus_set_slave(mb,1);

//3-connect
modbus_connect(mb);

//4-respond delay
timeval t;

//
t.tv_sec = 0;
//
t.tv_usec = 50000;//1000ms
modbus_set_response_timeout(mb,&t);
/*
 *     uint16_t iData[10] = {0xAA,0xBB,0xCC,0xDD,0xEE,0xFFFF,6,7,8,9};
int iRet = modbus_write_registers(mb,0,10,iData);
*/

int ret=modbus_read_registers(mb, 0, 2, rec);

QStringList list_ret;
for(int i = 0; i < M_SIZE_ARRAY_ELEMENTS(rec); i++){
    list_ret<<M_GET_OBJECT_MTOOLS->mUint2HexStr(rec[i]);
}
MDG<<ret<<list_ret;

//7-
modbus_close(mb);

//8-
modbus_free(mb);

#endif
/*********************************************************************
 *                              demo
 * *******************************************************************/


#endif  /* _MODBUS_H_ */
