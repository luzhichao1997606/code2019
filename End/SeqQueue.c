#include "variable.h"

void QueueInit(SeqQueue *Queue)
{ //队列初始化
  Queue->head = 0;
  Queue->end = 0;
  Queue->count = 0;
  Queue->finish_Flag = 1;
}

UINT8 QueueNotEmpty(SeqQueue Queue)
{ //队列是否为空
  if (Queue.count != 0)
  { //队列非空
    return 1;
  }
  else
  { //队列空
    return 0;
  }
}

UINT8 QueueAdd(SeqQueue *Queue, UINT8 x)
{ //进队列
  if ((Queue->count > 0) && (Queue->head == Queue->end))
  { //队列已满
    return 0;
  }
  else
  {
    Queue->buf[Queue->end] = x;
    Queue->end = (Queue->end + 1) % MAXQUEUESIZE;
    Queue->count ++;

    return 1;
  }
}

UINT8 QueueDelete(SeqQueue *Queue, UINT8 *d)
{ //出队列
  if (Queue->count == 0)
  { //队列已空
    return 0;
  }
  else
  {
    *d = Queue->buf[Queue->head];
    Queue->head  = (Queue->head + 1) % MAXQUEUESIZE;
    Queue->count --;

    return 1;
  }
}

UINT8 QueueHeadGet(SeqQueue Queue, UINT8 *d)
{ //读取队列头
  if (Queue.count == 0)
  { //队列空
    return 0;
  }
  else
  {
    *d = Queue.buf[Queue.head];

    return 1;
  }
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
