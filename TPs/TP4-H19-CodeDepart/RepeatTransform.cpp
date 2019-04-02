///////////////////////////////////////////////////////////
//  RepeatTransform.cpp
//  Implementation of the Class RepeatTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "RepeatTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

void RepeatTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
    // A completer : Ajouter le chunk de C a outFile a m_nRepetitions fois 
	for (size_t i = 0; i < m_nRepetitions; i++)
		outFile.addChunk(c);
}

size_t RepeatTransform::getNRepetitions(void)
{
	return m_nRepetitions;
}

