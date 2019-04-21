/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);
	
	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
	  ringBuffer->tab = dataBuffer;
	  ringBuffer->dataBufferSize = dataBufferSize;
	  ringBuffer->first = dataBuffer;
	  ringBuffer->last = dataBuffer;
	  ringBuffer->length = 0;
	  return true;
	}
	
	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
      ringBuffer->first	=	ringBuffer->tab;
	  ringBuffer->last	=	ringBuffer->tab;
	  ringBuffer->length=	0;
	  return true;
	    
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);	
	if((ringBuffer->first == ringBuffer->last) && (ringBuffer->length == 0))
	{
	    return true;
	}
	
	return false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) 
	{
		return (ringBuffer->length);
	}
	return 0;
	
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->dataBufferSize;
	}
	return 0;	
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		if ((ringBuffer->first == ringBuffer->last) && (ringBuffer->length != 0))
		{
		    return false;
		}
		*ringBuffer->last =	c;
		if(ringBuffer->last == ringBuffer->tab + ringBuffer->dataBufferSize-1)
		{
		    ringBuffer->last = ringBuffer->tab;
		}
		else
		{
		ringBuffer->last++;
		}
		ringBuffer->length++;
		return true;
		
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);
	
  if ((ringBuffer) && (c)) {
        if((ringBuffer->first == ringBuffer->last) && (ringBuffer->length == 0))
	{
	    return false;
	}
	*c = *ringBuffer->first;
	if(ringBuffer->first == ringBuffer->tab + ringBuffer->dataBufferSize-1)
		{
		ringBuffer->first = ringBuffer->tab;
		}
	else
		{
		ringBuffer->first++;
		}
		ringBuffer->length--;
		return true;
	}
	
	return false;
}