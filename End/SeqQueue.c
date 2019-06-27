#include "variable.h"

void QueueInit(SeqQueue *Queue)
{ //���г�ʼ��
  Queue->head = 0;
  Queue->end = 0;
  Queue->count = 0;
  Queue->finish_Flag = 1;
}

UINT8 QueueNotEmpty(SeqQueue Queue)
{ //�����Ƿ�Ϊ��
  if (Queue.count != 0)
  { //���зǿ�
    return 1;
  }
  else
  { //���п�
    return 0;
  }
}

UINT8 QueueAdd(SeqQueue *Queue, UINT8 x)
{ //������
  if ((Queue->count > 0) && (Queue->head == Queue->end))
  { //��������
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
{ //������
  if (Queue->count == 0)
  { //�����ѿ�
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
{ //��ȡ����ͷ
  if (Queue.count == 0)
  { //���п�
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
