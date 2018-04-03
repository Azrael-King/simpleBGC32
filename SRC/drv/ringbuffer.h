/*
 *  ringbuffer.h
 *
 *  Created on: Aug 1, 2013
 *      Author: ala42
 */

///////////////////////////////////////////////////////////////////////////////

#pragma once

///////////////////////////////////////////////////////////////////////////////

typedef struct
{
	volatile int Read, Write, Overrun;
	unsigned char Buffer[1024];
	void (*CallBack)(void);

} tRingBuffer;

///////////////////////////////////////////////////////////////////////////////

void RingBufferInit(tRingBuffer *rb, void (*callback)(void));

///////////////////////////////////////////////////////////////////////////////

int RingBufferSize(tRingBuffer *rb);

///////////////////////////////////////////////////////////////////////////////

int RingBufferFillLevel(tRingBuffer *rb);

///////////////////////////////////////////////////////////////////////////////

void RingBufferPut(tRingBuffer *rb, unsigned char c, int block);

///////////////////////////////////////////////////////////////////////////////

void RingBufferPutBlock(tRingBuffer *rb, unsigned char *data, int dataLen, int block);

///////////////////////////////////////////////////////////////////////////////

int RingBufferGet(tRingBuffer *rb);

///////////////////////////////////////////////////////////////////////////////

int RingBufferPeek(tRingBuffer *rb);

///////////////////////////////////////////////////////////////////////////////
