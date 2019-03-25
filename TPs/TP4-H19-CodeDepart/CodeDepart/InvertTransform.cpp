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
	Chunk_iterator IteratorTemporary(c);
	int i = 0;
	int k = c->size(); - 1;
	for (; i < c->size(); i++, k--) // i et k 2 compteurs inversement incrementés 
		IteratorTemporary->get()[i] = c->get()[k];

	outFile.addChunk(IteratorTemporary); //Ajouter le chunk a outFile 
}
