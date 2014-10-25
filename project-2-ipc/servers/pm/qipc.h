/*
 * qipc.h
 *
 *  Created on: 24-Oct-2014
 *      Author: matrix
 */

#ifndef QIPC_H_
#define QIPC_H_

#define QIPC_MAX_MSG_LEN 16

typedef struct qipc_message {
	int no;         // message number in message queue
	char* data;	//message payload
	endpoint_t senderId;	//sender of the message
	endpoint_t *recieverIds;	//receivers intended by this message
	int priority;	//priority of the message
	int dataLen;	//priority of the message
	time_t expiryts;	//message expiry timestamp
	time_t rests;	//message received timestamp
	int recieverCount;	// how many processes are yet to consume the message
} qmsg;

typedef struct QueueNode {
	struct qmsg *msg;
	struct QueueNode *prev;
	struct QueueNode *next;
} Qnode;

EXTERN char* qipc_msg[2];
time_t clock_time();
qmsg * get_qipc_msg();
int cap_msg_len();

#endif /* QIPC_H_ */
