///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
   // A Completer...
	Chunk_iterator iteratorCopy(c);
	auto data = iteratorCopy->get();
	size_t size = outFile.getChunkSize();
	for (int i = 0 ; i < size / 2 ; i++) 
		std::swap(data[i],data[size-i-1]);

	outFile.addChunk(iteratorCopy); //Ajouter le chunk a outFile 
}