///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
   // A Completer: Ajouter les enfants de mdd. 
	for (auto iterator = mdd.begin(); iterator != mdd.end(); iterator++)
		addChild(*iterator);
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
    // A Completer: faire une copie de l'objet courant (this) et le retourner 
	return new CompositeTransform(*this);
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	// A Completer...
	for (int iterator = 0; iterator < m_transforms.size(); iterator++) 
		m_transforms[iterator].get()->transform(c, outFile);
}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	// A Completer: faire un pushback dans la memoire : 
	m_transforms.push_back((TransformPtr)t.clone());
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	// A Completer: Avec la fonction erase.
	m_transforms.erase(transfIt);
}
